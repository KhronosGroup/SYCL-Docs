// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

#include <sycl/sycl.hpp>

SYCL_EXTERNAL void Foo();

SYCL_EXTERNAL void Bar() { /* ... */ }

SYCL_EXTERNAL extern void Baz();

[[nodiscard]] SYCL_EXTERNAL void Important();

SYCL_EXTERNAL [[nodiscard]] void AlsoImportant();
