class MyKernel;  // Forward declaration of the name of the lambda functor

cl::sycl::queue myQueue;

// obtain an existing OpenCL C program object
cl_program myClProgram = ...;

// Create a SYCL program object from a cl_program object
cl::sycl::program myExternProgram(myQueue.get_context(), myClProgram);

// Release the program if we no longer need it as
// SYCL program retained a reference to it
clReleaseProgram(myClProgram);

// Add in the SYCL program object for our kernel
cl::sycl::program mySyclProgram(myQueue.get_context());
mySyclProgram.compile_with_kernel_type<MyKernel>("-my-compile-options");

// Link myClProgram with the SYCL program object
mySyclProgram.link(myExternProgram,"-my-link-options");

myQueue.submit([&](handler& commandgroup) {
  commandgroup.parallel_for<class MyKernel>(
      cl::sycl::range<2>(4, 4),
      myLinkedProgram.get_kernel<MyKernel>(),  // execute the kernel as compiled in MyProgram
      ([=](cl::sycl::item<2> index) {
        //[kernel code]
      }));
});
