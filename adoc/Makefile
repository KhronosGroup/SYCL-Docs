# Copyright 2011-2025 The Khronos Group, Inc.
#
# SPDX-License-Identifier: Apache-2.0

# SYCL Specification makefile

# If a recipe fails, delete its target file. Without this cleanup, the leftover
# file from the failed recipe can falsely satisfy dependencies on subsequent
# runs of `make`.
.DELETE_ON_ERROR:

# IMAGEOPTS is normally set to generate inline SVG images, but can be
# overridden to an empty string, since the inline option doesn't work
# well with our HTML diffs.
# This select opts as explained in "Taming SVGs" of
# https://asciidoctor.org/docs/user-manual/#taming-svgs
# Do not use inline because it breaks the text of the figures in the
# HTML output.
IMAGEOPTS =

# The default 'all' target builds the following sub-targets:
#  html - HTML single-page API specification
#  pdf - PDF single-page API specification

# Jon: don't build PDF yet - some weird errors (related to code: macro?)
all: html

#
QUIET    ?= @
PYTHON   ?= python3
ASCIIDOC ?= asciidoctor
# Using such variables allows running local version with:
# BUNDLE_GEMFILE=.../asciidoctor-pdf/Gemfile make QUIET= ASCIIDOCPDF="bundle exec asciidoctor-pdf" pdf
ASCIIDOCPDF ?= asciidoctor-pdf
RUBY      = ruby
NODEJS    = node
PATCH     = patch
RM        = rm -f
RMRF      = rm -rf
MKDIR     = mkdir -p
CP        = cp
ECHO      = echo

# Path to Python scripts used in generation
SCRIPTS  = scripts

# Compute the absolute directory name from the location of this Makefile
# so that we can compile from anywhere even if we use make -f
# <this_makefile>:
SYCL_DIR := $(abspath $(dir $(firstword $(MAKEFILE_LIST)))/..)

# Target directories for output files
# HTMLDIR - 'html' target
# PDFDIR - 'pdf' target
OUTDIR    = $(GENERATED)/out
HTMLDIR   = $(OUTDIR)/html
PDFDIR    = $(OUTDIR)/pdf

# PDF Equations are written to SVGs, this dictates the location to
# store those files (temporary)
PDFMATHDIR = $(OUTDIR)/equations_temp

# Set VERBOSE to -v to --verbose to see what asciidoc is doing.
VERBOSE = --verbose

# Some AsciiDoctor attributes (such as SYCL_LANGUAGE_VERSION, SYCL_NAME,
# SYCL_VERSION & SYCL_REVISION) are based on this external configuration file:
include $(SYCL_DIR)/sycl_version.txt

# Name the generated spec from the revision
SPEC_BASE_NAME=$(shell echo $(SYCLNAME)-$(SYCLVERSION) \
  | tr [:upper:] [:lower:])

# asciidoc build attributes to set (defaults are usually OK)
# NOTEOPTS sets options controlling which NOTEs are generated
# ATTRIBOPTS sets the API revision and enables KaTeX generation
# VERSIONATTRIBS sets attributes for enabled API versions
# EXTRAATTRIBS sets additional attributes, if passed to make
# ADOCMISCOPTS miscellaneous options controlling error behavior, etc.
# ADOCEXTS asciidoctor extensions to load
# ADOCOPTS options for asciidoc->HTML5 output

# Uncomment to get TODO notes
NOTEOPTS     = --attribute showtodos

# Spell out ISO 8601 format as not all date commands support --rfc-3339
SPECDATE     = $(shell echo `date -u "+%Y-%m-%d %TZ"`)

# Deterine the commit ID that is printed at the top of the spec.
# In some CI systems, the build may happen outside of a git repo, so
# "git log" may not be available.  These CI systems set the commit id via
# "make COMMIT_SHA=...", so the build process doesn't need the "git log"
# command.
SPECREMARK = commit $(COMMIT_SHA)
COMMIT_SHA = $(shell echo `git log -1 --format="%H" 2> /dev/null \
               || echo "(not available)"`)

# Some of the attributes used in building all spec documents:
#   chapters - absolute path to chapter sources
#   appendices - absolute path to appendix sources
#   images - absolute path to images
#   code_dir - absolute path of the directory with code samples
#   header_dir - absolute path of the directory with header samples
#   generated - absolute path to generated sources
#   refprefix - controls which generated extension metafiles are
#   included at build time. Must be empty for specification,
#   'refprefix.' for refpages (see ADOCREFOPTS below).
ATTRIBOPTS   = --attribute revdate="$(SPECDATE)" \
  --attribute revremark="$(SPECREMARK)" \
  --attribute SYCL_LANGUAGE_VERSION="$(SYCLLANGVERSION)" \
  --attribute SYCL_NAME="$(SYCLNAME)" \
  --attribute SYCL_VERSION="$(SYCLVERSION)" \
  --attribute SYCL_REVISION="$(SYCLREVISION)" \
  --attribute stem=latexmath \
  --attribute imageopts="$(IMAGEOPTS)" \
  --attribute config=$(CURDIR)/config \
  --attribute images=$(IMAGEPATH) \
  --attribute code_dir=$(CODE_DIR) \
  --attribute header_dir=$(HEADER_DIR) \
  --attribute generated=$(GENERATED) \
  --attribute refprefix \
  $(VERSIONATTRIBS)
ADOCMISCOPTS = --require asciidoctor-diagram --failure-level INFO
ADOCEXTS     = --require $(CURDIR)/config/spec-macros.rb \
	--require $(CURDIR)/config/rouge_sycl.rb
ADOCOPTS     = --doctype book $(ADOCMISCOPTS) $(ATTRIBOPTS) \
  $(NOTEOPTS) $(VERBOSE) $(ADOCEXTS)

ADOCHTMLEXTS = --require $(CURDIR)/config/katex_replace.rb \
  --require $(CURDIR)/config/loadable_html.rb \
  --require $(CURDIR)/config/synopsis.rb \
  --require $(CURDIR)/config/accordion_toc.rb \
  --require $(CURDIR)/config/api_xrefs.rb

# ADOCHTMLOPTS relies on the relative runtime path from the output HTML
# file to the katex scripts being set with KATEXDIR. This is overridden
# by some targets.
# ADOCHTMLOPTS also relies on the absolute build-time path to the
# 'stylesdir' containing our custom CSS.
KATEXDIR     = katex
ADOCHTMLOPTS = $(ADOCHTMLEXTS) --attribute katexpath=$(KATEXDIR) \
  --attribute stylesheet=khronos.css --attribute stylesdir=$(CURDIR)/config \
  --attribute sectanchors
ADOCPDFEXTS  = --require asciidoctor-pdf --require asciidoctor-mathematical \
  --require $(CURDIR)/config/asciidoctor-mathematical-ext.rb
ADOCPDFOPTS  = $(ADOCPDFEXTS) --attribute mathematical-format=svg \
  --attribute imagesoutdir=$(PDFMATHDIR) \
  --attribute pdf-themesdir=$(CURDIR)/config/themes \
  --attribute pdf-theme=pdf \
  --attribute hyphens=en_us

.PHONY: directories

# Images used by the spec. These are included in generated HTML now.
IMAGEPATH = $(CURDIR)/images
SVGFILES  = $(wildcard $(IMAGEPATH)/*.svg)

# Code samples
CODE_DIR = $(CURDIR)/code

# Header samples
HEADER_DIR = $(CURDIR)/headers

# Top-level spec source file
SPECSRC = syclbase.adoc
# Static files making up sections of the API spec.
SPECFILES = $(wildcard *.adoc) $(wildcard chapters/*.adoc) $(wildcard extensions/*.adoc)

# Shorthand for where different types of generated files go.
# All can be relocated by overriding GENERATED in the make invocation.
GENERATED      = $(CURDIR)
# All non-format-specific dependencies
COMMONDOCS     = $(SPECFILES) $(GENDEPENDS)

# Install katex in $(OUTDIR)/katex for reference by all HTML targets
# README.md is a proxy for all the katex files that need to be installed
katexinst: KATEXDIR = katex
katexinst: $(OUTDIR)/$(KATEXDIR)/README.md

$(OUTDIR)/$(KATEXDIR)/README.md: katex/README.md
	$(QUIET)$(MKDIR) $(OUTDIR)
	$(QUIET)$(RMRF)  $(OUTDIR)/$(KATEXDIR)
	$(QUIET)$(CP) --archive katex $(OUTDIR)

# Script to add href to anchors
GENANCHORLINKS = $(SCRIPTS)/genanchorlinks.py

# Spec targets
# There is some complexity to try and avoid short virtual targets like 'html'
# causing specs to *always* be regenerated.
ROSWELL = ros
ROSWELLOPTS ?= dynamic-space-size=4000
CHUNKER = $(HOME)/common-lisp/asciidoctor-chunker/roswell/asciidoctor-chunker.ros
CHUNKINDEX = $(CURDIR)/config/chunkindex
# Only the $(ROSWELL) step is required unless the search index is to be
# generated and incorporated into the chunked spec.
#
# Dropped $(QUIET) for now
# Should set NODE_PATH=/usr/local/lib/node_modules or wherever, outside Makefile
# Copying chunked.js into target avoids a warning from the chunker
chunked: $(HTMLDIR)/$(SPEC_BASE_NAME).html $(SPECSRC) $(COMMONDOCS)
	$(QUIET)$(PATCH) $(HTMLDIR)/$(SPEC_BASE_NAME).html \
	  -o $(HTMLDIR)/prechunked.html $(CHUNKINDEX)/custom.patch
	$(QUIET)$(CP) $(CHUNKINDEX)/chunked.css $(CHUNKINDEX)/chunked.js \
	  $(CHUNKINDEX)/lunr.js $(HTMLDIR)
	$(QUIET)$(ROSWELL) $(ROSWELLOPTS) $(CHUNKER) \
	  $(HTMLDIR)/prechunked.html -o $(HTMLDIR)
	$(QUIET)$(RM) $(HTMLDIR)/prechunked.html
	$(QUIET)$(RUBY) $(CHUNKINDEX)/generate-index.rb $(HTMLDIR)/chap*html | \
	  $(NODEJS) $(CHUNKINDEX)/build-index.js > $(HTMLDIR)/search.index.js

html: $(HTMLDIR)/$(SPEC_BASE_NAME).html $(SPECSRC) $(COMMONDOCS)

%.html: KATEXDIR = ../katex
%.html: $(SPECSRC) $(COMMONDOCS) katexinst
	$(QUIET)$(ASCIIDOC) --backend html5 $(ADOCOPTS) $(ADOCHTMLOPTS) \
	  --out-file $@ $(SPECSRC)
	$(QUIET)$(PYTHON) $(GENANCHORLINKS) $@ $@
	$(QUIET)$(NODEJS) translate_math.js $@

diff_html: $(HTMLDIR)/diff.html $(SPECSRC) $(COMMONDOCS)

$(HTMLDIR)/diff.html: KATEXDIR = ../katex
$(HTMLDIR)/diff.html: $(SPECSRC) $(COMMONDOCS) katexinst
	$(QUIET)$(ASCIIDOC) --backend html5 $(ADOCOPTS) $(ADOCHTMLOPTS) \
	  --attribute diff_extensions="$(DIFFEXTENSIONS)" \
	  --require $(CURDIR)/config/extension-highlighter.rb --trace \
	  --out-file $@ $(SPECSRC)
	$(QUIET)$(NODEJS) translate_math.js $@

pdf: $(PDFDIR)/$(SPEC_BASE_NAME).pdf $(SPECSRC) $(COMMONDOCS)

OPTIMIZEPDF = hexapdf optimize $(OPTIMIZEPDFOPTS)
%.pdf: $(SPECSRC) $(COMMONDOCS)
	$(QUIET)$(MKDIR) $(PDFDIR)
	$(QUIET)$(MKDIR) $(PDFMATHDIR)
	$(QUIET)$(ASCIIDOCPDF) --trace $(ADOCOPTS) $(ADOCPDFOPTS) \
	  --out-file $@ $(SPECSRC)
	$(QUIET)$(OPTIMIZEPDF) $@ $@.out && mv $@.out $@
	$(QUIET)rm -rf $(PDFMATHDIR)

# Reflow text in spec sources
REFLOW = $(SCRIPTS)/reflow.py
REFLOWOPTS = -overwrite

reflow:
	$(QUIET) echo "Warning: please verify the spec outputs build without changes!"
	$(PYTHON) $(REFLOW) $(REFLOWOPTS) $(SPECSRC) $(SPECFILES)

# Clean generated and output files

clean: clean_html clean_pdf

clean_html:
	$(QUIET)$(RMRF) $(HTMLDIR) $(OUTDIR)/katex

clean_pdf:
	$(QUIET)$(RMRF) $(PDFDIR)

# Expose docker-TARGET to forward a TARGET inside a Docker container.
# For example:
#   make docker-clean docker-html docker-pdf
# Also useful to have a shell inside docker:
#   make docker-bash
#
# Set the user and group inside the container to match the user and group
# outside of the container.  This causes the generated files to be owned by the
# current user when accessed from outside the container.  However, this user
# probably doesn't have write access to the default HOME directory, so set HOME
# to some directory that does have write access.  This is important because
# some tools (e.g. asciidoctor-pdf) write temporary files into HOME.  It does
# not matter that we are polluting /tmp here because the entire container will
# be discarded when the build is complete.
docker-%:
	sudo docker run --user `id --user`:`id --group` --env HOME=/tmp \
	  --interactive --tty --rm \
	  --volume $(SYCL_DIR):/sycl \
	  khronosgroup/docker-images:asciidoctor-spec \
	  $(MAKE) MAKEFLAGS="$(MAKEFLAGS)" --directory=/sycl/adoc $*

dock:
	# First update the Docker image to latest Gem with rouge and run
	# $DOCKER_COMMAND with current user and group id the published
	# AsciiDoctor capable Khronos docker image with current SYCL
	# specification directory mounted in /sycl
	sudo docker run \
	  --interactive --tty --rm \
	  -e USER_ID=`id --user` -e GROUP_ID=`id --group` \
          --volume $(SYCL_DIR):/sycl \
          khronosgroup/docker-images:asciidoctor-spec \
	  /sycl/adoc/scripts/install-rouge.sh \
	  $(DOCKER_COMMAND)

# Use a default rule to just execute by the shell the given rule.
# For example "make bash" will run bash, "make env" will display the
# environment to debug the configuration, etc.
# Mainly to be used in docker context.
.DEFAULT:
	$@
