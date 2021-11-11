// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

class device {
 public:
  device();

  template <typename DeviceSelector>
  explicit device(const DeviceSelector &deviceSelector);

  /* -- common interface members -- */

  backend get_backend() const noexcept;

  bool is_cpu() const;

  bool is_gpu() const;

  bool is_accelerator() const;

  platform get_platform() const;

  template <typename Param> typename Param::return_type get_info() const;

  template <typename Param>
  typename Param::return_type get_backend_info() const;

  bool has(aspect asp) const;

  bool has_extension(const std::string &extension) const; // Deprecated

  // Available only when Prop == info::partition_property::partition_equally
  template <info::partition_property Prop>
  std::vector<device> create_sub_devices(size_t count) const;

  // Available only when Prop == info::partition_property::partition_by_counts
  template <info::partition_property Prop>
  std::vector<device> create_sub_devices(const std::vector<size_t> &counts) const;

  // Available only when Prop == info::partition_property::partition_by_affinity_domain
  template <info::partition_property Prop>
  std::vector<device> create_sub_devices(info::partition_affinity_domain affinityDomain) const;

  static std::vector<device> get_devices(
      info::device_type deviceType = info::device_type::all);
};
} // namespace sycl
