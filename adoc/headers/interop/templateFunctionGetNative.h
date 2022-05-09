// Copyright (c) 2011-2022 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

template<backend Backend, class T>
backend_return_t<Backend, T> get_native(const T &syclObject);

}  // namespace sycl
