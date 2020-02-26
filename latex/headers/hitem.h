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
template <int dimensions>
class h_item {
public:
  h_item() = delete;

  /* -- common interface members -- */

  item<dimensions, false> get_global() const;

  item<dimensions, false> get_local() const;

  item<dimensions, false> get_logical_local() const;

  item<dimensions, false> get_physical_local() const;

  range<dimensions> get_global_range() const;

  size_t get_global_range(int dimension) const;

  id<dimensions> get_global_id() const;

  size_t get_global_id(int dimension) const;

  range<dimensions> get_local_range() const;

  size_t get_local_range(int dimension) const;

  id<dimensions> get_local_id() const;

  size_t get_local_id(int dimension) const;

  range<dimensions> get_logical_local_range() const;

  size_t get_logical_local_range(int dimension) const;

  id<dimensions> get_logical_local_id() const;

  size_t get_logical_local_id(int dimension) const;

  range<dimensions> get_physical_local_range() const;

  size_t get_physical_local_range(int dimension) const;

  id<dimensions> get_physical_local_id() const;

  size_t get_physical_local_id(int dimension) const;

};
}  // namespace sycl
}  // namespace cl
