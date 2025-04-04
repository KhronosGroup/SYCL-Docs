// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

void catch_invalid_errors(sycl::context const& ctx) {
  try {
    do_something_to_invoke_error(ctx);
  } catch (sycl::exception const& e) {
    if (e.code() == sycl::errc::invalid) {
      std::cerr << "Invalid error: " << e.what();
    } else {
      throw;
    }
  }
}
