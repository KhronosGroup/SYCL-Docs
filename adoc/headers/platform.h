// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
class platform {
 public:
  platform();

  template <typename DeviceSelector>
  explicit platform(const DeviceSelector &deviceSelector);

  /* -- common interface members -- */

  backend get_backend() const noexcept;

  std::vector<device> get_devices(
    info::device_type = info::device_type::all) const;

  template <typename Param> typename Param::return_type get_info() const;

  template <typename Param>
  typename Param::return_type get_backend_info() const;

  bool has(aspect asp) const;

  bool has_extension(const std::string &extension) const; // Deprecated

  static std::vector<platform> get_platforms();
};
}  // namespace sycl
