// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

myQueue.submit([&](handler& cgh) {
  cgh.parallel_for(nd_range<3>(range<3>(4, 4, 4), range<3>(2, 2, 2)),
                   [=](nd_item<3> item) {
                     //[kernel code]
                     group_barrier(item.get_group());
                     //[kernel code]
                   });
});
