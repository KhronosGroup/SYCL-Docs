# Copyright (c) 2011-2026 The Khronos Group, Inc.
#
# SPDX-License-Identifier: Apache-2.0

#require 'asciidoctor/extensions' unless RUBY_ENGINE == 'opal'
RUBY_ENGINE == 'opal' ? (require 'spec-macros/extension') : (require_relative 'spec-macros/extension')

# All the inline macros we need
Asciidoctor::Extensions.register do
    inline_macro MustInlineMacro
    inline_macro ReflinkInlineMacro
    inline_macro CodeInlineMacro
end
