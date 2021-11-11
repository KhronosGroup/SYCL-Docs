// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
class context {
 public:
  explicit context(const property_list &propList = {});

  explicit context(async_handler asyncHandler,
                   const property_list &propList = {});

  explicit context(const device &dev, const property_list &propList = {});

  explicit context(const device &dev, async_handler asyncHandler,
                   const property_list &propList = {});

  explicit context(const std::vector<device> &deviceList,
                   const property_list &propList = {});

  explicit context(const std::vector<device> &deviceList,
                   async_handler asyncHandler,
                   const property_list &propList = {});

  /* -- property interface members -- */

  /* -- common interface members -- */

  backend get_backend() const noexcept;

  platform get_platform() const;

  std::vector<device> get_devices() const;

  template <typename Param> typename Param::return_type get_info() const;

  template <typename Param>
  typename Param::return_type get_backend_info() const;
};
}  // namespace sycl
