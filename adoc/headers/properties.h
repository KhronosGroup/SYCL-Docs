// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

template <typename propertyT>
struct is_property;

template <typename propertyT>
inline constexpr bool is_property_v = is_property<propertyT>::value;

template <typename propertyT, typename syclObjectT>
struct is_property_of;

template <typename propertyT, typename syclObjectT>
inline constexpr bool is_property_of_v = is_property_of<propertyT, syclObjectT>::value;

class T {
  ...

  template <typename propertyT>
  bool has_property() const noexcept;

  template <typename propertyT>
  propertyT get_property() const;

  ...
};

class property_list {
 public:
   template <typename... propertyTN>
   property_list(propertyTN... props);
};
}  // namespace sycl
