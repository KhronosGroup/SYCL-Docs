// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
template <int dimensions = 1>
class nd_item {
public:
  nd_item() = delete;

   /* -- common interface members -- */

  id<dimensions> get_global_id() const;

  size_t get_global_id(int dimension) const;

  size_t get_global_linear_id() const;

  id<dimensions> get_local_id() const;

  size_t get_local_id(int dimension) const;

  size_t get_local_linear_id() const;

  group<dimensions> get_group() const;

  size_t get_group(int dimension) const;

  size_t get_group_linear_id() const;

  range<dimensions> get_group_range() const;

  size_t get_group_range(int dimension) const;

  range<dimensions> get_global_range() const;

  size_t get_global_range(int dimension) const;

  range<dimensions> get_local_range() const;

  size_t get_local_range(int dimension) const;

  // Deprecated in SYCL 2020.
  id<dimensions> get_offset() const;

  nd_range<dimensions> get_nd_range() const;

  template <typename dataT>
  device_event async_work_group_copy(decorated_local_ptr<dataT> dest,
    decorated_global_ptr<dataT> src, size_t numElements) const;

  template <typename dataT>
  device_event async_work_group_copy(decorated_global_ptr<dataT> dest,
    decorated_local_ptr<dataT> src, size_t numElements) const;

  template <typename dataT>
  device_event async_work_group_copy(decorated_local_ptr<dataT> dest,
    decorated_global_ptr<dataT> src, size_t numElements, size_t srcStride) const;

  template <typename dataT>
  device_event async_work_group_copy(decorated_global_ptr<dataT> dest,
    decorated_local_ptr<dataT> src, size_t numElements, size_t destStride) const;

  template <typename... eventTN>
  void wait_for(eventTN... events) const;
};
}  // namespace sycl
