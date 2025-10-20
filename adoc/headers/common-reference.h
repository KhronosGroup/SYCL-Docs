// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

class T {
  ...

      public : T(const T& rhs);

  T(T&& rhs);

  T& operator=(const T& rhs);

  T& operator=(T&& rhs);

  ~T();

  ...

      friend bool
      operator==(const T& lhs, const T& rhs) { /* ... */
  }

  friend bool operator!=(const T& lhs, const T& rhs) { /* ... */ }

  ...
};
} // namespace sycl
