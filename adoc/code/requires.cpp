// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

class KernelFunctor {
 public:
  void operator()(item<1> it) const [[sycl::requires(has(aspect::fp16))]] {
    foo();
    bar();
  };

 private:
  void foo() const {
    half fp = 1.0;  // No compiler diagnostic here
  }

  void bar() const {
    sycl::atomic_ref longAtomic(longValue);
    longAtomic.fetchAdd(1);   // ERROR: Compiler issues diagnostic because
                              // "aspect::atomic64" missing from "has()"
  }
};

// Using "sycl::requires()" does not provide any guarantee that the device
// actually supports the required features.  Therefore, the host code should
// still check the devices aspects before submitting the kernel.
if (myQueue.get_device().has(aspect::fp16)) {
  myQueue.submit([&](handler &h) {
    h.parallel_for(range{16}, KernelFunctor{});
  });
}
