// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

enum class image_target {
  device,
  host_task
};

template <typename dataT,
          int dimensions,
          access_mode accessMode,
          image_target accessTarget = image_target::device>
class unsampled_image_accessor {
 public:
  using value_type =             // const dataT for read-only accessors, dataT otherwise
      __value_type__;
  using reference = value_type &;
  using const_reference = const dataT &;

  template <typename AllocatorT>
  unsampled_image_accessor(unsampled_image<dimensions, AllocatorT> &imageRef,
                           handler &commandGroupHandlerRef,
                           const property_list &propList = {});

  template <typename AllocatorT, typename TagT>
  unsampled_image_accessor(unsampled_image<dimensions, AllocatorT> &imageRef,
                           handler &commandGroupHandlerRef, TagT tag,
                           const property_list &propList = {});

  /* -- common interface members -- */

  /* -- property interface members -- */

  size_t size() const noexcept;

  /* Available only when: accessMode == access_mode::read
  if dimensions == 1, coordT = int
  if dimensions == 2, coordT = int2
  if dimensions == 4, coordT = int4 */
  template <typename coordT>
  dataT read(const coordT &coords) const noexcept;

  /* Available only when: accessMode == access_mode::write
  if dimensions == 1, coordT = int
  if dimensions == 2, coordT = int2
  if dimensions == 3, coordT = int4 */
  template <typename coordT>
  void write(const coordT &coords, const dataT &color) const;
};

template <typename dataT,
          int dimensions,
          access_mode accessMode>
class host_unsampled_image_accessor {
 public:
  using value_type =             // const dataT for read-only accessors, dataT otherwise
      __value_type__;
  using reference = value_type &;
  using const_reference = const dataT &;

  template <typename AllocatorT>
  host_unsampled_image_accessor(unsampled_image<dimensions, AllocatorT> &imageRef,
                                const property_list &propList = {});

  template <typename AllocatorT, typename TagT>
  host_unsampled_image_accessor(unsampled_image<dimensions, AllocatorT> &imageRef,
                                TagT tag, const property_list &propList = {});

  /* -- common interface members -- */

  /* -- property interface members -- */

  size_t size() const noexcept;

  /* Available only when: accessMode == access_mode::read
  if dimensions == 1, coordT = int
  if dimensions == 2, coordT = int2
  if dimensions == 4, coordT = int4 */
  template <typename coordT>
  dataT read(const coordT &coords) const noexcept;

  /* Available only when: accessMode == access_mode::write
  if dimensions == 1, coordT = int
  if dimensions == 2, coordT = int2
  if dimensions == 3, coordT = int4 */
  template <typename coordT>
  void write(const coordT &coords, const dataT &color) const;
};

}  // namespace sycl
