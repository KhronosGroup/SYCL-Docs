// Copyright (c) 2011-2024 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

template <typename T = void> struct minimum {
  T operator()(const T& x, const T& y) const;
};

template <> struct minimum<void> {
  template <class T, class U> constexpr auto operator()(T&& t, U&& u) const
  -> decltype(std::forward<U>(u) < std::forward<T>(t) ? std::forward<U>(u) : std::forward<T>(t));

  using is_transparent = /* unspecified */;
};

} // namespace sycl
