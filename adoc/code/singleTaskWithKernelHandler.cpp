// Copyright (c) 2011-2024 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

myQueue.submit([&](handler& cgh) {
cgh.single_task(
    [=] (kernel_handler kh) {
    // [kernel code]
    }));
});
