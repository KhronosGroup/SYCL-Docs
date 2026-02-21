// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
template <int Dimensions = 1> class nd_item {
 public:
  static constexpr int dimensions = Dimensions;

  nd_item() = delete;

  /* -- common interface members -- */

  id<Dimensions> get_global_id() const noexcept;

  std::size_t get_global_id(int dimension) const noexcept;

  std::size_t get_global_linear_id() const noexcept;

  id<Dimensions> get_local_id() const noexcept;

  std::size_t get_local_id(int dimension) const noexcept;

  std::size_t get_local_linear_id() const noexcept;

  group<Dimensions> get_group() const noexcept;

  sub_group get_sub_group() const noexcept;

  std::size_t get_group(int dimension) const noexcept;

  std::size_t get_group_linear_id() const noexcept;

  range<Dimensions> get_group_range() const noexcept;

  std::size_t get_group_range(int dimension) const noexcept;

  range<Dimensions> get_global_range() const noexcept;

  std::size_t get_global_range(int dimension) const noexcept;

  range<Dimensions> get_local_range() const noexcept;

  std::size_t get_local_range(int dimension) const noexcept;

  // Deprecated in SYCL 2020.
  id<Dimensions> get_offset() const noexcept;

  nd_range<Dimensions> get_nd_range() const noexcept;

  // Deprecated in SYCL 2020. 
  template <typename DataT>
  device_event async_work_group_copy(local_ptr<DataT> dest,
                                     global_ptr<DataT> src,
                                     std::size_t numElements) const noexcept;

  // Deprecated in SYCL 2020.
  template <typename DataT>
  device_event async_work_group_copy(global_ptr<DataT> dest,
                                     local_ptr<DataT> src,
                                     std::size_t numElements) const noexcept;

  // Deprecated in SYCL 2020.
  template <typename DataT>
  device_event async_work_group_copy(local_ptr<DataT> dest,
                                     global_ptr<DataT> src,
                                     std::size_t numElements,
                                     std::size_t srcStride) const noexcept;

  // Deprecated in SYCL 2020.
  template <typename DataT>
  device_event async_work_group_copy(global_ptr<DataT> dest,
                                     local_ptr<DataT> src,
                                     std::size_t numElements,
                                     std::size_t destStride) const noexcept;

  /* Available only when: (std::is_same_v<DestDataT,
       std::remove_const_t<SrcDataT>> == true) */
  template <typename DestDataT, typename SrcDataT>
  device_event async_work_group_copy(decorated_local_ptr<DestDataT> dest,
                                     decorated_global_ptr<SrcDataT> src,
                                     std::size_t numElements) const noexcept;

  /* Available only when: (std::is_same_v<DestDataT,
       std::remove_const_t<SrcDataT>> == true) */
  template <typename DestDataT, typename SrcDataT>
  device_event async_work_group_copy(decorated_global_ptr<DestDataT> dest,
                                     decorated_local_ptr<SrcDataT> src,
                                     std::size_t numElements) const noexcept;

  /* Available only when: (std::is_same_v<DestDataT,
       std::remove_const_t<SrcDataT>> == true) */
  template <typename DestDataT, typename SrcDataT>
  device_event async_work_group_copy(decorated_local_ptr<DestDataT> dest,
                                     decorated_global_ptr<SrcDataT> src,
                                     std::size_t numElements,
                                     std::size_t srcStride) const noexcept;

  /* Available only when: (std::is_same_v<DestDataT,
       std::remove_const_t<SrcDataT>> == true) */
  template <typename DestDataT, typename SrcDataT>
  device_event async_work_group_copy(decorated_global_ptr<DestDataT> dest,
                                     decorated_local_ptr<SrcDataT> src,
                                     std::size_t numElements,
                                     std::size_t destStride) const noexcept;

  template <typename... EventTN> void wait_for(EventTN... events) const noexcept;
};
} // namespace sycl
