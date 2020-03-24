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

  /* Available only when: ((isPlaceholder == access::placeholder::false_t &&
  accessTarget == access::target::host_buffer) || (isPlaceholder ==
  access::placeholder::true_t && (accessTarget == access::target::global_buffer
  || accessTarget == access::target::constant_buffer))) && dimensions == 0 */
  template <typename AllocatorT>
  accessor(buffer<dataT, 1, AllocatorT> &bufferRef,
           const property_list &propList = {});

  /* Available only when: (isPlaceholder == access::placeholder::false_t &&
  (accessTarget == access::target::global_buffer || accessTarget ==
  access::target::constant_buffer)) && dimensions == 0 */
  template <typename AllocatorT>
  accessor(buffer<dataT, 1, AllocatorT> &bufferRef,
           handler &commandGroupHandlerRef, const property_list &propList = {});

  /* Available only when: ((isPlaceholder == access::placeholder::false_t &&
  accessTarget == access::target::host_buffer) || (isPlaceholder ==
  access::placeholder::true_t && (accessTarget == access::target::global_buffer
  || accessTarget == access::target::constant_buffer))) && dimensions > 0 */
  template <typename AllocatorT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           const property_list &propList = {});

  /* Available only when: (isPlaceholder == access::placeholder::false_t &&
  (accessTarget == access::target::global_buffer || accessTarget ==
  access::target::constant_buffer)) && dimensions > 0 */
  template <typename AllocatorT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           handler &commandGroupHandlerRef, const property_list &propList = {});

  /* Available only when: (isPlaceholder == access::placeholder::false_t &&
  accessTarget == access::target::host_buffer) || (isPlaceholder ==
  access::placeholder::true_t && (accessTarget == access::target::global_buffer
  || accessTarget == access::target::constant_buffer)) && dimensions > 0 */
  template <typename AllocatorT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           range<dimensions> accessRange, const property_list &propList = {});

  /* Available only when: (isPlaceholder == access::placeholder::false_t &&
  accessTarget == access::target::host_buffer) || (isPlaceholder ==
  access::placeholder::true_t && (accessTarget == access::target::global_buffer
  || accessTarget == access::target::constant_buffer)) && dimensions > 0 */
  template <typename AllocatorT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           range<dimensions> accessRange, id<dimensions> accessOffset,
           const property_list &propList = {});

  /* Available only when: (isPlaceholder == access::placeholder::false_t &&
  (accessTarget == access::target::global_buffer || accessTarget ==
  access::target::constant_buffer)) && dimensions > 0 */
  template <typename AllocatorT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           handler &commandGroupHandlerRef, range<dimensions> accessRange,
           const property_list &propList = {});

  /* Available only when: (isPlaceholder == access::placeholder::false_t &&
  (accessTarget == access::target::global_buffer || accessTarget ==
  access::target::constant_buffer)) && dimensions > 0 */
  template <typename AllocatorT>
  accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef,
           handler &commandGroupHandlerRef, range<dimensions> accessRange,
           id<dimensions> accessOffset, const property_list &propList = {});

  /* -- common interface members -- */

  /* -- property interface members -- */

  constexpr bool is_placeholder() const;

  size_t get_size() const;

  size_t get_count() const;

  /* Available only when: dimensions > 0 */
  range<dimensions> get_range() const;

  /* Available only when: dimensions > 0 */
  id<dimensions> get_offset() const;

  /* Available only when: (accessMode == access::mode::write || accessMode ==
  access::mode::read_write || accessMode == access::mode::discard_write ||
  accessMode == access::mode::discard_read_write) && dimensions == 0) */
  operator dataT &() const;

  /* Available only when: (accessMode == access::mode::write || accessMode ==
  access::mode::read_write || accessMode == access::mode::discard_write ||
  accessMode == access::mode::discard_read_write) && dimensions > 0) */
  dataT &operator[](id<dimensions> index) const;

  /* Available only when: (accessMode == access::mode::write || accessMode ==
  access::mode::read_write || accessMode == access::mode::discard_write ||
  accessMode == access::mode::discard_read_write) && dimensions == 1) */
  dataT &operator[](size_t index) const;

  /* Available only when: accessMode == access::mode::read && dimensions == 0 */
  operator dataT() const;

  /* Available only when: accessMode == access::mode::read && dimensions > 0 */
  dataT operator[](id<dimensions> index) const;

  /* Available only when: accessMode == access::mode::read && dimensions == 1 */
  dataT operator[](size_t index) const;

  /* Available only when: accessMode == access::mode::atomic && dimensions ==
  0 */
  operator atomic<dataT, access::address_space::global_space> () const;

  /* Available only when: accessMode == access::mode::atomic && dimensions >
  0 */
  atomic<dataT, access::address_space::global_space> operator[](
    id<dimensions> index) const;

  /* Available only when: accessMode == access::mode::atomic && dimensions ==
  1 */
  atomic<dataT, access::address_space::global_space> operator[](
    size_t index) const;

  /* Available only when: dimensions > 1 */
  __unspecified__ &operator[](size_t index) const;

  /* Available only when: accessTarget == access::target::host_buffer */
  dataT *get_pointer() const;

  /* Available only when: accessTarget == access::target::global_buffer */
  global_ptr<dataT> get_pointer() const;

  /* Available only when: accessTarget == access::target::constant_buffer */
  constant_ptr<dataT> get_pointer() const;
};
}  // namespace sycl
}  // namespace cl
