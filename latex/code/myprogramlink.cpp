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

class MyKernel;  // Forward declaration of the name of the lambda functor

cl::sycl::queue myQueue;

// obtain an existing OpenCL C program object
cl_program myClProgram = ...;

// Create a SYCL program object from a cl_program object
cl::sycl::program myExternProgram(myQueue.get_context(), myClProgram);

// Release the program if we no longer need it as
// SYCL program retained a reference to it
clReleaseProgram(myClProgram);

// Add in the SYCL program object for our kernel
cl::sycl::program mySyclProgram(myQueue.get_context());
mySyclProgram.compile_with_kernel_type<MyKernel>("-my-compile-options");

// Link myClProgram with the SYCL program object
mySyclProgram.link(myExternProgram,"-my-link-options");

myQueue.submit([&](handler& commandgroup) {
  commandgroup.parallel_for<class MyKernel>(
      cl::sycl::range<2>(4, 4),
      myLinkedProgram.get_kernel<MyKernel>(),  // execute the kernel as compiled in MyProgram
      ([=](cl::sycl::item<2> index) {
        //[kernel code]
      }));
});
