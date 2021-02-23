// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
template <int dimensions = 1, bool with_offset = true>
class item {
public:
  item() = delete;

   /* -- common interface members -- */

  id<dimensions> get_id() const;

  size_t get_id(int dimension) const;

  size_t operator[](int dimension) const;

  range<dimensions> get_range() const;

  size_t get_range(int dimension) const;

  // Deprecated in SYCL 2020.
  // only available if with_offset is true
  id<dimensions> get_offset() const;

  // only available if with_offset is false
  operator item<dimensions, true>() const;

  // only available if dimensions == 1
  operator size_t() const;

  size_t get_linear_id() const;
};
}  // namespace sycl
