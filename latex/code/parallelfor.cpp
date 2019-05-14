myQueue.submit([&](handler & cgh) {
 cgh.parallel_for<class example_kernel1>(
    range<3>(3,3,3), // global range
      [=] (item<3> it) {
        //[kernel code]
      });
});
myQueue.submit([&](handler & cgh) {
 cgh.parallel_for<class example_kernel2>(
    range<3>(3,3,3), // global range
    id<3>(1,1,1), // offset
      [=] (item<3> it) {
        //[kernel code]
      });
});
