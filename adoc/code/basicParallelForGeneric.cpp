// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

myQueue.submit([&](handler& cgh) {
  auto acc = myBuffer.get_access<access_mode::write>(cgh);

  cgh.parallel_for(range<1>(numWorkItems), [=](auto item) {
    // kernel argument type is auto treated as an item
    size_t index = item.get_linear_id();
    acc[index] = index;
  });
});
