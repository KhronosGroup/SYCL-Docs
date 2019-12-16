// Copyright (c) 2012-2020 The Khronos Group Inc.
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
  // Issue 8 work-groups of 8 work-items each
  cgh.parallel_for_work_group<class example_kernel>(
      range<3>(2, 2, 2), range<3>(2, 2, 2), [=](group<3> myGroup) {

    //[workgroup code]
    int myLocal;  // this variable is shared between workitems
    // this variable will be instantiated for each work-item separately
    private_memory<int> myPrivate(myGroup);

    // Issue parallel work-items.  The number issued per work-group is determined
    // by the work-group size range of parallel_for_work_group.  In this case,
    // 8 work-items will execute the parallel_for_work_item body for each of the
    // 8 work-groups, resulting in 64 executions globally/total.
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
