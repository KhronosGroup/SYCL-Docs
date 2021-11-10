// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
template <typename DataT, int Dimensions = 1>
class local_accessor {
 public:
  using value_type =             // const DataT for read-only accessors, DataT otherwise
      __value_type__;
  using reference = value_type &;
  using const_reference = const DataT &;
  template <access::decorated IsDecorated>
      using accessor_ptr =
          multi_ptr<value_type, access::address_space::local_space, IsDecorated>;
  using iterator = __unspecified_iterator__<value_type>;
  using const_iterator = __unspecified_iterator__<const value_type>;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;
  using difference_type = typename std::iterator_traits<iterator>::difference_type;
  using size_type = size_t;

  local_accessor();

  /* Available only when: (Dimensions == 0) */
  local_accessor(handler &commandGroupHandlerRef,
                 const property_list &propList = {});

  /* Available only when: (Dimensions > 0) */
  local_accessor(range<Dimensions> allocationSize, handler &commandGroupHandlerRef,
                 const property_list &propList = {});

  /* -- common interface members -- */

  void swap(accessor &other);

  size_type byte_size() const noexcept;

  size_type size() const noexcept;

  size_type max_size() const noexcept;

  bool empty() const noexcept;

  range<Dimensions> get_range() const;

  /* Available only when: (Dimensions == 0) */
  operator reference() const;

  /* Available only when: (Dimensions > 0) */
  reference operator[](id<Dimensions> index) const;

  /* Available only when: (Dimensions > 1) */
  __unspecified__ &operator[](size_t index) const;

  /* Available only when: (Dimensions == 1) */
  reference operator[](size_t index) const;

  std::add_pointer_t<value_type> get_pointer() const noexcept;

  template <access::decorated IsDecorated>
  accessor_ptr<IsDecorated> get_multi_ptr() const noexcept;

  iterator begin() const noexcept;

  iterator end() const noexcept;

  const_iterator cbegin() const noexcept;

  const_iterator cend() const noexcept;

  reverse_iterator rbegin() const noexcept;

  reverse_iterator rend() const noexcept;

  const_reverse_iterator crbegin() const noexcept;

  const_reverse_iterator crend() const noexcept;
};
}  // namespace sycl
