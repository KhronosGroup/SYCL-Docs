// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

class MyKernel;

queue myQueue;
auto usmPtr = malloc_device<int>(1024, myQueue);  // USM pointer

int* data = /* pointer to some data */;
buffer buf{data, {1024}};
accessor acc{buf};  // Placeholder accessor

// Queue shortcut for a kernel invocation
myQueue.single_task<MyKernel>([=] {
  // Allowed to use USM pointers,
  // not allowed to use accessors
  usmPtr[0] = 0;
});

// Placeholder accessor will automatically be registered
myQueue.copy(data, acc);
