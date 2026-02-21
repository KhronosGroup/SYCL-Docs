# Copyright (c) 2011-2026 The Khronos Group, Inc.
# SPDX-License-Identifier: Apache-2.0

require 'asciidoctor/extensions' unless RUBY_ENGINE == 'opal'

include ::Asciidoctor

# Add HTML anchors for "[role=synopsis,id=X]" blocks, changing the HTML from
# this:
#
# <div id="X" class="XX synopsis">
#
# to this:
#
# <div id="X" class="XX synopsis">
# <a href="#X"></a>
#
# Note that this happens only if the block has an "id" attribute.
#
# This extension also relies on some custom CSS styling to turn the anchor into
# into a marker that you can click on to get the URL of the synopsis block.  See
# the CSS entries for the class name "synopsis".

class AddSynopsisAnchors < Extensions::Postprocessor

  SynopsisDiv = /<div id="([^"]*)" class="[^"]*\bsynopsis\b[^"]*"[^>]*>/m
  Replacement = '\0
<a href="#\1"></a>'

  def process document, output

    if document.basebackend? 'html'
      output.gsub! SynopsisDiv, Replacement
    end
    output

  end
end
