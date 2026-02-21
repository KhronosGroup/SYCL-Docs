# -*- coding: utf-8 -*- #
# frozen_string_literal: true
# Copyright (c) 2011-2026 The Khronos Group, Inc.
# SPDX-License-Identifier: Apache-2.0

puts "Loading rouge_sycl extensions for source code highlighting"

require 'rouge'

RUBY_ENGINE == 'opal' ? (require 'rouge/lib/rouge/lexers/sycl' ;
                         require 'rouge/lib/rouge/themes/sycl_spec') \
                      : (require_relative 'rouge/lib/rouge/lexers/sycl' ;
                         require_relative 'rouge/lib/rouge/themes/sycl_spec')
