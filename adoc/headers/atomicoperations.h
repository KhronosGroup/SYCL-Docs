// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
/* Deprecated in SYCL 2020 */
template <typename T, access::address_space AddressSpace>
void atomic_store(atomic<T, AddressSpace> object, T operand,
                  memory_order memoryOrder = memory_order::relaxed);

/* Deprecated in SYCL 2020 */
template <typename T, access::address_space AddressSpace>
T atomic_load(atomic<T, AddressSpace> object,
              memory_order memoryOrder = memory_order::relaxed);

/* Deprecated in SYCL 2020 */
template <typename T, access::address_space AddressSpace>
T atomic_exchange(atomic<T, AddressSpace> object, T operand,
                  memory_order memoryOrder = memory_order::relaxed);

/* Deprecated in SYCL 2020 */
template <typename T, access::address_space AddressSpace>
bool atomic_compare_exchange_strong(
    atomic<T, AddressSpace> object, T& expected, T desired,
    memory_order successMemoryOrder = memory_order::relaxed,
    memory_order failMemoryOrder = memory_order::relaxed);

/* Deprecated in SYCL 2020 */
template <typename T, access::address_space AddressSpace>
T atomic_fetch_add(atomic<T, AddressSpace> object, T operand,
                   memory_order memoryOrder = memory_order::relaxed);

/* Deprecated in SYCL 2020 */
template <typename T, access::address_space AddressSpace>
T atomic_fetch_sub(atomic<T, AddressSpace> object, T operand,
                   memory_order memoryOrder = memory_order::relaxed);

/* Deprecated in SYCL 2020 */
template <typename T, access::address_space AddressSpace>
T atomic_fetch_and(atomic<T, AddressSpace> object, T operand,
                   memory_order memoryOrder = memory_order::relaxed);

/* Deprecated in SYCL 2020 */
template <typename T, access::address_space AddressSpace>
T atomic_fetch_or(atomic<T, AddressSpace> object, T operand,
                  memory_order memoryOrder = memory_order::relaxed);

/* Deprecated in SYCL 2020 */
template <typename T, access::address_space AddressSpace>
T atomic_fetch_xor(atomic<T, AddressSpace> object, T operand,
                   memory_order memoryOrder = memory_order::relaxed);

/* Deprecated in SYCL 2020 */
template <typename T, access::address_space AddressSpace>
T atomic_fetch_min(atomic<T, AddressSpace> object, T operand,
                   memory_order memoryOrder = memory_order::relaxed);

/* Deprecated in SYCL 2020 */
template <typename T, access::address_space AddressSpace>
T atomic_fetch_max(atomic<T, AddressSpace> object, T operand,
                   memory_order memoryOrder = memory_order::relaxed);
} // namespace sycl
