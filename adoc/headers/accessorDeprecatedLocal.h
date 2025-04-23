// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

template <typename DataT, int Dimensions, access_mode AccessMode,
          target AccessTarget, access::placeholder IsPlaceholder>
class accessor {
 public:
  using value_type = DataT;
  using reference = DataT&;
  using const_reference = const DataT&;

  /* Available only when: (Dimensions == 0) */
  accessor(handler& commandGroupHandlerRef, const property_list& propList = {});

  /* Available only when: (Dimensions > 0) */
  accessor(range<Dimensions> allocationSize, handler& commandGroupHandlerRef,
           const property_list& propList = {});

  /* -- common interface members -- */

  size_t get_size() const;

  size_t get_count() const;

  /* Available only when: (Dimensions > 0) */
  range<Dimensions> get_range() const;

  /* Available only when: (AccessMode == access_mode::read_write && Dimensions
   * == 0) */
  operator reference() const;

  /* Available only when: (AccessMode == access_mode::read_write && Dimensions >
   * 0) */
  reference operator[](id<Dimensions> index) const;

  /* Available only when: (Dimensions > 1) */
  __unspecified__ operator[](size_t index) const;

  /* Available only when: (AccessMode == access_mode::read_write && Dimensions
   * == 1) */
  reference operator[](size_t index) const;

  /* Available only when: (AccessMode == access_mode::atomic && Dimensions == 0)
   */
  operator atomic<DataT, access::address_space::local_space>() const;

  /* Available only when: (AccessMode == access_mode::atomic && Dimensions > 0)
   */
  atomic<DataT, access::address_space::local_space>
  operator[](id<Dimensions> index) const;

  /* Available only when: (AccessMode == access_mode::atomic && Dimensions == 1)
   */
  atomic<DataT, access::address_space::local_space>
  operator[](size_t index) const;

  local_ptr<DataT> get_pointer() const noexcept;
};

} // namespace sycl
