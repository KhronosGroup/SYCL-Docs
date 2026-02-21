// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
class sub_group {
 public:
  using id_type = id<1>;
  using range_type = range<1>;
  using linear_id_type = std::uint32_t;
  static constexpr int dimensions = 1;
  static constexpr memory_scope fence_scope = memory_scope::sub_group;

  sub_group() = delete;

  /* -- common interface members -- */

  id<1> get_group_id() const noexcept;

  id<1> get_local_id() const noexcept;

  range<1> get_local_range() const noexcept;

  range<1> get_group_range() const noexcept;

  range<1> get_max_local_range() const noexcept;

  std::uint32_t get_group_linear_id() const noexcept;

  std::uint32_t get_local_linear_id() const noexcept;

  std::uint32_t get_group_linear_range() const noexcept;

  std::uint32_t get_local_linear_range() const noexcept;

  bool leader() const noexcept;
};
} // namespace sycl
