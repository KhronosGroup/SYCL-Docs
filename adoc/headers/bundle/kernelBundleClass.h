// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

class kernel { /* ... */ };

template<bundle_state State>
class kernel_bundle {
 public:
  using device_image_iterator = __unspecified__;

  kernel_bundle() = delete;

  bool empty() const noexcept;

  backend get_backend() const noexcept;

  context get_context() const noexcept;

  std::vector<device> get_devices() const noexcept;

  bool has_kernel(const kernel_id &kernelId) const noexcept;

  bool has_kernel(const kernel_id &kernelId, const device &dev) const noexcept;

  std::vector<kernel_id> get_kernel_ids() const;

  /* Available only when: (State == bundle_state::executable) */
  kernel get_kernel(const kernel_id &kernelId) const;

  bool contains_specialization_constants() const noexcept;

  bool native_specialization_constant() const noexcept;

  template<auto& S>
  bool has_specialization_constant() const noexcept;

  /* Available only when: (State == bundle_state::input) */
  template<auto& S>
  void set_specialization_constant(
    typename std::remove_reference_t<decltype(S)>::type value);

  template<auto& S>
  typename std::remove_reference_t<decltype(S)>::type get_specialization_constant() const;

  device_image_iterator begin() const;

  device_image_iterator end() const;
};

}  // namespace sycl
