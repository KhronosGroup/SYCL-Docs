// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
namespace property {
namespace buffer {
class use_host_ptr {
  public:
    use_host_ptr() = default;
};

class use_mutex {
  public:
    use_mutex(std::mutex &mutexRef);

    std::mutex *get_mutex_ptr() const;
};

class context_bound {
  public:
    context_bound(context boundContext);

    context get_context() const;
};
}  // namespace buffer
}  // namespace property

template <typename T, int Dimensions = 1,
          typename AllocatorT = buffer_allocator<std::remove_const_t<T>>>
class buffer {
 public:
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using allocator_type = AllocatorT;

  buffer(const range<Dimensions> &bufferRange,
         const property_list &propList = {});

  buffer(const range<Dimensions> &bufferRange, AllocatorT allocator,
         const property_list &propList = {});

  buffer(T *hostData, const range<Dimensions> &bufferRange,
         const property_list &propList = {});

  buffer(T *hostData, const range<Dimensions> &bufferRange,
         AllocatorT allocator, const property_list &propList = {});

  buffer(const T *hostData, const range<Dimensions> &bufferRange,
         const property_list &propList = {});

  buffer(const T *hostData, const range<Dimensions> &bufferRange,
         AllocatorT allocator, const property_list &propList = {});

  /* Available only if Container is a contiguous container:
       - std::data(container) and std::size(container) are well formed
       - return type of std::data(container) is convertible to T*
     and Dimensions == 1 */
  template <typename Container>
  buffer(Container &container, AllocatorT allocator,
         const property_list &propList = {});

  /* Available only if Container is a contiguous container:
       - std::data(container) and std::size(container) are well formed
       - return type of std::data(container) is convertible to T*
     and Dimensions == 1 */
  template <typename Container>
  buffer(Container &container, const property_list &propList = {});

  buffer(const std::shared_ptr<T> &hostData,
         const range<Dimensions> &bufferRange, AllocatorT allocator,
         const property_list &propList = {});

  buffer(const std::shared_ptr<T> &hostData,
         const range<Dimensions> &bufferRange,
         const property_list &propList = {});

  buffer(const std::shared_ptr<T[]> &hostData,
         const range<Dimensions> &bufferRange, AllocatorT allocator,
         const property_list &propList = {});

  buffer(const std::shared_ptr<T[]> &hostData,
         const range<Dimensions> &bufferRange,
         const property_list &propList = {});

  template <class InputIterator>
  buffer<T, 1>(InputIterator first, InputIterator last, AllocatorT allocator,
               const property_list &propList = {});

  template <class InputIterator>
  buffer<T, 1>(InputIterator first, InputIterator last,
               const property_list &propList = {});

  buffer(buffer &b, const id<Dimensions> &baseIndex,
         const range<Dimensions> &subRange);

  /* -- common interface members -- */

  /* -- property interface members -- */

  range<Dimensions> get_range() const;

  size_t byte_size() const noexcept;

  size_t size() const noexcept;

  // Deprecated
  size_t get_count() const;

  // Deprecated
  size_t get_size() const;

  AllocatorT get_allocator() const;

  template <access_mode Mode = access_mode::read_write, target Targ = target::device>
  accessor<T, Dimensions, Mode, Targ> get_access(
      handler &commandGroupHandler);

  // Deprecated
  template <access_mode Mode>
  accessor<T, Dimensions, Mode, target::host_buffer> get_access();

  template <access_mode Mode = access_mode::read_write, target Targ = target::device>
  accessor<T, Dimensions, Mode, Targ> get_access(
      handler &commandGroupHandler, range<Dimensions> accessRange,
      id<Dimensions> accessOffset = {});

  // Deprecated
  template <access_mode Mode>
  accessor<T, Dimensions, Mode, target::host_buffer> get_access(
    range<Dimensions> accessRange, id<Dimensions> accessOffset = {});

  template<typename... Ts>
  auto get_access(Ts...);

  template<typename... Ts>
  auto get_host_access(Ts...);

  template <typename Destination = std::nullptr_t>
  void set_final_data(Destination finalData = nullptr);

  void set_write_back(bool flag = true);

  bool is_sub_buffer() const;

  template <typename ReinterpretT, int ReinterpretDim>
  buffer<ReinterpretT, ReinterpretDim,
         typename std::allocator_traits<AllocatorT>::template rebind_alloc<
             ReinterpretT>>
  reinterpret(range<ReinterpretDim> reinterpretRange) const;

  // Only available when ReinterpretDim == 1
  // or when (ReinterpretDim == Dimensions) &&
  //         (sizeof(ReinterpretT) == sizeof(T))
  template <typename ReinterpretT, int ReinterpretDim = Dimensions>
  buffer<ReinterpretT, ReinterpretDim,
         typename std::allocator_traits<AllocatorT>::template rebind_alloc<
             ReinterpretT>>
  reinterpret() const;
};

// Deduction guides
template <class InputIterator, class AllocatorT>
buffer(InputIterator, InputIterator, AllocatorT, const property_list & = {})
    -> buffer<typename std::iterator_traits<InputIterator>::value_type, 1,
             AllocatorT>;

template <class InputIterator>
buffer(InputIterator, InputIterator, const property_list & = {})
    -> buffer<typename std::iterator_traits<InputIterator>::value_type, 1>;

template <class T, int Dimensions, class AllocatorT>
buffer(const T *, const range<Dimensions> &, AllocatorT,
       const property_list & = {})
    -> buffer<T, Dimensions, AllocatorT>;

template <class T, int Dimensions>
buffer(const T *, const range<Dimensions> &, const property_list & = {})
    -> buffer<T, Dimensions>;

template <class Container, class AllocatorT>
buffer(Container &, AllocatorT, const property_list & = {})
    ->buffer<typename Container::value_type, 1, AllocatorT>;

template <class Container>
buffer(Container &, const property_list & = {})
    ->buffer<typename Container::value_type, 1>;

}  // namespace sycl
