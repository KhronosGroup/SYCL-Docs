// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

queue q1(dev1);
if (dev1.has(aspect::fp16)) {
  q1.submit([&](handler& cgh) {
    cgh.parallel_for<KernelA>(range{N}, [=](id i) {
      half fpShort = 1.0;
      /* ... */
    });
  });
}

queue q2(dev2);
if (dev2.has(aspect::atomic64)) {
  q2.submit([&](handler& cgh) {
    cgh.parallel_for<KernelB>(range{N}, [=](id i) {
      /* ... */
      sycl::atomic_ref longAtomic(longValue);
      longAtomic.fetch_add(1);
    });
  });
}
