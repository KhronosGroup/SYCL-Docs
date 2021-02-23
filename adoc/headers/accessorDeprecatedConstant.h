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
  using value_type = const dataT;
  using reference = const dataT &;
  using const_reference = const dataT &;

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
  template <typename AllocatorT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           handler &commandGroupHandlerRef, const property_list &propList = {});

  /* Available only when: (dimensions > 0) */
  template <typename AllocatorT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           range<dimensions> accessRange, const property_list &propList = {});

  /* Available only when: (dimensions > 0) */
  template <typename AllocatorT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           range<dimensions> accessRange, id<dimensions> accessOffset,
           const property_list &propList = {});

  /* Available only when: (dimensions > 0) */
  template <typename AllocatorT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           handler &commandGroupHandlerRef, range<dimensions> accessRange,
           const property_list &propList = {});

  /* Available only when: (dimensions > 0) */
  template <typename AllocatorT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           handler &commandGroupHandlerRef, range<dimensions> accessRange,
           id<dimensions> accessOffset, const property_list &propList = {});

  /* -- common interface members -- */

  bool is_placeholder() const;

  size_t get_size() const noexcept;

  size_t get_count() const noexcept;

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

  /* Available only when: (dimensions == 1) */
  reference operator[](size_t index) const;

  constant_ptr<dataT> get_pointer() const noexcept;
};

}  // namespace sycl
