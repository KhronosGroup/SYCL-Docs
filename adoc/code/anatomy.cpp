#include <iostream>
#include <sycl/sycl.hpp>
#include <vector>
using namespace sycl; // (optional) avoids need for "sycl::" before SYCL names

int main() {
  // Allocate host memory to store the results
  std::vector<int> A_host(1024);

  // Create an in order queue to enqueue work to the default device
  queue myQueue{property::queue::in_order()};

  // Allocate device memory to be worked on
  int *A_device = malloc_device<int>(1024, myQueue);

  // Enqueue a parallel_for task with 1024 work-items
  myQueue.parallel_for(1024, [=](id<1> idx) {
    // Initialize each buffer element with its own rank number starting at 0
    A_device[idx] = idx;
  }); // End of the kernel function

  // Copy the results back to the host from the device
  myQueue.copy(A_device, A_host.data(), 1024);

  myQueue.wait(); // Wait for the queue to finish executing all the tasks

  // Print result
  for (int i = 0; i < 1024; i++)
    std::cout << "A_host[" << i << "] = " << A_host[i] << std::endl;

  // Free device memory
  free(A_device, myQueue);

  return 0;
}
