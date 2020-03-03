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
class device_selector {
 public:
  device_selector();

  device_selector(const device_selector &rhs);

  device_selector &operator=(const device_selector &rhs);

  virtual ~device_selector();

  device select_device() const;

  virtual int operator()(const device &device) const = 0;
};
}  // namespace sycl
}  // namespace cl
