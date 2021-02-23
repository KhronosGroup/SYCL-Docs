// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

class kernel_id {
 public:
  kernel_id() = delete;

  const char *get_name() const noexcept;
};

}  // namespace sycl
