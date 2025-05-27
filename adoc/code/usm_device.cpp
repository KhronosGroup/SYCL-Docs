// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

#include <iostream>
#include <sycl/sycl.hpp>
using namespace sycl;  // (optional) avoids need for "sycl::" before SYCL names

int main() {
  // Create a default queue to enqueue work to the default device
  queue myQueue;

  // Allocate device USM, using the device and context associated with the queue
  int* data = sycl::malloc_device<int>(1024, myQueue);

  myQueue.parallel_for(1024, [=](id<1> idx) {
    // Initialize each buffer element with its own rank number starting at 0
    data[idx] = idx;
  });  // End of the kernel function

  // Explicitly wait for kernel execution since there is no accessor involved
  myQueue.wait();

  // Create an array to receive the device content
  int hostData[1024];
  // Receive the content from the device
  myQueue.memcpy(hostData, data, 1024 * sizeof(int));
  // Wait for the copy to complete
  myQueue.wait();

  // Print result
  for (int i = 0; i < 1024; i++)
    std::cout << "hostData[" << i << "] = " << hostData[i] << std::endl;

  return 0;
}
