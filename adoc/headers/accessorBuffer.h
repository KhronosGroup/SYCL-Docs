// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

enum class target {
  device,
  host_task,
  global_buffer = device,             // Deprecated
  constant_buffer,                    // Deprecated
  local,                              // Deprecated
  host_buffer                         // Deprecated
};

namespace access {
  // The legacy type "access::target" is deprecated.
  using sycl::target;

enum class placeholder { // Deprecated
  false_t,
  true_t
};

}  // namespace access


template <typename dataT,
          int dimensions = 1,
          access_mode accessMode =
            (std::is_const_v<dataT> ? access_mode::read
                                    : access_mode::read_write),
          target accessTarget = target::device,
          access::placeholder isPlaceholder = access::placeholder::false_t>
class accessor {
 public:
  using value_type =             // const dataT for read-only accessors, dataT otherwise
      __value_type__;
  using reference = value_type &;
  using const_reference = const dataT &;
  template <access::decorated IsDecorated>
      using accessor_ptr =       // multi_ptr to value_type with target address space,
          __pointer_class__;     //   unspecified for access_mode::host_task
  using iterator = __unspecified_iterator__<value_type>;
  using const_iterator = __unspecified_iterator__<const value_type>;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;
  using difference_type = typename std::iterator_traits<iterator>::difference_type;
  using size_type = size_t;

  accessor();

  /* Available only when: (dimensions == 0) */
  template <typename AllocatorT>
  accessor(buffer<dataT, 1, AllocatorT> &bufferRef,
           const property_list &propList = {});

  /* Available only when: (dimensions == 0) */
  template <typename AllocatorT>
  accessor(buffer<dataT, 1, AllocatorT> &bufferRef,
           handler &commandGroupHandlerRef, const property_list &propList = {});

  /* Available only when: (dimensions > 0) */
  template <typename AllocatorT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           const property_list &propList = {});

  /* Available only when: (dimensions > 0) */
  template <typename AllocatorT, typename TagT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef, TagT tag,
           const property_list &propList = {});

  /* Available only when: (dimensions > 0) */
  template <typename AllocatorT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           handler &commandGroupHandlerRef, const property_list &propList = {});

  /* Available only when: (dimensions > 0) */
  template <typename AllocatorT, typename TagT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           handler &commandGroupHandlerRef, TagT tag,
           const property_list &propList = {});

  /* Available only when: (dimensions > 0) */
  template <typename AllocatorT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           range<dimensions> accessRange, const property_list &propList = {});

  /* Available only when: (dimensions > 0) */
  template <typename AllocatorT, typename TagT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           range<dimensions> accessRange, TagT tag,
           const property_list &propList = {});

  /* Available only when: (dimensions > 0) */
  template <typename AllocatorT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           range<dimensions> accessRange, id<dimensions> accessOffset,
           const property_list &propList = {});

  /* Available only when: (dimensions > 0) */
  template <typename AllocatorT, typename TagT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           range<dimensions> accessRange, id<dimensions> accessOffset,
           TagT tag, const property_list &propList = {});

  /* Available only when: (dimensions > 0) */
  template <typename AllocatorT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           handler &commandGroupHandlerRef, range<dimensions> accessRange,
           const property_list &propList = {});

  /* Available only when: (dimensions > 0) */
  template <typename AllocatorT, typename TagT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           handler &commandGroupHandlerRef, range<dimensions> accessRange,
           TagT tag, const property_list &propList = {});

  /* Available only when: (dimensions > 0) */
  template <typename AllocatorT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           handler &commandGroupHandlerRef, range<dimensions> accessRange,
           id<dimensions> accessOffset, const property_list &propList = {});

  /* Available only when: (dimensions > 0) */
  template <typename AllocatorT, typename TagT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           handler &commandGroupHandlerRef, range<dimensions> accessRange,
           id<dimensions> accessOffset, TagT tag,
           const property_list &propList = {});

  /* -- common interface members -- */

  void swap(accessor &other);

  bool is_placeholder() const;

  size_type byte_size() const noexcept;

  size_type size() const noexcept;

  size_type max_size() const noexcept;

  // Deprecated
  size_t get_size() const;

  // Deprecated
  size_t get_count() const;

  bool empty() const noexcept;

  /* Available only when: (dimensions > 0) */
  range<dimensions> get_range() const;

  /* Available only when: (dimensions > 0) */
  id<dimensions> get_offset() const;

  /* Available only when: (dimensions == 0) */
  operator reference() const;

  /* Available only when: (dimensions > 0) */
  reference operator[](id<dimensions> index) const;

  /* Available only when: (dimensions > 1) */
  __unspecified__ &operator[](size_t index) const;

  /* Available only when: (accessMode != access_mode::atomic && dimensions == 1) */
  reference operator[](size_t index) const;

  /* Deprecated
  Available only when: (accessMode == access_mode::atomic && dimensions ==  0) */
  operator cl::sycl::atomic<dataT, access::address_space::global_space> () const;

  /* Deprecated
  Available only when: (accessMode == access_mode::atomic && dimensions == 1) */
  cl::sycl::atomic<dataT, access::address_space::global_space> operator[](
    id<dimensions> index) const;

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
