// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

// Predefined device selectors
__unspecified__ default_selector_v;
__unspecified__ cpu_selector_v;
__unspecified__ gpu_selector_v;
__unspecified__ accelerator_selector_v;

// Predefined types for compatibility with old SYCL 1.2.1 device selectors
using default_selector = __unspecified__;
using cpu_selector = __unspecified__;
using gpu_selector = __unspecified__;
using accelerator_selector = __unspecified__;

// Returns a selector that selects a device based on desired aspects
__unspecified_callable__ aspect_selector(
  const std::vector<aspect> &aspectList,
  const std::vector<aspect> &denyList = {});
template <class... AspectList>
__unspecified_callable__ aspect_selector(AspectList... aspectList);
template <aspect... AspectList>
__unspecified_callable__ aspect_selector();

} // namespace sycl
