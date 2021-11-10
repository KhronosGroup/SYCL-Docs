// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
template <typename DataT,
          int Dimensions = 1,
          access_mode AccessMode =
            (std::is_const_v<DataT> ? access_mode::read
                                    : access_mode::read_write),
class host_accessor {
 public:
  using value_type =             // const DataT for read-only accessors, DataT otherwise
      __value_type__;
  using reference = value_type &;
  using const_reference = const DataT &;
  using iterator = __unspecified_iterator__<value_type>;
  using const_iterator = __unspecified_iterator__<const value_type>;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;
  using difference_type = typename std::iterator_traits<iterator>::difference_type;
  using size_type = size_t;

  host_accessor();

  /* Available only when: (Dimensions == 0) */
  template <typename AllocatorT>
  host_accessor(buffer<DataT, 1, AllocatorT> &bufferRef,
                const property_list &propList = {});

  /* Available only when: (Dimensions > 0) */
  template <typename AllocatorT>
  host_accessor(buffer<DataT, Dimensions, AllocatorT> &bufferRef,
                const property_list &propList = {});

  /* Available only when: (Dimensions > 0) */
  template <typename AllocatorT, typename TagT>
  host_accessor(buffer<DataT, Dimensions, AllocatorT> &bufferRef, TagT tag,
                const property_list &propList = {});

  /* Available only when: (Dimensions > 0) */
  template <typename AllocatorT>
  host_accessor(buffer<DataT, Dimensions, AllocatorT> &bufferRef,
                range<Dimensions> accessRange, const property_list &propList = {});

  /* Available only when: (Dimensions > 0) */
  template <typename AllocatorT, typename TagT>
  host_accessor(buffer<DataT, Dimensions, AllocatorT> &bufferRef,
                range<Dimensions> accessRange, TagT tag,
                const property_list &propList = {});

  /* Available only when: (Dimensions > 0) */
  template <typename AllocatorT>
  host_accessor(buffer<DataT, Dimensions, AllocatorT> &bufferRef,
                range<Dimensions> accessRange, id<Dimensions> accessOffset,
                const property_list &propList = {});

  /* Available only when: (Dimensions > 0) */
  template <typename AllocatorT, typename TagT>
  host_accessor(buffer<DataT, Dimensions, AllocatorT> &bufferRef,
                range<Dimensions> accessRange, id<Dimensions> accessOffset,
                TagT tag, const property_list &propList = {});

  /* -- common interface members -- */

  void swap(host_accessor &other);

  size_type byte_size() const noexcept;

  size_type size() const noexcept;

  size_type max_size() const noexcept;

  bool empty() const noexcept;

  /* Available only when: (Dimensions > 0) */
  range<Dimensions> get_range() const;

  /* Available only when: (Dimensions > 0) */
  id<Dimensions> get_offset() const;

  /* Available only when: (Dimensions == 0) */
  operator reference() const;

  /* Available only when: (Dimensions > 0) */
  reference operator[](id<Dimensions> index) const;

  /* Available only when: (Dimensions > 1) */
  __unspecified__ &operator[](size_t index) const;

  /* Available only when: (Dimensions == 1) */
  reference operator[](size_t index) const;

  std::add_pointer_t<value_type> get_pointer() const noexcept;

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
