// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

#include <sycl/sycl.hpp>
using namespace sycl;  // (optional) avoids need for "sycl::" before SYCL names

class MyKernel;  // Forward declare the name of our kernel.

int main() {
  size_t N = 1024;
  queue myQueue;
  auto myContext = myQueue.get_context();
  auto myDev = myQueue.get_device();

  // Get an executable kernel bundle containing our kernel.
  kernel_id kernelId = get_kernel_id<MyKernel>();
  auto myBundle =
      get_kernel_bundle<bundle_state::executable>(myContext, {kernelId});

  // Get the kernel's maximum work-group size when running on our device.
  kernel myKernel = myBundle.get_kernel(kernelId);
  size_t maxWgSize =
      myKernel.get_info<info::kernel_device_specific::work_group_size>(myDev);

  // Compute a good ND-range to use for iteration in the kernel
  // based on the maximum work-group size.
  std::array<size_t, 11> divisors = {1024, 512, 256, 128, 64, 32,
                                     16,   8,   4,   2,   1};
  size_t wgSize = *std::find_if(divisors.begin(), divisors.end(),
                                [=](auto d) { return (d <= maxWgSize); });
  nd_range myRange{range{N}, range{wgSize}};

  myQueue.submit([&](handler& cgh) {
    // Use the kernel bundle we queried, so we are sure the queried work-group
    // size matches the kernel we run.
    cgh.use_kernel_bundle(myBundle);
    cgh.parallel_for<MyKernel>(myRange, ([=](nd_item<1> index) {
                                 // kernel code
                               }));
  });

  myQueue.wait();
}
