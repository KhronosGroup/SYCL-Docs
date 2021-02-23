// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

class kernel_handler {
 private:

  kernel_handler(__unspecified__);

 public:

  template<auto& S>
  bool has_specialization_constant() const noexcept;

  template<auto& S>
  typename std::remove_reference_t<decltype(S)>::type get_specialization_constant();

};

}  // namespace sycl
