// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl::opencl {

template <bundle_state State>
kernel_bundle<State> create_bundle(const context& ctxt,
                                   const std::vector<device>& devs,
                                   const std::vector<cl_program>& clPrograms);

kernel_bundle<bundle_state::executable>
create_bundle(const context& ctxt, const std::vector<device>& devs,
              const std::vector<cl_kernel>& clKernels);

} // namespace sycl::opencl
