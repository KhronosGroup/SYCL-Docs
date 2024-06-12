# Copyright (c) 2011-2024 The Khronos Group, Inc.
# SPDX-License-Identifier: Apache-2.0

require 'asciidoctor/extensions' unless RUBY_ENGINE == 'opal'

include ::Asciidoctor

# Add HTML anchors for "[source,role=synopsis,id=X]" blocks, changing the HTML
# from this:
#
# <div id="X" class="listingblock synopsis">
#
# to this:
#
# <div id="X" class="listingblock synopsis">
# <a href="#X"></a>
#
# Note that this happens only if the block has an "id" attribute.
#
# This extension also relies on some custom CSS styling to turn the anchor into
# into a section marker that you can click on to get the URL of the synopsis
# block.  See the CSS entries for the class name "synopsis".
#
# TODO: It would be nice to create a custom Asciidoc block instead of using the
# "role=" syntax.  This would allow the Asciidoc source to look like:
#
# [synopsis,id=X]
#
# However, doing this disables the source code highlighting feature.  I think
# this is because the rouge highlighter looks only at [source] blocks, and I
# cannot find a way to tell it to look at a custom block named [synopsis].

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
