// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

myQueue.submit([&](handler& cgh) {
  auto acc = myBuffer.get_access<access_mode::write>(cgh);

  // parallel_for may be called with number (with numWorkItems)
  cgh.parallel_for(numWorkItems, [=](auto item) {
    size_t index = item.get_linear_id();
    acc[index] = index;
  });
});
