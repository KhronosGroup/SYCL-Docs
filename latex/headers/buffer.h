namespace cl {
namespace sycl {
namespace property {
namespace buffer {
class use_host_ptr {
  public:
    use_host_ptr() = default;
};

class use_mutex {
  public:
    use_mutex(mutex_class &mutexRef);

    mutex_class *get_mutex_ptr() const;
};

class context_bound {
  public:
    context_bound(context boundContext);

    context get_context() const;
};
}  // namespace buffer
}  // namespace property

template <typename T, int dimensions = 1,
          typename AllocatorT = cl::sycl::buffer_allocator>
class buffer {
 public:
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using allocator_type = AllocatorT;

  buffer(const range<dimensions> &bufferRange,
         const property_list &propList = {});

  buffer(const range<dimensions> &bufferRange, AllocatorT allocator,
         const property_list &propList = {});

  buffer(T *hostData, const range<dimensions> &bufferRange,
         const property_list &propList = {});

  buffer(T *hostData, const range<dimensions> &bufferRange,
         AllocatorT allocator, const property_list &propList = {});

  buffer(const T *hostData, const range<dimensions> &bufferRange,
         const property_list &propList = {});

  buffer(const T *hostData, const range<dimensions> &bufferRange,
         AllocatorT allocator, const property_list &propList = {});

  buffer(const shared_ptr_class<T> &hostData,
         const range<dimensions> &bufferRange, AllocatorT allocator,
         const property_list &propList = {});

  buffer(const shared_ptr_class<T> &hostData,
         const range<dimensions> &bufferRange,
         const property_list &propList = {});

  template <class InputIterator>
  buffer<T, 1>(InputIterator first, InputIterator last, AllocatorT allocator,
               const property_list &propList = {});

  template <class InputIterator>
  buffer<T, 1>(InputIterator first, InputIterator last,
               const property_list &propList = {});

  buffer(buffer<T, dimensions, AllocatorT> b, const id<dimensions> &baseIndex,
         const range<dimensions> &subRange);

  /* Available only when: dimensions == 1. */
  buffer(cl_mem clMemObject, const context &syclContext,
         event availableEvent = {});

  /* -- common interface members -- */

  /* -- property interface members -- */

  range<dimensions> get_range() const;

  size_t get_count() const;

  size_t get_size() const;

  AllocatorT get_allocator() const;

  template <access::mode mode, access::target target = access::target::global_buffer>
  accessor<T, dimensions, mode, target> get_access(
      handler &commandGroupHandler);

  template <access::mode mode>
  accessor<T, dimensions, mode, access::target::host_buffer> get_access();

  template <access::mode mode, access::target target = access::target::global_buffer>
  accessor<T, dimensions, mode, target> get_access(
      handler &commandGroupHandler, range<dimensions> accessRange,
      id<dimensions> accessOffset = {});

  template <access::mode mode>
  accessor<T, dimensions, mode, access::target::host_buffer> get_access(
    range<dimensions> accessRange, id<dimensions> accessOffset = {});

  template <typename Destination = std::nullptr_t>
  void set_final_data(Destination finalData = std::nullptr);

  void set_write_back(bool flag = true);

  bool is_sub_buffer() const;

  template <typename ReinterpretT, int ReinterpretDim>
  buffer<ReinterpretT, ReinterpretDim, AllocatorT>
  reinterpret(range<ReinterpretDim> reinterpretRange) const;

};
}  // namespace sycl
}  // namespace cl
