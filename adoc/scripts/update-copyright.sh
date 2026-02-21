#! /bin/bash
# Copyright 2024-2026 The Khronos Group Inc.
#
# SPDX-License-Identifier: Apache-2.0

# Run this script at the beginning of the year to update the copyright dates
# on all the source files.  Run it from the root of the repo.  The script only
# updates copyright dates in the following forms:
#
# Copyright <begin-date>-<end-date> The Khronos Group
# Copyright (c) <begin-date>-<end-date> The Khronos Group
#
# And it only updates the <end-date> if the original value is the previous year
# (i.e. last year, assuming you run the script at the beginning of the year).
#
# We intentionally do not update copyright notices from other companies.
#
# The script also performs a check for Khronos copyright notices that do not
# follow either of the patterns above.  If any such notices are found, they are
# printed to stdout.  These lines should be examined and modified manually.

thisyear=`date +%Y`
lastyear=`expr $thisyear - 1`

function update_code() {
  file_name="$1"
  # Update the copyright dates and names
  sed -i \
    -e "s/Copyright\\( (c)\\)\\? \\([12][0-9][0-9][0-9]\\)-$lastyear The Khronos Group/Copyright\\1 \\2-$thisyear The Khronos Group/g" \
    "$file_name"
}

git ls-files | while read -r f ; do
  update_code "$f"

  # See if the file contains a Khronos copyright that was not updated.
  # We skip the file for this script because the sed expression above causes
  # a false report.
  if [ "$f" != "adoc/scripts/update-copyright.sh" ]; then
    grep -iH 'copyright.*khronos' "$f" | grep -v "[12][0-9][0-9][0-9]-$thisyear"
  fi
done
