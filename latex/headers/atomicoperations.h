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
template <typename T, access::address_space addressSpace>
void atomic_store(atomic<T, addressSpace> object, T operand, memory_order memoryOrder =
  memory_order::relaxed);

template <typename T, access::address_space addressSpace>
T atomic_load(atomic<T, addressSpace> object, memory_order memoryOrder =
  memory_order::relaxed);

template <typename T, access::address_space addressSpace>
T atomic_exchange(atomic<T, addressSpace> object, T operand, memory_order memoryOrder =
  memory_order::relaxed);

template <typename T, access::address_space addressSpace>
bool atomic_compare_exchange_strong(atomic<T, addressSpace> object, T &expected, T desired,
    memory_order successMemoryOrder = memory_order::relaxed,
    memory_order failMemoryOrder = memory_order::relaxed);

template <typename T, access::address_space addressSpace>
T atomic_fetch_add(atomic<T, addressSpace> object, T operand, memory_order memoryOrder =
    memory_order::relaxed);

template <typename T, access::address_space addressSpace>
T atomic_fetch_sub(atomic<T, addressSpace> object, T operand, memory_order memoryOrder =
  memory_order::relaxed);

template <typename T, access::address_space addressSpace>
T atomic_fetch_and(atomic<T, addressSpace> object, T operand, memory_order memoryOrder =
  memory_order::relaxed);

template <typename T, access::address_space addressSpace>
T atomic_fetch_or(atomic<T, addressSpace> object, T operand, memory_order memoryOrder =
  memory_order::relaxed);

template <typename T, access::address_space addressSpace>
T atomic_fetch_xor(atomic<T, addressSpace> object, T operand, memory_order memoryOrder =
  memory_order::relaxed);

template <typename T, access::address_space addressSpace>
T atomic_fetch_min(atomic<T, addressSpace> object, T operand, memory_order memoryOrder =
  memory_order::relaxed);

template <typename T, access::address_space addressSpace>
T atomic_fetch_max(atomic<T, addressSpace> object, T operand, memory_order memoryOrder =
  memory_order::relaxed);
}  // namespace sycl
}  // namespace cl
