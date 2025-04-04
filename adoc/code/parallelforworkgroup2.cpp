// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

myQueue.submit([&](handler& cgh) {
  // Issue 8 work-groups.  The work-group size is chosen by the runtime because
  // unspecified
  cgh.parallel_for_work_group(range<3>(2, 2, 2), [=](group<3> myGroup) {
    // Launch a set of work-items for each work-group.  The number of work-items
    // is chosen by the runtime because the work-group size was not specified to
    // parallel_for_work_group and a logical range is not specified to
    // parallel_for_work_item.
    myGroup.parallel_for_work_item([=](h_item<3> myItem) {
      //[work-item code]
    });

    // Implicit work-group barrier

    // Launch 512 logical work-items that will be executed by the underlying
    // work-group size chosen by the runtime.  myItem allows the logical and
    // physical work-item IDs to be queried.  512 logical work-items will
    // execute for each work-group, and the parallel_for body will therefore be
    // executed 8*512 = 4096 times globally/total.
    myGroup.parallel_for_work_item(range<3>(8, 8, 8), [=](h_item<3> myItem) {
      //[work-item code]
    });
    //[workgroup code]
  });
});
