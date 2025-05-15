// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
template <int Dimensions = 1, bool WithOffset = true> class item {
 public:
  static constexpr int dimensions = Dimensions;

  item() = delete;

  /* -- common interface members -- */

  id<Dimensions> get_id() const;

  size_t get_id(int dimension) const;

  size_t operator[](int dimension) const;

  range<Dimensions> get_range() const;

  size_t get_range(int dimension) const;

  // Deprecated in SYCL 2020.
  // only available if WithOffset is true
  id<Dimensions> get_offset() const;

  // Deprecated in SYCL 2020.
  // only available if WithOffset is false
  operator item<Dimensions, true>() const;

  // only available if Dimensions == 1
  operator size_t() const;

  size_t get_linear_id() const;
};
} // namespace sycl
