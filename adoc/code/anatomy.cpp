#include <iostream>
#include <sycl/sycl.hpp>
using namespace sycl; // (optional) avoids need for "sycl::" before SYCL names

std::vector<int> A_host(1024);

int main() {
  // Create a default queue to enqueue work to the default device
  queue myQueue{property::queue::in_order()};

  // Allocate shared memory to be worked on on the default device
  int *A_device = malloc_device<int>(1024, myQueue);

  // Enqueue a parallel_for task with 1024 work-items
  myQueue.parallel_for(1024, [=](id<1> idx) {
    // Initialize each buffer element with its own rank number starting at 0
    A_device[idx] = idx;
  }); // End of the kernel function

  // Copy the results back to the device from the host
  myQueue.copy(A_device, A_host.data(), 1024);

  myQueue.wait(); // Wait for the queue to finish executing on the device

  // Print result
  for (int i = 0; i < 1024; i++)
    std::cout << "A_shared[" << i << "] = " << A_host[i] << std::endl;

  // Reclaim memory on the host and the device
  free(A_device, myQueue);

  return 0;
}
