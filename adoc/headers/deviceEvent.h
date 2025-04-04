// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
class device_event {

  device_event(__unspecified__);

 public:
  void wait() noexcept;
};
} // namespace sycl
