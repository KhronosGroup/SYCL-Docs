// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
class queue {
 public:
  explicit queue(const property_list &propList = {});

  explicit queue(const async_handler &asyncHandler,
                 const property_list &propList = {});

  template <typename DeviceSelector>
  explicit queue(const DeviceSelector &deviceSelector,
                 const property_list &propList = {});

  template <typename DeviceSelector>
  explicit queue(const DeviceSelector &deviceSelector,
                 const async_handler &asyncHandler,
                 const property_list &propList = {});

  explicit queue(const device &syclDevice, const property_list &propList = {});

  explicit queue(const device &syclDevice, const async_handler &asyncHandler,
                 const property_list &propList = {});

  template <typename DeviceSelector>
  explicit queue(const context &syclContext,
                 const DeviceSelector &deviceSelector,
                 const property_list &propList = {});

  template <typename DeviceSelector>
  explicit queue(const context &syclContext,
                 const DeviceSelector &deviceSelector,
                 const async_handler &asyncHandler,
                 const property_list &propList = {});

  explicit queue(const context &syclContext, const device &syclDevice,
                 const property_list &propList = {});

  explicit queue(const context &syclContext, const device &syclDevice,
                 const async_handler &asyncHandler,
                 const property_list &propList = {});

  /* -- common interface members -- */

  /* -- property interface members -- */

  backend get_backend() const noexcept;

  context get_context() const;

  device get_device() const;

  bool is_in_order() const;

  template <typename Param> typename Param::return_type get_info() const;

  template <typename Param>
  typename Param::return_type get_backend_info() const;

  template <typename T>
  event submit(T cgf);

  template <typename T>
  event submit(T cgf, const queue &secondaryQueue);

  void wait();

  void wait_and_throw();

  void throw_asynchronous();

  /* -- convenience shortcuts -- */

  template <typename KernelName, typename KernelType>
  event single_task(const KernelType &kernelFunc);

  template <typename KernelName, typename KernelType>
  event single_task(event depEvent, const KernelType &kernelFunc);

  template <typename KernelName, typename KernelType>
  event single_task(const std::vector<event> &depEvents,
                    const KernelType &kernelFunc);

  // Parameter pack acts as-if: Reductions&&... reductions, const KernelType &kernelFunc
  template <typename KernelName, int Dims, typename... Rest>
  event parallel_for(range<Dims> numWorkItems,
                     Rest&&... rest);

  // Parameter pack acts as-if: Reductions&&... reductions, const KernelType &kernelFunc
  template <typename KernelName, int Dims, typename... Rest>
  event parallel_for(range<Dims> numWorkItems, event depEvent,
                     Rest&&... rest);

  // Parameter pack acts as-if: Reductions&&... reductions, const KernelType &kernelFunc
  template <typename KernelName, int Dims, typename... Rest>
  event parallel_for(range<Dims> numWorkItems,
                     const std::vector<event> &depEvents,
                     Rest&&... rest);

  // Parameter pack acts as-if: Reductions&&... reductions, const KernelType &kernelFunc
  template <typename KernelName, int Dims, typename... Rest>
  event parallel_for(nd_range<Dims> executionRange,
                     Rest&&... rest);

  // Parameter pack acts as-if: Reductions&&... reductions, const KernelType &kernelFunc
  template <typename KernelName, int Dims, typename... Rest>
  event parallel_for(nd_range<Dims> executionRange,
                     event depEvent,
                     Rest&&... rest);

  // Parameter pack acts as-if: Reductions&&... reductions, const KernelType &kernelFunc
  template <typename KernelName, int Dims, typename... Rest>
  event parallel_for(nd_range<Dims> executionRange,
                     const std::vector<event> &depEvents,
                     Rest&&... rest);

  /* -- USM functions -- */

  event memcpy(void* dest, const void* src, size_t numBytes);
  event memcpy(void* dest, const void* src, size_t numBytes,
               event depEvent);
  event memcpy(void* dest, const void* src, size_t numBytes,
               const std::vector<event> &depEvents);

  template <typename T>
  event copy(T* dest, const T *src, size_t count);
  template <typename T>
  event copy(T* dest, const T *src, size_t count,
             event depEvent);
  template <typename T>
  event copy(T* dest, const T *src, size_t count,
             const std::vector<event> &depEvents);

  event memset(void* ptr, int value, size_t numBytes);
  event memset(void* ptr, int value, size_t numBytes,
               event depEvent);
  event memset(void* ptr, int value, size_t numBytes,
               const std::vector<event> &depEvents);

  template <typename T>
  event fill(void* ptr, const T& pattern, size_t count);
  template <typename T>
  event fill(void* ptr, const T& pattern, size_t count,
             event depEvent);
  template <typename T>
  event fill(void* ptr, const T& pattern, size_t count,
             const std::vector<event> &depEvents);

  event prefetch(void* ptr, size_t numBytes);
  event prefetch(void* ptr, size_t numBytes,
                 event depEvent);
  event prefetch(void* ptr, size_t numBytes,
                 const std::vector<event> &depEvents);

  event mem_advise(void *ptr, size_t numBytes, int advice);
  event mem_advise(void *ptr, size_t numBytes, int advice,
                   event depEvent);
  event mem_advise(void *ptr, size_t numBytes, int advice,
                   const std::vector<event> &depEvents);

  /// Placeholder accessor shortcuts

  // Explicit copy functions

  template <typename SrcT, int SrcDims, access_mode SrcMode, target SrcTgt,
            access::placeholder IsPlaceholder, typename DestT>
  event copy(accessor<SrcT, SrcDims, SrcMode, SrcTgt, IsPlaceholder> src,
             std::shared_ptr<DestT> dest);

  template <typename SrcT, typename DestT, int DestDims,
            access_mode DestMode, target DestTgt,
            access::placeholder IsPlaceholder>
  event
  copy(std::shared_ptr<SrcT> src,
       accessor<DestT, DestDims, DestMode, DestTgt, IsPlaceholder> dest);

  template <typename SrcT, int SrcDims, access_mode SrcMode, target SrcTgt,
            access::placeholder IsPlaceholder, typename DestT>
  event copy(accessor<SrcT, SrcDims, SrcMode, SrcTgt, IsPlaceholder> src,
             DestT *dest);

  template <typename SrcT, typename DestT, int DestDims,
            access_mode DestMode, target DestTgt,
            access::placeholder IsPlaceholder>
  event
  copy(const SrcT *src,
       accessor<DestT, DestDims, DestMode, DestTgt, IsPlaceholder> dest);

  template <typename SrcT, int SrcDims, access_mode SrcMode, target SrcTgt,
            access::placeholder IsSrcPlaceholder, typename DestT,
            int DestDims, access_mode DestMode, target DestTgt,
            access::placeholder IsDestPlaceholder>
  event copy(
      accessor<SrcT, SrcDims, SrcMode, SrcTgt, IsSrcPlaceholder> src,
      accessor<DestT, DestDims, DestMode, DestTgt, IsDestPlaceholder> dest);

  template <typename T, int Dims, access_mode Mode, target Tgt,
            access::placeholder IsPlaceholder>
  event update_host(accessor<T, Dim, Mode, Tgt, IsPlaceholder> acc);

  template <typename T, int Dims, access_mode Mode, target Tgt,
            access::placeholder IsPlaceholder>
  event fill(accessor<T, Dims, Mode, Tgt, IsPlaceholder> dest, const T &src);
};
}  // namespace sycl
