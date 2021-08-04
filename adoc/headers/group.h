// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
template <int Dimensions = 1>
class group {
public:

  using id_type = id<Dimensions>;
  using range_type = range<Dimensions>;
  using linear_id_type = size_t;
  static constexpr int dimensions = Dimensions;
  static constexpr memory_scope fence_scope = memory_scope::work_group;

   /* -- common interface members -- */

  id<Dimensions> get_group_id() const;

  size_t get_group_id(int dimension) const;

  id<Dimensions> get_local_id() const;

  size_t get_local_id(int dimension) const;

  range<Dimensions> get_local_range() const;

  size_t get_local_range(int dimension) const;

  range<Dimensions> get_group_range() const;

  size_t get_group_range(int dimension) const;

  range<Dimensions> get_max_local_range() const;

  size_t operator[](int dimension) const;

  size_t get_group_linear_id() const;

  size_t get_local_linear_id() const;

  size_t get_group_linear_range() const;

  size_t get_local_linear_range() const;

  bool leader() const;

  template<typename WorkItemFunctionT>
  void parallel_for_work_item(const WorkItemFunctionT &func) const;

  template<typename WorkItemFunctionT>
  void parallel_for_work_item(range<Dimensions> logicalRange,
    const WorkItemFunctionT &func) const;

  template <typename DataT>
  device_event async_work_group_copy(decorated_local_ptr<DataT> dest,
    decorated_global_ptr<DataT> src, size_t numElements) const;

  template <typename DataT>
  device_event async_work_group_copy(decorated_global_ptr<DataT> dest,
    decorated_local_ptr<DataT> src, size_t numElements) const;

  template <typename DataT>
  device_event async_work_group_copy(decorated_local_ptr<DataT> dest,
    decorated_global_ptr<DataT> src, size_t numElements, size_t srcStride) const;

  template <typename DataT>
  device_event async_work_group_copy(decorated_global_ptr<DataT> dest,
    decorated_local_ptr<DataT> src, size_t numElements, size_t destStride) const;

  template <typename... EventTN>
  void wait_for(EventTN... events) const;
};
}  // sycl
