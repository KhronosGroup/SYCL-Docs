// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

class handler {
 private:

  // implementation defined constructor
  handler(___unspecified___);

 public:

  template <typename dataT, int dimensions, access_mode accessMode,
    target accessTarget, access::placeholder isPlaceholder>
  void require(accessor<dataT, dimensions, accessMode, accessTarget,
               isPlaceholder> acc);

  void depends_on(event depEvent);

  void depends_on(const std::vector<event> &depEvents);

  //----- Backend interoperability interface
  //
  template <typename T>
  void set_arg(int argIndex, T && arg);

  template <typename... Ts>
  void set_args(Ts &&... args);

  //------ Kernel dispatch API
  //
  // Note: In all kernel dispatch functions, the template parameter
  // "typename KernelName" is optional.
  //
  template <typename KernelName, typename KernelType>
  void single_task(const KernelType &kernelFunc);

  // Parameter pack acts as-if: Reductions&&... reductions, const KernelType &kernelFunc
  template <typename KernelName, int dimensions, typename... Rest>
  void parallel_for(range<dimensions> numWorkItems,
                    Rest&&... rest);

  // Deprecated in SYCL 2020.
  template <typename KernelName, typename KernelType, int dimensions>
  void parallel_for(range<dimensions> numWorkItems,
                    id<dimensions> workItemOffset,
                    const KernelType& kernelFunc);

  // Parameter pack acts as-if: Reductions&&... reductions, const KernelType &kernelFunc
  template <typename KernelName, int dimensions, typename... Rest>
  void parallel_for(nd_range<dimensions> executionRange,
                    Rest&&... rest);

  template <typename KernelName, typename WorkgroupFunctionType, int dimensions>
  void parallel_for_work_group(range<dimensions> numWorkGroups,
                               const WorkgroupFunctionType &kernelFunc);

  template <typename KernelName, typename WorkgroupFunctionType, int dimensions>
  void parallel_for_work_group(range<dimensions> numWorkGroups,
                               range<dimensions> workGroupSize,
                               const WorkgroupFunctionType &kernelFunc);

  void single_task(const kernel &kernelObject);

  template <int dimensions>
  void parallel_for(range<dimensions> numWorkItems, const kernel &kernelObject);

  template <int dimensions>
  void parallel_for(nd_range<dimensions> ndRange, const kernel &kernelObject);

  
  //------ USM functions
  //

  void memcpy(void *dest, const void *src, size_t numBytes);

  template <typename T>
  void copy(T *dest, const T *src, size_t count);

  void memset(void *ptr, int value, size_t numBytes);

  template <typename T>
  void fill(void *ptr, const T &pattern, size_t count);

  void prefetch(void *ptr, size_t numBytes);

  void mem_advise(void *ptr, size_t numBytes, int advice);


  //------ Explicit memory operation APIs
  //
  template <typename T_src, int dim_src, access_mode mode_src, target tgt_src, access::placeholder isPlaceholder,
            typename T_dest>
  void copy(accessor<T_src, dim_src, mode_src, tgt_src, isPlaceholder> src,
            std::shared_ptr<T_dest> dest);

  template <typename T_src,
            typename T_dest, int dim_dest, access_mode mode_dest, target tgt_dest, access::placeholder isPlaceholder>
  void copy(std::shared_ptr<T_src> src,
            accessor<T_dest, dim_dest, mode_dest, tgt_dest, isPlaceholder> dest);

  template <typename T_src, int dim_src, access_mode mode_src, target tgt_src, access::placeholder isPlaceholder,
            typename T_dest>
  void copy(accessor<T_src, dim_src, mode_src, tgt_src, isPlaceholder> src,
            T_dest *dest);

  template <typename T_src,
            typename T_dest, int dim_dest, access_mode mode_dest, target tgt_dest, access::placeholder isPlaceholder>
  void copy(const T_src *src,
            accessor<T_dest, dim_dest, mode_dest, tgt_dest, isPlaceholder> dest);

  template <typename T_src, int dim_src, access_mode mode_src, target tgt_src, access::placeholder isPlaceholder_src,
            typename T_dest, int dim_dest, access_mode mode_dest, target tgt_dest, access::placeholder isPlaceholder_dest>
  void copy(accessor<T_src, dim_src, mode_src, tgt_src, isPlaceholder_src> src,
            accessor<T_dest, dim_dest, mode_dest, tgt_dest, isPlaceholder_dest> dest);

  template <typename T, int dim, access_mode mode, target tgt, access::placeholder isPlaceholder>
  void update_host(accessor<T, dim, mode, tgt, isPlaceholder> acc);

  template <typename T, int dim, access_mode mode, target tgt, access::placeholder isPlaceholder>
  void fill(accessor<T, dim, mode, tgt, isPlaceholder> dest, const T& src);

  void use_kernel_bundle(const kernel_bundle<bundle_state::executable> &execBundle);

  template<auto& S>
  typename std::remove_reference_t<decltype(S)>::type get_specialization_constant();

};
}  // namespace sycl
