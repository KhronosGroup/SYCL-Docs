// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
/* Deprecated in SYCL 2020 */
template <typename T, int Dimensions = 1> class private_memory {
 public:
  // Construct based directly off the number of work-items
  private_memory(const group<Dimensions>&);

  // Access the instance for the current work-item
  T& operator()(const h_item<Dimensions>& id);
};
} // namespace sycl
