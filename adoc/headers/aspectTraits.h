// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

template <aspect Aspect> struct any_device_has;
template <aspect Aspect> struct all_devices_have;

template <aspect A>
inline constexpr bool any_device_has_v = any_device_has<A>::value;
template <aspect A>
inline constexpr bool all_devices_have_v = all_devices_have<A>::value;

} // namespace sycl
