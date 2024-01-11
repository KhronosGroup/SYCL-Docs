// Copyright (c) 2011-2023 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

class handler {
 public:
  // ...

  template <typename T>
  void host_task(T&& hostTaskCallable); // (1)

  // ...
};
