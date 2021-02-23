#!/usr/bin/python3
# rewriteTable.py - rewrite SYCL LaTeX tables as asciidoctor.
#
# Usage: rewritePname.py < file > file

import argparse
import copy
import sys
import re
import string
import pdb

global curLine

# Non-standard table column separator, which must be a character that
# doesn't appear in any table content. The default '|' shows up in imbedded
# C++ source and can't be used.
global tableSep
tableSep = '@'

# Match \startTable
def startRegularTable(line):
    match = re.match(r'\\startTable\{',line)
    return match is not None

# Match start of a table
def startTable(line):
    match = re.match(r'\\start(|Info)Table\{',line)
    return match is not None

# Match end of a table
def endTable(line):
    match = re.match(r'\\complete(|Info)Table',line)
    return match is not None

# Match \addInfoRow
def startInfoRow(line):
    match = re.match(r'\\addInfoRow',line)
    return match is not None

# Match \addRow*
def startRegularRow(line):
    match = re.match(r'\\addRow(|Two|Three|Four|Five|Six|Seven)(|L|SL)',line)
    return match is not None

# Match a row command
def startRow(line):
    if startInfoRow(line):
        return True
    elif startRegularRow(line):
        return True
    else:
        return False

# Map string numeric names in a \addRow<name> macro to numbers
colDict = {
    ''       : 1,
    'Two'    : 2,
    'Three'  : 3,
    'Four'   : 4,
    'Five'   : 5,
    'Six'    : 6,
    'Seven'  : 7,
    'Eight'  : 8,
}

# Parse a row macro
# Returns (isInfoRow, firstColArgs, firstIndent)
#   isInfoRow -> True if \addInfoRow macro (3 column table)
#   firstColArgs -> number of following arguments merged into first column
#   firstIndent -> which first column argument starts indentation
# Thus:
#   \addInfoRow      -> (True, 1, 1000)   (never indent)
#   \addRow          -> (False, 1, 1000)  (never indent)
#   \addRow(nargs)L  -> (False, nargs, 2) (indent 2nd & later)
#   \addRow(nargs)SL -> (False, nargs, 3) (indent 3rd & later)
def parseRowFormat(format):
    if format.startswith('\\addInfoRow'):
        return (True, 0, 1000)
    elif format.startswith('\\addRow'):
        format = format[len('\\addRow'):]

        if format.endswith('SL'):
            firstIndent = 3
            format = format[0:-2]
        elif format.endswith('L'):
            firstIndent = 2
            format = format[0:-1]
        else:
            # Just an \addRow macro, never indent
            firstIndent = 1000

        # Remainder must match a text number
        if format in colDict:
            firstColArgs = colDict[format]
        else:
            print('ERROR: row format macro has unrecognized number of columns:',
                  format, file=sys.stderr)
            sys.exit(1)

        return (False, firstColArgs, firstIndent)
    else:
        print('ERROR: row format macro "' + format + '" unrecognized',
              file=sys.stderr)
        sys.exit(1)

# Parse arguments following a row macro
# Passed a single string 'text' (may span multiple lines) containing {}
# bracketed arguments, which may themselves contain nested brackets.
# Returns a list of debracketed strings with leading and trailing whitespace
# stripped from each.
def parseBrackets(text):
    # Uses yet another simple state machine tracking bracket depth
    args = []
    bracketDepth = 0
    pos = 0

    for c in text:
        if bracketDepth == 0:
            if c == '{':
                # Begin accumulating an argument inside {}
                curArg = ''
                bracketDepth = 1
            elif c not in string.whitespace:
                print('ERROR: disallowed character "' + c + '"outside brackets in:',
                      text, file=sys.stderr)
                sys.exit(1)
        else:
            if c == '{':
                # Handle nested brackets
                bracketDepth += 1
                curArg += c
            elif c == '}':
                bracketDepth -= 1
                if bracketDepth > 0:
                    curArg += c
                else:
                    # End this argument
                    args.append(curArg.strip())
            else:
                curArg += c

        # Increment string position
        pos += 1

    # At end, if we're not at bracket depth 0, something bad happened
    if bracketDepth > 0:
        print('ERROR: inside brackets at depth', bracketDepth,
              'at end of args:', text, file=sys.stderr)
        sys.exit(1)

    return args

# Format multiline description, indenting by 'prefix' on second line
# and beyond (except after the first paragraph).
def formatDescription(txt, prefix):
    firstLine = True
    indent = True
    result = ''

    for line in txt.split('\n'):
        if line == '' or line == '--' or line.startswith('[source'):
            indent = False

        if indent and not firstLine:
            result += prefix + line.strip() + '\n'
        else:
            result += line.rstrip() + '\n'
        firstLine = False

    return result

# Process table content
# (just print it, for now)
def processTable(head, body, tail, file):
    global curLine, tableSep

    # Accumulate list of rows
    # This is another simple state machine
    tableRows = []
    curRowFormat = ''
    curRow = ''
    inRow = False

    for line in body:
        # Skip blank lines
        if line.strip() == '' and not inRow:
            continue

        if startRow(line):
            # Begin a row with an \add*Row* macro
            # Flush previous row, if present

            if curRow != '':
                tableRows.append([curRowFormat, curRow])

            curRowFormat = line
            curRow = ''
            inRow = True
        else:
            # Just accumulate the line
            if not inRow:
                print('ERROR following line', curLine,
                      ': line not in row macro:', line, file=sys.stderr)
                sys.exit(1)
            curRow += line

    # Flush final row, if present
    if curRow != '':
        tableRows.append([curRowFormat, curRow])

    # Just print the table out unchanged
    # print(head, end='', file=file)
    # for (rowFormat, row) in tableRows:
    #     print(rowFormat, end='', file=file)
    #     print(row, end='', file=file)
    # print(tail, end='', file=file)

    start = head.find('{')
    end = head.rfind('}')
    macro = head[0:start]
    caption = head[start+1:end]

    # If the head is \startInfoTable, table is 3 columns and macros are 3
    # arguments. Otherwise table is 2 columns and macros are varying
    # arguments.
    if macro == r'\startTable':
        # Two column table
        infoTable = False

        # Don't print out the LaTeX table start macro
        # print('// {}'.format(macro), file=file)

        print('[width="100%",options="header",separator="{}",cols="65%,35%"]'.format(tableSep),
              file=file)
        print('|====', file=file)
        print('{0} {1} {0} {2}'.format(
                tableSep, caption, 'Description'),
                file=file)
    elif macro == r'\startInfoTable':
        # Three-column 'info' table
        infoTable = True

        # Don't print out the LaTeX table start macro
        # print('// {}'.format(macro), file=file)

        print('[width="100%",options="header",separator="{}",cols="37%,19%,44%"]'.format(tableSep),
              file=file)
        print('|====', file=file)
        print('{0} {1} {0} {2} {0} {3}'.format(
                tableSep, caption, 'Return type', 'Description'),
                file=file)
    else:
        print('ERROR: unrecognized table macro', macro, file=sys.stderr)
        sys.exit(1)

    for (rowFormat, row) in tableRows:
        format = rowFormat.strip()

        # Parse LaTeX row format macro
        (infoRow, firstColArgs, firstIndent) = parseRowFormat(format)

        args = parseBrackets(row)
        nargs = len(args)

        if infoRow:
            if nargs != 3:
                print('ERROR: InfoRow with wrong # of columns {}'.format(nargs),
                      file=sys.stderr)
                sys.exit(1)

            # Don't print out the LaTeX table row macro
            # print('// {}'.format(format), file=file)

            print('a{}\n'.format(tableSep) +
                  '[source,c++]\n' +
                  '----\n' +
                  args[0] + '\n' +
                  '----\n',
                  file=file)
            # Might need to be in a source block if not a simple term
            if args[1].find(' ') != -1:
                print('// WARNING: following argument contains spaces', file=file)
            print('    {} [.code]#{}#'.format(tableSep, args[1]),
                  file=file)
            print('   a{}'.format(tableSep),
                  formatDescription(args[2], 6 * ' '),
                  file=file)
        else:
            if nargs != firstColArgs + 1:
                print('ERROR: Row with wrong # of columns {} expected {}'.format(
                        nargs, firstColArgs + 1), file=file)
                sys.exit(1)

            # Don't print out the LaTeX table row macro
            # print('// {}'.format(format), file=file)

            # Print firstColArgs worth of the arguments in a source block
            # for the first column, indenting arguments firstIndent and
            # beyond.
            print('a{}\n'.format(tableSep) +
                  '[source,c++]\n' +
                  '----\n',
                  end='', file=file)
            for i in range(0, firstColArgs):
                if i < firstIndent - 1:
                    print(args[i], file=file)
                else:
                    print('    ' + args[i], file=file)
            print('----\n',
                  end='', file=file)

            # Print second column argument
            print('   a{}'.format(tableSep),
                  formatDescription(args[firstColArgs], 6 * ' '),
                  file=file)

        # Now the fancy brace-matching parsing to find each individual macro
        # argument, strip them, indent the properly, etc.
        # print('//# {} -> infoRow {} firstColArgs {} firstIndent {}'.format(
        #     format, infoRow, firstColArgs, firstIndent), file=file)
        # n = 1
        # for arg in args:
        #     print('//#@ arg{}: {}'.format(n, arg), file=file)
        #     n += 1

    # End the table
    print('|====', file=file)

if __name__ == '__main__':
    parser = argparse.ArgumentParser()

    parser.add_argument('-in', action='store', dest='inpath', default=None,
                        help='Set the input path')
    parser.add_argument('-out', action='store', dest='outpath', default=None,
                        help='Set the output path')

    results = parser.parse_args()

    if results.inpath is not None:
        ifp = open(results.inpath, 'r', encoding='utf-8')
    else:
        ifp = sys.stdin

    if results.outpath is not None:
        ofp = open(results.outpath, 'w', encoding='utf-8')
    else:
        ofp = sys.stdout

    global curLine
    curLine = 0

    # Simple state machine tracking whether outside a table (just emit the
    # line) or inside (accumulate), with an action at table end.

    inTable = False
    tableHead = ''
    tableBody = []

    for line in ifp:
        curLine = curLine + 1

        if startTable(line):
            if inTable:
                write('ERROR: table inside table at line', curLine, file=sys.stderr)
                sys.exit(1)
            inTable = True
            tableHead = line
            tableBody = []
        elif endTable(line):
            if not inTable:
                write('ERROR: end table when not inside table at line', curLine, file=sys.stderr)
                sys.exit(1)
            processTable(head=tableHead, body=tableBody, tail=line, file=ofp)
            inTable = False
            tableHead = ''
            tableBody = []
        elif inTable:
            # Accumulate this line
            tableBody.append(line)
        else:
            # Emit lines outside tables
            print(line, end='', file=ofp)
