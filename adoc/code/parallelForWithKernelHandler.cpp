// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

myQueue.submit([&](handler& cgh) {
  cgh.parallel_for(range<3>(3, 3, 3),  // global range
                   [=](item<3> it, kernel_handler kh) {
                     //[kernel code]
                   });
});

// This form of parallel_for with the "offset" parameter is deprecated in SYCL
// 2020
myQueue.submit([&](handler& cgh) {
  cgh.parallel_for(range<3>(3, 3, 3),  // global range
                   id<3>(1, 1, 1),     // offset
                   [=](item<3> it, kernel_handler kh) {
                     //[kernel code]
                   });
});
