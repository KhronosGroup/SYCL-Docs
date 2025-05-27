// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

enum class memory_scope : /* unspecified */ {
  work_item,
  sub_group,
  work_group,
  device,
  system
};

inline constexpr auto memory_scope_work_item = memory_scope::work_item;
inline constexpr auto memory_scope_sub_group = memory_scope::sub_group;
inline constexpr auto memory_scope_work_group = memory_scope::work_group;
inline constexpr auto memory_scope_device = memory_scope::device;
inline constexpr auto memory_scope_system = memory_scope::system;

} // namespace sycl
