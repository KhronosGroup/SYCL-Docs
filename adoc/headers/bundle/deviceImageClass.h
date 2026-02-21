// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

template <bundle_state State> class device_image {
 public:
  device_image() = delete;

  bool has_kernel(const kernel_id& kernelId) const noexcept;

  bool has_kernel(const kernel_id& kernelId, const device& dev) const noexcept;
};

} // namespace sycl
