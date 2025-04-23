# Copyright (c) 2011-2025 The Khronos Group, Inc.
# SPDX-License-Identifier: Apache-2.0

#require 'asciidoctor/extensions' unless RUBY_ENGINE == 'opal'
RUBY_ENGINE == 'opal' ? (require 'accordion_toc/extension') : (require_relative 'accordion_toc/extension')

Asciidoctor::Extensions.register do
    postprocessor MakeAccordionToc
end
