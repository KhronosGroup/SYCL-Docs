// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
template <int Dimensions = 1> class nd_range {
 public:
  static constexpr int dimensions = Dimensions;

  /* -- common interface members -- */

  // The offset is deprecated in SYCL 2020.
  nd_range(range<Dimensions> globalSize, range<Dimensions> localSize,
           id<Dimensions> offset = id<Dimensions>());

  range<Dimensions> get_global_range() const;
  range<Dimensions> get_local_range() const;
  range<Dimensions> get_group_range() const;
  id<Dimensions> get_offset() const; // Deprecated in SYCL 2020.
};
} // namespace sycl
