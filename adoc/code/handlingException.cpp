// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

void catch_any_errors(sycl::context const& ctx) {
  try {
    do_something_to_invoke_error(ctx);
  } catch (sycl::exception const& e) {
    std::cerr << e.what();
  }
}
