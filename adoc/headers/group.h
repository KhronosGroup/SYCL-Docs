// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
template <int Dimensions = 1> class group {
 public:
  using id_type = id<Dimensions>;
  using range_type = range<Dimensions>;
  using linear_id_type = std::size_t;
  static constexpr int dimensions = Dimensions;
  static constexpr memory_scope fence_scope = memory_scope::work_group;

  group() = delete;

  /* -- common interface members -- */

  id<Dimensions> get_group_id() const noexcept;

  std::size_t get_group_id(int dimension) const noexcept;

  id<Dimensions> get_local_id() const noexcept;

  std::size_t get_local_id(int dimension) const noexcept;

  range<Dimensions> get_local_range() const noexcept;

  std::size_t get_local_range(int dimension) const noexcept;

  range<Dimensions> get_group_range() const noexcept;

  std::size_t get_group_range(int dimension) const noexcept;

  range<Dimensions> get_max_local_range() const noexcept;

  std::size_t operator[](int dimension) const noexcept;

  std::size_t get_group_linear_id() const noexcept;

  std::size_t get_local_linear_id() const noexcept;

  std::size_t get_group_linear_range() const noexcept;

  std::size_t get_local_linear_range() const noexcept;

  bool leader() const noexcept;

  // Deprecated in SYCL 2020.
  template <typename WorkItemFunctionT>
  void parallel_for_work_item(const WorkItemFunctionT& func) const noexcept;

  // Deprecated in SYCL 2020.
  template <typename WorkItemFunctionT>
  void parallel_for_work_item(range<Dimensions> logicalRange,
                              const WorkItemFunctionT& func) const noexcept;

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
