// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

template <backend Backend>
class backend_traits {
 public:
  template <class T>
  using input_type = /* see below */;

  template <class T>
  using return_type = /* see below */;

  using errc = /* see below */;
};

template <backend Backend, typename SyclType>
using backend_input_t =
    typename backend_traits<Backend>::template input_type<SyclType>;

template <backend Backend, typename SyclType>
using backend_return_t =
    typename backend_traits<Backend>::template return_type<SyclType>;

}  // namespace sycl
