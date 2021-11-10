// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

#include <sycl/sycl.hpp>
using namespace sycl; // (optional) avoids need for "sycl::" before SYCL names

constexpr int N = 512;

template<bool HasFp16>
class MyKernel {
 public:
  void operator()(id<1> i) {
    if constexpr (HasFp16) {
      // Algorithm using sycl::half type
    } else {
      // Fall back code for devices that don't support sycl::half
    }
  }
};

int main() {
  queue myQueue;
  myQueue.submit([&](handler& cgh) {
    device dev = myQueue.get_device();
    if (dev.has(aspect::fp16)) {
      cgh.parallel_for(range{N}, MyKernel<any_device_has_v<aspect::fp16>>{});
    } else {
      cgh.parallel_for(range{N}, MyKernel<all_devices_have_v<aspect::fp16>>{});
    }
  });

  myQueue.wait();
}
