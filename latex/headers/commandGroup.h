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
class command_group {
 public:
  template <typename functorT>
  command_group(queue &primaryQueue, const functorT &lambda);

  template <typename functorT>
  command_group(queue &primaryQueue, queue &secondaryQueue,
                const functorT &lambda);

  ~command_group();

  event start_event();

  event kernel_event();

  event complete_event();
};
}  // namespace sycl
}  // namespace cl
