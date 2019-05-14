class MyKernel;  // Forward declaration of the name of the lambda functor

cl::sycl::queue myQueue;
cl::sycl::program myProgram(myQueue.get_context());

/* use the name of the kernel to obtain the associated program */
myProgram.build_from_name<MyKernel>();

myQueue.submit([&](handler& commandGroup) {
  commandgroup.parallel_for<class MyKernel>(
      cl::sycl::nd_range<2>(range<2>(4, 4),range<2>(1,1)),
      MyProgram.get_kernel<MyKernel>(),  // execute the kernel as compiled in MyProgram
      ([=](cl::sycl::nd_item<2> index) {
        //[kernel code]
      }));
});
