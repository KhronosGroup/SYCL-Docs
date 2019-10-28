#include <CL/sycl.hpp>
#include <iostream>

int main() {
  using namespace cl::sycl;

  int data[1024];  // Allocate data to be worked on

  // By sticking all the SYCL work in a {} block, we ensure
  // all SYCL tasks must complete before exiting the block,
  // because the destructor of resultBuf will wait.
  {
    // Create a queue to enqueue work to
    queue myQueue;

    // Wrap our data variable in a buffer
    buffer<int, 1> resultBuf { data, range<1> { 1024 } };

    // Create a command_group to issue commands to the queue
    myQueue.submit([&](handler& cgh) {
      // request access to the buffer
      auto writeResult = resultBuf.get_access<access::mode::discard_write>(cgh);

      // Enqueue a parallel_for task
      cgh.parallel_for<class simple_test>(range<1> { 1024 }, [=](id<1> idx) {
        writeResult[idx] = idx[0];
      });  // End of the kernel function
    });    // End of our commands for this queue
  }        // End of scope, so we wait for work producing resultBuf to complete

  // Print result
  for (int i = 0; i < 1024; i++)
    std::cout << "data[" << i << "] = " << data[i] << std::endl;

  return 0;
}
