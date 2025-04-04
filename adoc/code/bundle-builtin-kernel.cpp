// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

#include <sycl/sycl.hpp>
using namespace sycl;  // (optional) avoids need for "sycl::" before SYCL names

int main() {
  queue myQueue;
  auto myContext = myQueue.get_context();
  auto myDevice = myQueue.get_device();

  const std::vector<kernel_id> builtinKernelIds =
      myDevice.get_info<info::device::built_in_kernel_ids>();

  // Get an executable kernel_bundle containing all the built-in kernels
  // supported by the device.
  kernel_bundle<bundle_state::executable> myBundle =
      get_kernel_bundle(myContext, {myDevice}, builtinKernelIds);

  // Retrieve a kernel object that can be used to query for more information
  // about the built-in kernel or to submit it to a command group.  We assume
  // here that the device supports at least one built-in kernel.
  kernel builtinKernel = myBundle.get_kernel(builtinKernelIds[0]);

  // Submit the built-in kernel.
  myQueue.submit([&](handler& cgh) {
    // Setting the arguments depends on the backend and the exact kernel used.
    cgh.set_args(...);
    cgh.parallel_for(range{1024}, builtinKernel);
  });

  myQueue.wait();
}
