myQueue.submit([&](handler & cgh) {
  cgh.parallel_for<class example_kernel>(
      nd_range<3>(range<3>(4, 4, 4), range<3>(2, 2, 2)), [=](nd_item<3> item) {
        //[kernel code]
        // Internal synchronization
        item.barrier(access::fence_space::global_space);
        //[kernel code]
      });
});
