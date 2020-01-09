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
    auto acc = myBuffer.get_access<access::mode::write>(cgh);

    cgh.parallel_for<class myKernel>(range<1>(numWorkItems),
                                     [=] (item<1> item) {
        size_t index = item.get_linear_id();
        acc[index] = 42.0f;
    });
});
