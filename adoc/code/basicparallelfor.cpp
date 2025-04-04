// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

myQueue.submit([&](handler& cgh) {
  accessor acc{myBuffer, cgh, write_only};

  cgh.parallel_for(range<1>(numWorkItems),
                   [=](id<1> index) { acc[index] = 42.0f; });
});
