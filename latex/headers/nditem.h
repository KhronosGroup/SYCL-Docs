namespace cl {
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

  id<dimensions> get_offset() const;

  nd_range<dimensions> get_nd_range() const;

  void barrier(access::fence_space accessSpace =
    access::fence_space::global_and_local) const;

  template <access::mode accessMode = access::mode::read_write>
  void mem_fence(access::fence_space accessSpace =
    access::fence_space::global_and_local) const;

  template <typename dataT>
  device_event async_work_group_copy(local_ptr<dataT> dest,
    global_ptr<dataT> src, size_t numElements) const;

  template <typename dataT>
  device_event async_work_group_copy(global_ptr<dataT> dest,
    local_ptr<dataT> src, size_t numElements) const;

  template <typename dataT>
  device_event async_work_group_copy(local_ptr<dataT> dest,
    global_ptr<dataT> src, size_t numElements, size_t srcStride) const;

  template <typename dataT>
  device_event async_work_group_copy(global_ptr<dataT> dest,
    local_ptr<dataT> src, size_t numElements, size_t destStride) const;

  template <typename... eventTN>
  void wait_for(eventTN... events) const;
};
}  // namespace sycl
}  // namespace cl
