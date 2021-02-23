// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

class kernel {
 public:
  kernel() = delete;

  backend get_backend() const noexcept;

  context get_context() const;

  kernel_bundle<bundle_state::executable> get_kernel_bundle() const;

  template <typename param>
  typename param::return_type get_info() const;

  template <typename param>
  typename param::return_type get_info(const device &dev) const;

  template <typename param>
  typename param::return_type get_backend_info() const;
};

}  // namespace sycl
