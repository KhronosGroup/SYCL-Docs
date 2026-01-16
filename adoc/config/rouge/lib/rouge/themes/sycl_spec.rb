# -*- coding: utf-8 -*- #
# frozen_string_literal: true

# The SYCL theme used by Khronos in the SYCL specification

module Rouge
  module Themes
    class SYCLspec < Github
      name 'sycl.spec'

      # Use mostly :bold versions to be clearer and because :italic
      # does not work with asciidoctor-pdf

      # sycl_data_types DarkOrchid3 #9a32cd
      style Keyword::Pseudo,                  :fg => '#9a32cd', :italic => true
      # sycl_functions #00c5cd Turquoise 3
      style Name::Function::Magic,            :fg => '#00c5cd', :bold => true
      # sycl_future_keywords magenta #ff00ff
      style Name::Builtin::Pseudo,            :fg => '#ff00ff', :italic => true
      # sycl_macros OliveDrab2 #b3ee3a
      style Generic::Output,                  :fg => '#b3ee3a', :bold => true
      # sycl_namespaces use official SYCL orange defined by Khronos #f35a1c
      style Generic::Heading,                 :fg => '#f35a1c', :bold => true
      # sycl_opencl_keywords
      style Name::Other,                      :fg => '#ff4500', :italic => true
      # sycl_types VioletRed1 #ff3e96
      style Keyword::Reserved,                :fg => '#ff3e96', :bold => true
      # sycl_variables orange1 #ffa500
      style Name::Variable::Magic,            :fg => '#ffa500', :bold => true
      # Fix the gray comment which is not as visible as YellowGreen #9acd32
      style Comment,                          :fg => '#9acd32'
      style Comment::Multiline,               :fg => '#9acd32'
      style Comment::Single,                  :fg => '#9acd32'
      # Give preprocessing statements a different color from comments.
      # DarkOrchid3 (#9a32cd) is close to what Visual Studio Code uses in its
      # Light Modern theme.  This is the same color we use for sycl_data_types
      # (above), but those are very uncommon in our code listings now.
      style Comment::Preproc,                 :fg => '#9a32cd'
      style Comment::PreprocFile,             :fg => '#9a32cd'
      # Use a clearer white background
      style Text,                             :bg => '#ffffff'

    end
  end
end
