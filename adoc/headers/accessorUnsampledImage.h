// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

enum class image_target : /* unspecified */ { device, host_task };

template <typename DataT, int Dimensions, access_mode AccessMode,
          image_target AccessTarget = image_target::device>
class unsampled_image_accessor {
 public:
  using value_type = // const DataT for read-only accessors, DataT otherwise
      __value_type__;
  using reference = value_type&;
  using const_reference = const DataT&;

  template <typename AllocatorT>
  unsampled_image_accessor(unsampled_image<Dimensions, AllocatorT>& imageRef,
                           handler& commandGroupHandlerRef,
                           const property_list& propList = {});

  /* -- common interface members -- */

  /* -- property interface members -- */

  std::size_t size() const noexcept;

  /* Available only when: AccessMode == access_mode::read
  if Dimensions == 1, CoordT = int
  if Dimensions == 2, CoordT = int2
  if Dimensions == 3, CoordT = int4 */
  template <typename CoordT> DataT read(const CoordT& coords) const noexcept;

  /* Available only when: AccessMode == access_mode::write
  if Dimensions == 1, CoordT = int
  if Dimensions == 2, CoordT = int2
  if Dimensions == 3, CoordT = int4 */
  template <typename CoordT>
  void write(const CoordT& coords, const DataT& color) const;
};

template <typename DataT, int Dimensions = 1,
          access_mode AccessMode =
              (std::is_const_v<DataT> ? access_mode::read
                                      : access_mode::read_write)>
class host_unsampled_image_accessor {
 public:
  using value_type = // const DataT for read-only accessors, DataT otherwise
      __value_type__;
  using reference = value_type&;
  using const_reference = const DataT&;

  template <typename AllocatorT>
  host_unsampled_image_accessor(
      unsampled_image<Dimensions, AllocatorT>& imageRef,
      const property_list& propList = {});

  /* -- common interface members -- */

  /* -- property interface members -- */

  std::size_t size() const noexcept;

  /* Available only when: (AccessMode == access_mode::read ||
                           AccessMode == access_mode::read_write)
  if Dimensions == 1, CoordT = int
  if Dimensions == 2, CoordT = int2
  if Dimensions == 3, CoordT = int4 */
  template <typename CoordT> DataT read(const CoordT& coords) const noexcept;

  /* Available only when: (AccessMode == access_mode::write ||
                           AccessMode == access_mode::read_write)
  if Dimensions == 1, CoordT = int
  if Dimensions == 2, CoordT = int2
  if Dimensions == 3, CoordT = int4 */
  template <typename CoordT>
  void write(const CoordT& coords, const DataT& color) const;
};

} // namespace sycl
