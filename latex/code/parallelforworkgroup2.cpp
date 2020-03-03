// Copyright (c) 2011-2020 The Khronos Group, Inc.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

myQueue.submit([&](handler & cgh) {
  // Issue 8 work-groups.  The work-group size is chosen by the runtime because unspecified
  cgh.parallel_for_work_group<class example_kernel>(
      range<3>(2, 2, 2), [=](group<3> myGroup) {

    // Launch a set of work-items for each work-group.  The number of work-items is chosen
    // by the runtime because the work-group size was not specified to parallel_for_work_group
    // and a logical range is not specified to parallel_for_work_item.
    myGroup.parallel_for_work_item([=](h_item<3> myItem) {
      //[work-item code]
    });

    // Implicit work-group barrier

    // Launch 512 logical work-items that will be executed by the underlying work-group size
    // chosen by the runtime.  myItem allows the logical and physical work-item IDs to be
    // queried.  512 logical work-items will execute for each work-group, and the parallel_for
    // body will therefore be executed 8*512 = 4096 times globally/total.
    myGroup.parallel_for_work_item(range<3>(8, 8, 8), [=](h_item<3> myItem) {
      //[work-item code]
    });
    //[workgroup code]
  });
});
