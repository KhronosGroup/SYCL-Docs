// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
template <int Dimensions = 1, bool WithOffset = true> class item {
 public:
  static constexpr int dimensions = Dimensions;

  item() = delete;

  /* -- common interface members -- */

  id<Dimensions> get_id() const noexcept;

  std::size_t get_id(int dimension) const noexcept;

  std::size_t operator[](int dimension) const noexcept;

  range<Dimensions> get_range() const noexcept;

  std::size_t get_range(int dimension) const noexcept;

  // Deprecated in SYCL 2020.
  // only available if WithOffset is true
  id<Dimensions> get_offset() const noexcept;

  // Deprecated in SYCL 2020.
  // only available if WithOffset is false
  operator item<Dimensions, true>() const noexcept;

  // only available if Dimensions == 1
  operator std::size_t() const noexcept;

  std::size_t get_linear_id() const noexcept;
};
} // namespace sycl
