# This only needs to be run if changing the .tikz files.
# Generated SVG are checked into the repository and need only be
# rebuilt if the TikZ markup changes.
# Building requires asciidoctor, asciidoctor-diagram, pdf2svg,
# and a LaTeX installation including pdflatex, tikz,
# and the 'arrows' tikzlibrary.

TIKZ = \
    fig:three-cg-one-queue.tikz \
    fig:three-cg-three-queue.tikz \
    fig:device_to_device1.tikz \
    fig:device_to_device2.tikz \
    fig:overlap.tikz \
    fig:host-acc.tikz

all: makesvg.html

# The actual Makefile target is irrelevant.
# The side effect of running it is generating SVG files to be checked in.
makesvg.html: makesvg.adoc
	asciidoctor --backend html5 --require asciidoctor-diagram \
	  --out-file makesvg.html makesvg.adoc
	-rm $@

clean:
	-rm -f makesvg.html *.svg
