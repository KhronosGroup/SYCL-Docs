// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

myQueue.submit([&](handler& cgh) {
  auto acc = myBuffer.get_access<access_mode::write>(cgh);

  cgh.parallel_for(range<1>(numWorkItems), [=](size_t index) {
    // kernel argument type is size_t
    acc[index] = index;
  });
});
