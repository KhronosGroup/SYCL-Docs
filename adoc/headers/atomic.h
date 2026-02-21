// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

/* Deprecated in SYCL 2020 */
template <typename T, access::address_space AddressSpace =
                          access::address_space::global_space>
class atomic {
 public:
  template <typename PointerT, access::decorated IsDecorated>
  atomic(multi_ptr<PointerT, AddressSpace, IsDecorated> ptr);

  void store(T operand, memory_order memoryOrder = memory_order::relaxed);

  T load(memory_order memoryOrder = memory_order::relaxed) const;

  T exchange(T operand, memory_order memoryOrder = memory_order::relaxed);

  /* Available only when: T != float */
  bool compare_exchange_strong(
      T& expected, T desired,
      memory_order successMemoryOrder = memory_order::relaxed,
      memory_order failMemoryOrder = memory_order::relaxed);

  /* Available only when: T != float */
  T fetch_add(T operand, memory_order memoryOrder = memory_order::relaxed);

  /* Available only when: T != float */
  T fetch_sub(T operand, memory_order memoryOrder = memory_order::relaxed);

  /* Available only when: T != float */
  T fetch_and(T operand, memory_order memoryOrder = memory_order::relaxed);

  /* Available only when: T != float */
  T fetch_or(T operand, memory_order memoryOrder = memory_order::relaxed);

  /* Available only when: T != float */
  T fetch_xor(T operand, memory_order memoryOrder = memory_order::relaxed);

  /* Available only when: T != float */
  T fetch_min(T operand, memory_order memoryOrder = memory_order::relaxed);

  /* Available only when: T != float */
  T fetch_max(T operand, memory_order memoryOrder = memory_order::relaxed);
};

} // namespace sycl
