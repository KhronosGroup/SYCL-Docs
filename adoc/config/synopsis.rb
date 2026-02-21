# Copyright (c) 2011-2026 The Khronos Group, Inc.
# SPDX-License-Identifier: Apache-2.0

#require 'asciidoctor/extensions' unless RUBY_ENGINE == 'opal'
RUBY_ENGINE == 'opal' ? (require 'synopsis/extension') : (require_relative 'synopsis/extension')

Asciidoctor::Extensions.register do
    postprocessor AddSynopsisAnchors
end
