// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

#include <sycl/sycl.hpp>
using namespace sycl;  // (optional) avoids need for "sycl::" before SYCL names

// Forward declare names for our two kernels.
class MyKernel1;
class MyKernel2;

extern int get_width();
extern int get_height();

// Declare specialization constants used in our kernels.
constexpr specialization_id<int> width;
constexpr specialization_id<int> height;

int main() {
  queue myQueue;
  auto myContext = myQueue.get_context();

  // Get the identifiers for our kernels, then get an input kernel bundle that
  // contains our two kernels.
  auto kernelIds = {get_kernel_id<MyKernel1>(), get_kernel_id<MyKernel2>()};
  auto inputBundle =
      get_kernel_bundle<bundle_state::input>(myContext, kernelIds);

  // Set the values of the specialization constants.
  inputBundle.set_specialization_constant<width>(get_width());
  inputBundle.set_specialization_constant<height>(get_height());

  // Build the kernel bundle into an executable form.  The values of the
  // specialization constants are compiled in.
  auto exeBundle = build(inputBundle);

  myQueue.submit([&](handler& cgh) {
    // Use the kernel bundle we built in this command group.
    cgh.use_kernel_bundle(exeBundle);
    cgh.parallel_for<MyKernel1>(
        range{1024}, ([=](item index, kernel_handler kh) {
          // Read the value of the specialization constant.
          int w = kh.get_specialization_constant<width>();
          // ...
        }));
  });

  myQueue.submit([&](handler& cgh) {
    // This command group uses the same kernel bundle.
    cgh.use_kernel_bundle(exeBundle);
    cgh.parallel_for<MyKernel2>(
        range{1024}, ([=](item index, kernel_handler kh) {
          int h = kh.get_specialization_constant<height>();
          // ...
        }));
  });

  myQueue.wait();
}
