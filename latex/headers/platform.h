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
class platform {
 public:
  platform();

  explicit platform(cl_platform_id platformID);

  explicit platform(const device_selector &deviceSelector);

  /* -- common interface members -- */

  cl_platform_id get() const;

  vector_class<device> get_devices(
    info::device_type = info::device_type::all) const;

  template <info::platform param>
  typename info::param_traits<info::platform, param>::return_type get_info() const;

  bool has_extension(const string_class &extension) const;

  bool is_host() const;

  static vector_class<platform> get_platforms();
};
}  // namespace sycl
}  // namespace cl
