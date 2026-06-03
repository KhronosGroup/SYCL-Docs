#include <iostream>
#include <sycl/sycl.hpp>
using namespace sycl; // (optional) avoids need for "sycl::" before SYCL names

int main() {
  // Create a default queue to enqueue work to the default device
  queue myQueue{};
  // Allocate shared memory to be worked on on the default device
  int *A_shared = malloc_shared<int>(1024, myQueue);

  // Enqueue a parallel_for task with 1024 work-items
  myQueue.parallel_for(1024, [=](id<1> idx) {
    // Initialize each buffer element with its own rank number starting at 0
    A_shared[idx] = idx;
  }); // End of the kernel function

  myQueue.wait(); // Wait for the queue to finish executing on the device

  // Reclaim memory on the host and the device
  free(A_shared, myQueue);

  // Print result
  for (int i = 0; i < 1024; i++)
    std::cout << "A_shared[" << i << "] = " << A_shared[i] << std::endl;
  return 0;
}
