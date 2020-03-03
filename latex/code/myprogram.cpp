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

class MyKernel;  // Forward declaration of the name of the lambda functor

cl::sycl::queue myQueue;
cl::sycl::program myProgram(myQueue.get_context());

/* use the name of the kernel to obtain the associated program */
myProgram.build_from_name<MyKernel>();

myQueue.submit([&](handler& commandGroup) {
  commandgroup.parallel_for<class MyKernel>(
      cl::sycl::nd_range<2>(range<2>(4, 4),range<2>(1,1)),
      MyProgram.get_kernel<MyKernel>(),  // execute the kernel as compiled in MyProgram
      ([=](cl::sycl::nd_item<2> index) {
        //[kernel code]
      }));
});
