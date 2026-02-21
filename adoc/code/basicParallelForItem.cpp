// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

myQueue.submit([&](handler& cgh) {
  accessor acc{myBuffer, cgh, write_only};

  cgh.parallel_for(range<1>(numWorkItems), [=](item<1> item) {
    // kernel argument type is item
    size_t index = item.get_linear_id();
    acc[index] = index;
  });
});
