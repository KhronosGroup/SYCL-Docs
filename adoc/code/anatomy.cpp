// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

#include <iostream>
#include <sycl/sycl.hpp>
#include <vector>
using namespace sycl; // (optional) avoids need for "sycl::" before SYCL names

int main() {
  // Allocate host memory to store the results
  std::vector<int> dataHost(1024);

  // Create an in order queue to enqueue work to the default device
  queue myQueue{property::queue::in_order()};

  // Allocate device memory to be worked on
  int *dataDevice = malloc_device<int>(1024, myQueue);

  // Enqueue a parallel_for task with 1024 work-items
  myQueue.parallel_for(1024, [=](id<1> idx) {
    // Initialize each buffer element with its own rank number starting at 0
    dataDevice[idx] = idx;
  }); // End of the kernel function

  // Copy the results back to the host from the device
  myQueue.copy(dataDevice, dataHost.data(), 1024);

  myQueue.wait(); // Wait for the queue to finish executing all the tasks

  // Print result
  for (int i = 0; i < 1024; i++)
    std::cout << "dataHost[" << i << "] = " << dataHost[i] << std::endl;

  // Free device memory
  free(dataDevice, myQueue);

  return 0;
}
