// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
/* Deprecated in SYCL 2020 */
template <int Dimensions> class h_item {
 public:
  static constexpr int dimensions = Dimensions;

  h_item() = delete;

  /* -- common interface members -- */

  item<Dimensions, false> get_global() const noexcept;

  item<Dimensions, false> get_local() const noexcept;

  item<Dimensions, false> get_logical_local() const noexcept;

  item<Dimensions, false> get_physical_local() const noexcept;

  range<Dimensions> get_global_range() const noexcept;

  std::size_t get_global_range(int dimension) const noexcept;

  id<Dimensions> get_global_id() const noexcept;

  std::size_t get_global_id(int dimension) const noexcept;

  range<Dimensions> get_local_range() const noexcept;

  std::size_t get_local_range(int dimension) const noexcept;

  id<Dimensions> get_local_id() const noexcept;

  std::size_t get_local_id(int dimension) const noexcept;

  range<Dimensions> get_logical_local_range() const noexcept;

  std::size_t get_logical_local_range(int dimension) const noexcept;

  id<Dimensions> get_logical_local_id() const noexcept;

  std::size_t get_logical_local_id(int dimension) const noexcept;

  range<Dimensions> get_physical_local_range() const noexcept;

  std::size_t get_physical_local_range(int dimension) const noexcept;

  id<Dimensions> get_physical_local_id() const noexcept;

  std::size_t get_physical_local_id(int dimension) const noexcept;
};
} // namespace sycl
