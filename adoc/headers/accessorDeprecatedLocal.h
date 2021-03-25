// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

template <typename dataT,
          int dimensions,
          access_mode accessMode,
          target accessTarget,
          access::placeholder isPlaceholder>
class accessor {
 public:
  using value_type = dataT;
  using reference = dataT &;
  using const_reference = const dataT &;

  /* Available only when: (dimensions == 0) */
  accessor(handler &commandGroupHandlerRef,
           const property_list &propList = {});

  /* Available only when: (dimensions > 0) */
  accessor(range<dimensions> allocationSize, handler &commandGroupHandlerRef,
           const property_list &propList = {});

  /* -- common interface members -- */

  size_t get_size() const;

  size_t get_count() const;

  /* Available only when: (dimensions > 0) */
  range<dimensions> get_range() const;

  /* Available only when: (accessMode == access_mode::read_write && dimensions == 0) */
  operator reference() const;

  /* Available only when: (accessMode == access_mode::read_write && dimensions > 0) */
  reference operator[](id<dimensions> index) const;

  /* Available only when: (dimensions > 1) */
  __unspecified__ &operator[](size_t index) const;

  /* Available only when: (accessMode == access_mode::read_write && dimensions == 1) */
  reference operator[](size_t index) const;

  /* Available only when: (accessMode == access_mode::atomic && dimensions == 0) */
  operator atomic<dataT, access::address_space::local_space> () const;

  /* Available only when: (accessMode == access_mode::atomic && dimensions > 0) */
  atomic<dataT, access::address_space::local_space> operator[](id<dimensions> index) const;

  /* Available only when: (accessMode == access_mode::atomic && dimensions == 1) */
  atomic<dataT, access::address_space::local_space> operator[](size_t index) const;

  local_ptr<dataT> get_pointer() const noexcept;
};

}  // namespace sycl
