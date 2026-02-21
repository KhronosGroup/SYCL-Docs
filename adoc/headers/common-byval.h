// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

class T {
  ...

      public
      :
      // If any of the following five special member functions are declared,
      // then all five of them should be explicitly declared (see rule of
      // five).
      //
      // Otherwise, none of them should be explicitly declared
      // (see rule of zero).

      // T(const T &rhs);

      // T(T &&rhs);

      // T &operator=(const T &rhs);

      // T &operator=(T &&rhs);

      // ~T();

      ...

      friend bool
      operator==(const T& lhs, const T& rhs) { /* ... */
  }

  friend bool operator!=(const T& lhs, const T& rhs) { /* ... */ }

  ...
};
} // namespace sycl
