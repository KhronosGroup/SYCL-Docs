// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
template <int Dimensions = 1> class nd_item {
 public:
  static constexpr int dimensions = Dimensions;

  nd_item() = delete;

  /* -- common interface members -- */

  id<Dimensions> get_global_id() const;

  size_t get_global_id(int dimension) const;

  size_t get_global_linear_id() const;

  id<Dimensions> get_local_id() const;

  size_t get_local_id(int dimension) const;

  size_t get_local_linear_id() const;

  group<Dimensions> get_group() const;

  sub_group get_sub_group() const;

  size_t get_group(int dimension) const;

  size_t get_group_linear_id() const;

  range<Dimensions> get_group_range() const;

  size_t get_group_range(int dimension) const;

  range<Dimensions> get_global_range() const;

  size_t get_global_range(int dimension) const;

  range<Dimensions> get_local_range() const;

  size_t get_local_range(int dimension) const;

  // Deprecated in SYCL 2020.
  id<Dimensions> get_offset() const;

  nd_range<Dimensions> get_nd_range() const;

  // Deprecated in SYCL 2020. 
  template <typename DataT>
  device_event async_work_group_copy(local_ptr<DataT> dest,
                                     global_ptr<DataT> src,
                                     size_t numElements) const;

  // Deprecated in SYCL 2020.
  template <typename DataT>
  device_event async_work_group_copy(global_ptr<DataT> dest,
                                     local_ptr<DataT> src,
                                     size_t numElements) const;

  // Deprecated in SYCL 2020.
  template <typename DataT>
  device_event async_work_group_copy(local_ptr<DataT> dest,
                                     global_ptr<DataT> src,
                                     size_t numElements,
                                     size_t srcStride) const;

  // Deprecated in SYCL 2020.
  template <typename DataT>
  device_event async_work_group_copy(global_ptr<DataT> dest,
                                     local_ptr<DataT> src,
                                     size_t numElements,
                                     size_t destStride) const;

  /* Available only when: (std::is_same_v<DestDataT,
       std::remove_const_t<SrcDataT>> == true) */
  template <typename DestDataT, typename SrcDataT>
  device_event async_work_group_copy(decorated_local_ptr<DestDataT> dest,
                                     decorated_global_ptr<SrcDataT> src,
                                     size_t numElements) const;

  /* Available only when: (std::is_same_v<DestDataT,
       std::remove_const_t<SrcDataT>> == true) */
  template <typename DestDataT, typename SrcDataT>
  device_event async_work_group_copy(decorated_global_ptr<DestDataT> dest,
                                     decorated_local_ptr<SrcDataT> src,
                                     size_t numElements) const;

  /* Available only when: (std::is_same_v<DestDataT,
       std::remove_const_t<SrcDataT>> == true) */
  template <typename DestDataT, typename SrcDataT>
  device_event async_work_group_copy(decorated_local_ptr<DestDataT> dest,
                                     decorated_global_ptr<SrcDataT> src,
                                     size_t numElements,
                                     size_t srcStride) const;

  /* Available only when: (std::is_same_v<DestDataT,
       std::remove_const_t<SrcDataT>> == true) */
  template <typename DestDataT, typename SrcDataT>
  device_event async_work_group_copy(decorated_global_ptr<DestDataT> dest,
                                     decorated_local_ptr<SrcDataT> src,
                                     size_t numElements,
                                     size_t destStride) const;

  template <typename... EventTN> void wait_for(EventTN... events) const;
};
} // namespace sycl
