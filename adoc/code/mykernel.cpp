// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

// Explicit kernel names can be optionally forward declared at namespace scope
class MyKernel;

myQueue.submit([&](handler& h) {
  // Explicitly name kernel with previously forward declared type
  h.single_task<MyKernel>([=] {
    // [kernel code]
  });
});

// Explicitly name kernel without forward declaring type at
// namespace scope.  Must still be forward declarable at
// namespace scope, even if not declared at that scope
myQueue.submit([&](handler& h) {
  h.single_task<class MyOtherKernel>([=] {
    // [kernel code]
  });
});
