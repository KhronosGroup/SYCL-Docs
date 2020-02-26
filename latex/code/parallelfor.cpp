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
 cgh.parallel_for<class example_kernel1>(
    range<3>(3,3,3), // global range
      [=] (item<3> it) {
        //[kernel code]
      });
});
myQueue.submit([&](handler & cgh) {
 cgh.parallel_for<class example_kernel2>(
    range<3>(3,3,3), // global range
    id<3>(1,1,1), // offset
      [=] (item<3> it) {
        //[kernel code]
      });
});
