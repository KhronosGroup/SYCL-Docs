// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

#include <sycl/sycl.hpp>
using namespace sycl;  // (optional) avoids need for "sycl::" before SYCL names

int main() {
  queue myQueue;
  auto myContext = myQueue.get_context();

  // This call to get_kernel_bundle() forces an online compilation of all the
  // application's kernels for the device in "myContext", unless those kernels
  // were already compiled for that device by the ahead-of-time compiler.
  auto myBundle = get_kernel_bundle<bundle_state::executable>(myContext);

  myQueue.submit([&](handler& cgh) {
    // Calling use_kernel_bundle() causes the parallel_for() below to use the
    // pre-compiled kernel from "myBundle".
    cgh.use_kernel_bundle(myBundle);

    cgh.parallel_for(range{1024}, ([=](item index) {
                       // kernel code
                     }));
  });

  myQueue.wait();
}
