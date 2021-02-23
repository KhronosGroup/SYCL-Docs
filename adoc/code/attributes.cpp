// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

// Kernel defined as a lambda
myQueue.submit([&](handler &h) {
 h.parallel_for( range<1>(16),
      [=] (item<1> it) [[sycl::reqd_work_group_size(16)]] {
        //[kernel code]
      });
});

// Kernel defined as a functor to be invoked later
class KernelFunctor {
  public:
  void operator()(item<1> it) const [[sycl::reqd_work_group_size(16)]] {
    //[kernel code]
  };
};

