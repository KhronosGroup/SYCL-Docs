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
template <typename dataT, int dimensions, access::mode accessmode,
          access::target accessTarget = access::target::global_buffer,
          access::placeholder isPlaceholder = access::placeholder::false_t>
class accessor {
 public:
  using value_type = dataT;
  using reference = dataT &;
  using const_reference = const dataT &;

  /* Available only when: accessTarget == access::target::host_image */
  template <typename AllocatorT>
  accessor(image<dimensions, AllocatorT> &imageRef,
           const property_list &propList = {});

  /* Available only when: accessTarget == access::target::image */
  template <typename AllocatorT>
  accessor(image<dimensions, AllocatorT> &imageRef,
           handler &commandGroupHandlerRef, const property_list &propList = {});

  /* Available only when: accessTarget == access::target::image_array &&
  dimensions < 3 */
  template <typename AllocatorT>
  accessor(image<dimensions + 1, AllocatorT> &imageRef,
           handler &commandGroupHandlerRef, const property_list &propList = {});

  /* -- common interface members -- */

  /* -- property interface members -- */

  size_t get_count() const;

  /* Available only when: (accessTarget !=
  access::target::image_array) */
  range<dimensions> get_range() const;

  /* Available only when: (accessTarget ==
  access::target::image_array) */
  range<dimensions+1> get_range() const;

  /* Available only when: (accessTarget == access::target::image && 
  accessMode == access::mode::read) || (accessTarget ==
  access::target::host_image && (accessMode == access::mode::read ||
  accessMode == access::mode::read_write)) */
  template <typename coordT>
  dataT read(const coordT &coords) const;

  /* Available only when: (accessTarget == access::target::image && 
  accessMode == access::mode::read) || (accessTarget ==
  access::target::host_image && (accessMode == access::mode::read ||
  accessMode == access::mode::read_write)) */
  template <typename coordT>
  dataT read(const coordT &coords, const sampler &smpl) const;

  /* Available only when: (accessTarget == access::target::image &&
  (accessMode == access::mode::write || accessMode == access::mode::discard_write)) ||
  (accessTarget == access::target::host_image && (accessMode == access::mode::write ||
  accessMode == access::mode::discard_write || accessMode == access::mode::read_write)) */
  template <typename coordT>
  void write(const coordT &coords, const dataT &color) const;

  /* Available only when: accessTarget == access::target::image_array &&
  dimensions < 3 */
  __image_array_slice__ operator[](size_t index) const
};
}  // namespace sycl
}  // namespace cl
