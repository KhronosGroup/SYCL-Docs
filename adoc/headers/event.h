// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

class event {
 public:
  event();

  /* -- common interface members -- */

  backend get_backend() const noexcept;

  std::vector<event> get_wait_list();

  void wait();

  static void wait(const std::vector<event> &eventList);

  void wait_and_throw();

  static void wait_and_throw(const std::vector<event> &eventList);

  template <typename Param> typename Param::return_type get_info() const;

  template <typename Param>
  typename Param::return_type get_backend_info() const;

  template <typename Param>
  typename Param::return_type get_profiling_info() const;
};

}  // namespace sycl
