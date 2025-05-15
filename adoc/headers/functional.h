// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

template <typename T = void> struct plus {
  T operator()(const T& x, const T& y) const;
};

template <typename T = void> struct multiplies {
  T operator()(const T& x, const T& y) const;
};

template <typename T = void> struct bit_and {
  T operator()(const T& x, const T& y) const;
};

template <typename T = void> struct bit_or {
  T operator()(const T& x, const T& y) const;
};

template <typename T = void> struct bit_xor {
  T operator()(const T& x, const T& y) const;
};

template <typename T = void> struct logical_and {
  T operator()(const T& x, const T& y) const;
};

template <typename T = void> struct logical_or {
  T operator()(const T& x, const T& y) const;
};

template <typename T = void> struct minimum {
  T operator()(const T& x, const T& y) const;
};

template <typename T = void> struct maximum {
  T operator()(const T& x, const T& y) const;
};

} // namespace sycl
