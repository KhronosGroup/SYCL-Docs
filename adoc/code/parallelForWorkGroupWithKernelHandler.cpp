// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

myQueue.submit([&](handler& cgh) {
  // Issue 8 work-groups of 8 work-items each
  cgh.parallel_for_work_group(
      range<3>(2, 2, 2), range<3>(2, 2, 2),
      [=](group<3> myGroup, kernel_handler kh) {
        //[workgroup code]
        int myLocal;  // this variable is shared between workitems
        // this variable will be instantiated for each work-item separately
        private_memory<int> myPrivate(myGroup);

        // Issue parallel work-items.  The number issued per work-group is
        // determined by the work-group size range of parallel_for_work_group.
        // In this case, 8 work-items will execute the parallel_for_work_item
        // body for each of the 8 work-groups, resulting in 64 executions
        // globally/total.
        myGroup.parallel_for_work_item([&](h_item<3> myItem) {
          //[work-item code]
          myPrivate(myItem) = 0;
        });

        // Implicit work-group barrier

        // Carry private value across loops
        myGroup.parallel_for_work_item([&](h_item<3> myItem) {
          //[work-item code]
          output[myItem.get_global_id()] = myPrivate(myItem);
        });
        //[workgroup code]
      });
});
