// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

class handler {
 private:
  // implementation defined constructor
  handler(___unspecified___);

 public:
  template <typename DataT, int Dimensions, access_mode AccessMode,
            target AccessTarget, access::placeholder IsPlaceholder>
  void require(
      accessor<DataT, Dimensions, AccessMode, AccessTarget, IsPlaceholder> acc);

  void depends_on(event depEvent);

  void depends_on(const std::vector<event>& depEvents);

  //----- Backend interoperability interface
  //
  template <typename T> void set_arg(int argIndex, T&& arg);

  template <typename... Ts> void set_args(Ts&&... args);

  //------ Kernel dispatch API
  //
  // Note: In all kernel dispatch functions, the template parameter
  // "typename KernelName" is optional.
  //
  template <typename KernelName, typename KernelType>
  void single_task(const KernelType& kernelFunc);

  // Parameter pack acts as-if: Reductions&&... reductions, const KernelType
  // &kernelFunc
  template <typename KernelName, int Dimensions, typename... Rest>
  void parallel_for(range<Dimensions> numWorkItems, Rest&&... rest);

  // Deprecated in SYCL 2020.
  template <typename KernelName, typename KernelType, int Dimensions>
  void parallel_for(range<Dimensions> numWorkItems,
                    id<Dimensions> workItemOffset,
                    const KernelType& kernelFunc);

  // Parameter pack acts as-if: Reductions&&... reductions, const KernelType
  // &kernelFunc
  template <typename KernelName, int Dimensions, typename... Rest>
  void parallel_for(nd_range<Dimensions> executionRange, Rest&&... rest);

  // Deprecated in SYCL 2020.
  template <typename KernelName, typename WorkgroupFunctionType, int Dimensions>
  void parallel_for_work_group(range<Dimensions> numWorkGroups,
                               const WorkgroupFunctionType& kernelFunc);

  // Deprecated in SYCL 2020.
  template <typename KernelName, typename WorkgroupFunctionType, int Dimensions>
  void parallel_for_work_group(range<Dimensions> numWorkGroups,
                               range<Dimensions> workGroupSize,
                               const WorkgroupFunctionType& kernelFunc);

  void single_task(const kernel& kernelObject);

  template <int Dimensions>
  void parallel_for(range<Dimensions> numWorkItems, const kernel& kernelObject);

  template <int Dimensions>
  void parallel_for(nd_range<Dimensions> ndRange, const kernel& kernelObject);

  //------ USM functions
  //

  void memcpy(void* dest, const void* src, size_t numBytes);

  template <typename T> void copy(const T* src, T* dest, size_t count);

  void memset(void* ptr, int value, size_t numBytes);

  template <typename T> void fill(void* ptr, const T& pattern, size_t count);

  void prefetch(void* ptr, size_t numBytes);

  void mem_advise(void* ptr, size_t numBytes, int advice);

  //------ Explicit memory operation APIs
  //
  template <typename SrcT, int SrcDim, access_mode SrcMode, target SrcTgt,
            access::placeholder IsPlaceholder, typename DestT>
  void copy(accessor<SrcT, SrcDim, SrcMode, SrcTgt, IsPlaceholder> src,
            std::shared_ptr<DestT> dest);

  template <typename SrcT, typename DestT, int DestDim, access_mode DestMode,
            target DestTgt, access::placeholder IsPlaceholder>
  void copy(std::shared_ptr<SrcT> src,
            accessor<DestT, DestDim, DestMode, DestTgt, IsPlaceholder> dest);

  template <typename SrcT, int SrcDim, access_mode SrcMode, target SrcTgt,
            access::placeholder IsPlaceholder, typename DestT>
  void copy(accessor<SrcT, SrcDim, SrcMode, SrcTgt, IsPlaceholder> src,
            DestT* dest);

  template <typename SrcT, typename DestT, int DestDim, access_mode DestMode,
            target DestTgt, access::placeholder IsPlaceholder>
  void copy(const SrcT* src,
            accessor<DestT, DestDim, DestMode, DestTgt, IsPlaceholder> dest);

  template <typename SrcT, int SrcDim, access_mode SrcMode, target SrcTgt,
            access::placeholder SrcIsPlaceholder, typename DestT, int DestDim,
            access_mode DestMode, target DestTgt,
            access::placeholder DestIsPlaceholder>
  void
  copy(accessor<SrcT, SrcDim, SrcMode, SrcTgt, SrcIsPlaceholder> src,
       accessor<DestT, DestDim, DestMode, DestTgt, DestIsPlaceholder> dest);

  template <typename T, int Dim, access_mode Mode, target Tgt,
            access::placeholder IsPlaceholder>
  void update_host(accessor<T, Dim, Mode, Tgt, IsPlaceholder> acc);

  template <typename T, int Dim, access_mode Mode, target Tgt,
            access::placeholder IsPlaceholder>
  void fill(accessor<T, Dim, Mode, Tgt, IsPlaceholder> dest, const T& src);

  void
  use_kernel_bundle(const kernel_bundle<bundle_state::executable>& execBundle);

  template <auto& SpecName>
  void set_specialization_constant(
      typename std::remove_reference_t<decltype(SpecName)>::value_type value);

  template <auto& SpecName>
  typename std::remove_reference_t<decltype(SpecName)>::value_type
  get_specialization_constant();
};
} // namespace sycl
