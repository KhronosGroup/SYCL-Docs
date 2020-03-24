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

namespace cl {
namespace sycl {
class context {
 public:
  explicit context(const property_list &propList = {});

  context(async_handler asyncHandler,
          const property_list &propList = {});

  context(const device &dev, const property_list &propList = {});

  context(const device &dev, async_handler asyncHandler,
          const property_list &propList = {});

  context(const platform &plt, const property_list &propList = {});

  context(const platform &plt, async_handler asyncHandler,
          const property_list &propList = {});

  context(const vector_class<device> &deviceList,
          const property_list &propList = {});

  context(const vector_class<device> &deviceList,
          async_handler asyncHandler, const property_list &propList = {});

  context(cl_context clContext, async_handler asyncHandler = {});

  /* -- common interface members -- */

  /* -- property interface members -- */

  cl_context get() const;

  bool is_host() const;

  platform get_platform() const;

  vector_class<device> get_devices() const;

  template <info::context param>
  typename info::param_traits<info::context, param>::return_type get_info() const;
};
}  // namespace sycl
}  // namespace cl
