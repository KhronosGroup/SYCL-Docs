// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

class kernel_handler {
 private:
  kernel_handler(__unspecified__);

 public:
  template <auto& SpecName>
  typename std::remove_reference_t<decltype(SpecName)>::value_type
  get_specialization_constant();
};

} // namespace sycl
