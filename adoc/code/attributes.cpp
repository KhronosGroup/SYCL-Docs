// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

// Kernel defined as a lambda
myQueue.submit([&](handler& h) {
  h.parallel_for(range<1>(16),
                 [=](item<1> it) [[sycl::reqd_work_group_size(16)]] {
                   //[kernel code]
                 });
});

// Kernel defined as a named function object
class KernelFunctor1 {
 public:
  [[sycl::reqd_work_group_size(16)]] void operator()(item<1> it) const {
    //[kernel code]
  };
};

// Kernel defined as a named function object
class KernelFunctor2 {
 public:
  void operator() [[sycl::reqd_work_group_size(16)]] (item<1> it) const {
    //[kernel code]
  };
};
