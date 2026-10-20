// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

#include <iostream>
#include <sycl/sycl.hpp>
#include <vector>

int main() {
  // Declare number of work items
  constexpr size_t N = 1024;

  // Allocate host memory to store the results
  std::vector<int> dataHost(N);

  // Create an in order queue to enqueue work to the default device
  sycl::queue myQueue{sycl::property::queue::in_order()};

  // Allocate device memory to be worked on
  int *dataDevice = sycl::malloc_device<int>(N, myQueue);

  // Enqueue a parallel_for task with 1024 work-items
  myQueue.parallel_for(N, [=](sycl::id<1> idx) {
    // Initialize each buffer element with its own rank number starting at 0
    dataDevice[idx] = idx;
  }); // End of the kernel function

  // Copy the results back to the host from the device
  myQueue.copy(dataDevice, dataHost.data(), N);

  myQueue.wait(); // Wait for the queue to finish executing all the tasks

  // Print result
  for (int i = 0; i < N; i++)
    std::cout << "dataHost[" << i << "] = " << dataHost[i] << std::endl;

  // Free device memory
  sycl::free(dataDevice, myQueue);

  return 0;
}
