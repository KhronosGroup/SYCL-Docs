// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

enum class image_format : /* unspecified */ {
  r8g8b8a8_unorm,
  r16g16b16a16_unorm,
  r8g8b8a8_sint,
  r16g16b16a16_sint,
  r32b32g32a32_sint,
  r8g8b8a8_uint,
  r16g16b16a16_uint,
  r32b32g32a32_uint,
  r16b16g16a16_sfloat,
  r32g32b32a32_sfloat,
  b8g8r8a8_unorm
};

template <int Dimensions = 1, typename AllocatorT = sycl::image_allocator>
class unsampled_image {
 public:
  unsampled_image(image_format format, const range<Dimensions>& rangeRef,
                  const property_list& propList = {});

  unsampled_image(image_format format, const range<Dimensions>& rangeRef,
                  AllocatorT allocator, const property_list& propList = {});

  /* Available only when: Dimensions > 1 */
  unsampled_image(image_format format, const range<Dimensions>& rangeRef,
                  const range<Dimensions - 1>& pitch,
                  const property_list& propList = {});

  /* Available only when: Dimensions > 1 */
  unsampled_image(image_format format, const range<Dimensions>& rangeRef,
                  const range<Dimensions - 1>& pitch, AllocatorT allocator,
                  const property_list& propList = {});

  unsampled_image(void* hostPointer, image_format format,
                  const range<Dimensions>& rangeRef,
                  const property_list& propList = {});

  unsampled_image(void* hostPointer, image_format format,
                  const range<Dimensions>& rangeRef, AllocatorT allocator,
                  const property_list& propList = {});

  /* Available only when: Dimensions > 1 */
  unsampled_image(void* hostPointer, image_format format,
                  const range<Dimensions>& rangeRef,
                  const range<Dimensions - 1>& pitch,
                  const property_list& propList = {});

  /* Available only when: Dimensions > 1 */
  unsampled_image(void* hostPointer, image_format format,
                  const range<Dimensions>& rangeRef,
                  const range<Dimensions - 1>& pitch, AllocatorT allocator,
                  const property_list& propList = {});

  unsampled_image(std::shared_ptr<void>& hostPointer, image_format format,
                  const range<Dimensions>& rangeRef,
                  const property_list& propList = {});

  unsampled_image(std::shared_ptr<void>& hostPointer, image_format format,
                  const range<Dimensions>& rangeRef, AllocatorT allocator,
                  const property_list& propList = {});

  /* Available only when: Dimensions > 1 */
  unsampled_image(std::shared_ptr<void>& hostPointer, image_format format,
                  const range<Dimensions>& rangeRef,
                  const range<Dimensions - 1>& pitch,
                  const property_list& propList = {});

  /* Available only when: Dimensions > 1 */
  unsampled_image(std::shared_ptr<void>& hostPointer, image_format format,
                  const range<Dimensions>& rangeRef,
                  const range<Dimensions - 1>& pitch, AllocatorT allocator,
                  const property_list& propList = {});

  /* -- common interface members -- */

  /* -- property interface members -- */

  range<Dimensions> get_range() const;

  /* Available only when: Dimensions > 1 */
  range<Dimensions - 1> get_pitch() const;

  size_t byte_size() const noexcept;

  size_t size() const noexcept;

  AllocatorT get_allocator() const;

  template <typename DataT,
            access_mode Mode = (std::is_const_v<DataT>
                                    ? access_mode::read
                                    : access_mode::read_write),
            image_target Targ = image_target::device>
  unsampled_image_accessor<DataT, Dimensions, Mode, Targ>
  get_access(handler& commandGroupHandler, const property_list& propList = {});

  template <typename DataT, access_mode Mode = (std::is_const_v<DataT>
                                                    ? access_mode::read
                                                    : access_mode::read_write)>
  host_unsampled_image_accessor<DataT, Dimensions, Mode>
  get_host_access(const property_list& propList = {});

  template <typename Destination = std::nullptr_t>
  void set_final_data(Destination finalData = nullptr);

  void set_write_back(bool flag = true);
};

} // namespace sycl
