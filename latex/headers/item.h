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
template <int dimensions = 1, bool with_offset = true>
class item {
public:
  item() = delete;

   /* -- common interface members -- */

  id<dimensions> get_id() const;

  size_t get_id(int dimension) const;

  size_t operator[](int dimension) const;

  range<dimensions> get_range() const;

  size_t get_range(int dimension) const;

  // only available if with_offset is true
  id<dimensions> get_offset() const;

  // only available if with_offset is false
  operator item<dimensions, true>() const;

  size_t get_linear_id() const;
};
}  // namespace sycl
}  // namespace cl
