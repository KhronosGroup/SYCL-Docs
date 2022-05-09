// Copyright (c) 2011-2022 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

void catch_backend_errors(sycl::context const& ctx) {
  try {
    do_something_to_invoke_error(ctx);
  }
  catch(sycl::exception const& e) {
    if(e.category() == sycl::error_category_for<sycl::backend::opencl>()) {
      switch(e.code().value()) {
        case CL_INVALID_PROGRAM:
          std::cerr << "OpenCL invalid program error: " << e.what();
        /* ...*/
      }
      else {
        throw;
      }
    }
    else {
      if(e.code() == sycl::errc::invalid) {
        std::cerr << "Invalid error: " << e.what();
      }
      else {
        throw;
      }
    }
  }
}
