// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

void single_task(kernel* syclKernel);

void parallel_for(nd_range<Dimensions> ndRange, kernel* k);

void parallel_for(range range<Dimensions> kernel* syclKernel);

template <typename KernelName, class KernelType> void single_task(KernelType);

template <typename KernelName, class KernelType>
void parallel_for(range<Dimensions> num_work_items, KernelType);

// Deprecated in SYCL 2020.
template <typename KernelName, class KernelType>
void parallel_for(range<Dimensions> numWorkItems, id<Dimensions> workItemOffset,
                  KernelType);

template <typename KernelName, class KernelType>
void parallel_for(nd_range<Dimensions> ndRange, KernelType);

template <class KernelName, class WorkgroupFunctionType>
void parallel_for_work_group(range<Dimensions> numWorkGroups,
                             WorkgroupFunctionType);

template <class KernelName, class WorkgroupFunctionType>
void parallel_for_work_group(range<Dimensions> numWorkGroups,
                             range<Dimensions> workGroupSize,
                             WorkgroupFunctionType);

template <class KernelType> void single_task(KernelType);

template <class KernelType>
void parallel_for(range<Dimensions> numWorkItems, KernelType);

// Deprecated in SYCL 2020.
template <class KernelType>
void parallel_for(range<Dimensions> numWorkItems, id<Dimensions> workItemOffset,
                  KernelType);

template <class KernelType>
void parallel_for(nd_range<Dimensions> ndRange, KernelType);

// Deprecated in SYCL 2020.
template <class KernelType>
void parallel_for(nd_range<Dimensions> numWorkItems,
                  id<Dimensions> workItemOffset, KernelType);

template <class WorkgroupFunctionType>
void parallel_for_work_group(range<Dimensions> numWorkGroups,
                             WorkgroupFunctionType);

template <class KernelName>
void parallel_for_work_group(range<Dimensions> numWorkGroups,
                             range<Dimensions> workGroupSize,
                             WorkgroupFunctionType);
