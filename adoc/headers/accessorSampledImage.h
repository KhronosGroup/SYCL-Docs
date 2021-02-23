// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

enum class image_target {
  device,
  host_task
};

template <typename dataT,
          int dimensions,
          image_target accessTarget = image_target::device>
class sampled_image_accessor {
 public:
  using value_type = const dataT;
  using reference = const dataT &;
  using const_reference = const dataT &;

  template <typename AllocatorT>
  sampled_image_accessor(sampled_image<dimensions, AllocatorT> &imageRef,
                         handler &commandGroupHandlerRef,
                         const property_list &propList = {});

  template <typename AllocatorT, typename TagT>
  sampled_image_accessor(sampled_image<dimensions, AllocatorT> &imageRef,
                         handler &commandGroupHandlerRef, TagT tag,
                         const property_list &propList = {});

  /* -- common interface members -- */

  /* -- property interface members -- */

  size_t size() const noexcept;

  /* if dimensions == 1, coordT = float
     if dimensions == 2, coordT = float2
     if dimensions == 3, coordT = float4 */
  template <typename coordT>
  dataT read(const coordT &coords) const noexcept;
};

template <typename dataT, int dimensions>
class host_sampled_image_accessor {
 public:
  using value_type = const dataT;
  using reference = const dataT &;
  using const_reference = const dataT &;

  template <typename AllocatorT>
  host_sampled_image_accessor(sampled_image<dimensions, AllocatorT> &imageRef,
                              const property_list &propList = {});

  /* -- common interface members -- */

  /* -- property interface members -- */

  size_t size() const noexcept;

  /* if dimensions == 1, coordT = float
     if dimensions == 2, coordT = float2
     if dimensions == 3, coordT = float4 */
  template <typename coordT>
  dataT read(const coordT &coords) const noexcept;
};

}  // namespace sycl
