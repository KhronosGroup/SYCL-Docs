// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {
template <class T> struct is_group;

template <class T> inline constexpr bool is_group_v = is_group<T>::value;
} // namespace sycl
