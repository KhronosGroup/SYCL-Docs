# Copyright (c) 2011-2025 The Khronos Group, Inc.
#
# SPDX-License-Identifier: Apache-2.0

require 'asciidoctor/extensions' unless RUBY_ENGINE == 'opal'

include ::Asciidoctor

class SpecInlineMacroBase < Extensions::InlineMacroProcessor
    use_dsl
    using_format :short
end

class NormativeInlineMacroBase < SpecInlineMacroBase
    def text
        'normative'
    end

    def process parent, target, attributes
        create_inline parent, :quoted, '<strong class="purple">' + text + '</strong>'
    end
end

class LinkInlineMacroBase < SpecInlineMacroBase
    def process parent, target, attributes
      if parent.document.attributes['cross-file-links']
        return Inline.new(parent, :anchor, target, :type => :link, :target => (target + '.html'))
      else
        return Inline.new(parent, :anchor, target, :type => :xref, :target => ('#' + target), :attributes => {'fragment' => target, 'refid' => target})
      end
    end
end

class CodeInlineMacroBase < SpecInlineMacroBase
    def process parent, target, attributes
        create_inline parent, :quoted, '<code>' + target.gsub('&#8594;', '-&gt;') + '</code>'
    end
end

class StrongInlineMacroBase < SpecInlineMacroBase
    def process parent, target, attributes
        create_inline parent, :quoted, '<code>' + target.gsub('&#8594;', '-&gt;') + '</code>'
    end
end

class ParamInlineMacroBase < SpecInlineMacroBase
    def process parent, target, attributes
         create_inline parent, :quoted, '<code>' + target.gsub('&#8594;', '-&gt;') + '</code>'
    end
end

class MustInlineMacro < NormativeInlineMacroBase
    named :must
    match /must:(\w*)/

    def text
        'must'
    end
end

# Generic reference page link to any entity with an anchor/refpage
class ReflinkInlineMacro < LinkInlineMacroBase
    named :reflink
    match /reflink:(\w+)/
end

# This doesn't include the full range of code: use
#    match /code:(\w+(\.\w+)*)/
#    match /code:([-A-Za-z0-9_()<>!=?:"&%|/*^+"]+
class CodeInlineMacro < CodeInlineMacroBase
    named :code
    match /code:([-A-Za-z0-9_()<>!=?:"&%|*^+"\/]+)/
end
