// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
/* Deprecated in SYCL 2020 */
template <int Dimensions> class h_item {
 public:
  static constexpr int dimensions = Dimensions;

  h_item() = delete;

  /* -- common interface members -- */

  item<Dimensions, false> get_global() const;

  item<Dimensions, false> get_local() const;

  item<Dimensions, false> get_logical_local() const;

  item<Dimensions, false> get_physical_local() const;

  range<Dimensions> get_global_range() const;

  size_t get_global_range(int dimension) const;

  id<Dimensions> get_global_id() const;

  size_t get_global_id(int dimension) const;

  range<Dimensions> get_local_range() const;

  size_t get_local_range(int dimension) const;

  id<Dimensions> get_local_id() const;

  size_t get_local_id(int dimension) const;

  range<Dimensions> get_logical_local_range() const;

  size_t get_logical_local_range(int dimension) const;

  id<Dimensions> get_logical_local_id() const;

  size_t get_logical_local_id(int dimension) const;

  range<Dimensions> get_physical_local_range() const;

  size_t get_physical_local_range(int dimension) const;

  id<Dimensions> get_physical_local_id() const;

  size_t get_physical_local_id(int dimension) const;
};
} // namespace sycl
