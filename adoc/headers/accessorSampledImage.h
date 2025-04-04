// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

enum class image_target : /* unspecified */ { device, host_task };

template <typename DataT, int Dimensions,
          image_target AccessTarget = image_target::device>
class sampled_image_accessor {
 public:
  using value_type = const DataT;
  using reference = const DataT&;
  using const_reference = const DataT&;

  template <typename AllocatorT>
  sampled_image_accessor(sampled_image<Dimensions, AllocatorT>& imageRef,
                         handler& commandGroupHandlerRef,
                         const property_list& propList = {});


  /* -- common interface members -- */

  /* -- property interface members -- */

  size_t size() const noexcept;

  /* if Dimensions == 1, CoordT = float
     if Dimensions == 2, CoordT = float2
     if Dimensions == 3, CoordT = float4 */
  template <typename CoordT> DataT read(const CoordT& coords) const noexcept;
};

template <typename DataT, int Dimensions> class host_sampled_image_accessor {
 public:
  using value_type = const DataT;
  using reference = const DataT&;
  using const_reference = const DataT&;

  template <typename AllocatorT>
  host_sampled_image_accessor(sampled_image<Dimensions, AllocatorT>& imageRef,
                              const property_list& propList = {});

  /* -- common interface members -- */

  /* -- property interface members -- */

  size_t size() const noexcept;

  /* if Dimensions == 1, CoordT = float
     if Dimensions == 2, CoordT = float2
     if Dimensions == 3, CoordT = float4 */
  template <typename CoordT> DataT read(const CoordT& coords) const noexcept;
};

} // namespace sycl
