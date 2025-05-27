// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

enum class access_mode : /* unspecified */ {
  read,
  write,
  read_write,
  discard_write,      // Deprecated in SYCL 2020
  discard_read_write, // Deprecated in SYCL 2020
  atomic              // Deprecated in SYCL 2020
};

namespace access {
// The legacy type "access::mode" is deprecated.
using mode = sycl::access_mode;
} // namespace access

} // namespace sycl
