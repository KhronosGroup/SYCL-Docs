// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

class handler {
 public:
  // ...

  template <typename T>
  void host_task(T&& hostTaskCallable); // (1)

  // ...
};
