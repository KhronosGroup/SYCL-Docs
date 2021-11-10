// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
enum class image_format : unsigned int {
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
  b8g8r8a8_unorm,
};

template <int Dimensions = 1, typename AllocatorT = sycl::image_allocator>
class sampled_image {
 public:
  sampled_image(const void *hostPointer, image_format format,
                  image_sampler sampler, const range<Dimensions> &rangeRef,
                  const property_list &propList = {});

  /* Available only when: Dimensions > 1 */
  sampled_image(const void *hostPointer, image_format format,
                  image_sampler sampler, const range<Dimensions> &rangeRef,
                  const range<Dimensions - 1> &pitch,
                  const property_list &propList = {});

  sampled_image(std::shared_ptr<const void> &hostPointer, image_format format,
                  image_sampler sampler, const range<Dimensions> &rangeRef,
                  const property_list &propList = {});

  /* Available only when: Dimensions > 1 */
  sampled_image(std::shared_ptr<const void> &hostPointer, image_format format,
                  image_sampler sampler, const range<Dimensions> &rangeRef,
                  const range<Dimensions - 1> &pitch,
                  const property_list &propList = {});

  /* -- common interface members -- */

  /* -- property interface members -- */

  range<Dimensions> get_range() const;

  /* Available only when: Dimensions > 1 */
  range<Dimensions - 1> get_pitch() const;

  size_t byte_size() const;

  size_t size() const;

  template<typename... Ts>
  auto get_access(Ts... args);

  template<typename... Ts>
  auto get_host_access(Ts... args);
};
}  // namespace sycl
