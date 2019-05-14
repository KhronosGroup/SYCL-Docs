void single_task(kernel *syclKernel);

void parallel_for(nd_range<dimensions> ndRange, kernel *k);

void parallel_for(range range<dimensions> kernel *syclKernel);


template <typename KernelName, class KernelType>
void single_task(KernelType);

template <typename KernelName, class KernelType>
void parallel_for(range<dimensions> num_work_items, KernelType);


template <typename KernelName, class KernelType>
void parallel_for(range<dimensions> numWorkItems,
                  id<dimensions> workItemOffset, KernelType);

template <typename KernelName, class KernelType>
void parallel_for(nd_range<dimensions> ndRange, KernelType);

template <class KernelName, class WorkgroupFunctionType>
void parallel_for_work_group(range<dimensions> numWorkGroups,
                             WorkgroupFunctionType);

template <class KernelName, class WorkgroupFunctionType>
void parallel_for_work_group(range<dimensions> numWorkGroups,
                             range<dimensions> workGroupSize,
                             WorkgroupFunctionType);

template <class KernelType>
void single_task(KernelType);

template <class KernelType>
void parallel_for(range<dimensions> numWorkItems, KernelType);


template <class KernelType>
void parallel_for(range<dimensions> numWorkItems,
                  id<dimensions> workItemOffset, KernelType);

template <class KernelType>
void parallel_for(nd_range<dimensions> ndRange, KernelType);

template <class KernelType>
void parallel_for(nd_range<dimensions> numWorkItems,
                  id<dimensions> workItemOffset, KernelType);


template <class WorkgroupFunctionType>
void parallel_for_work_group(range<dimensions> numWorkGroups,
                             WorkgroupFunctionType);

template <class KernelName>
void parallel_for_work_group(range<dimensions> numWorkGroups,
                             range<dimensions> workGroupSize,
                             WorkgroupFunctionType);
