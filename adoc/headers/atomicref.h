// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

// Exposition only
template <memory_order ReadModifyWriteOrder> struct memory_order_traits;

template <> struct memory_order_traits<memory_order::relaxed> {
  static constexpr memory_order read_order = memory_order::relaxed;
  static constexpr memory_order write_order = memory_order::relaxed;
};

template <> struct memory_order_traits<memory_order::acq_rel> {
  static constexpr memory_order read_order = memory_order::acquire;
  static constexpr memory_order write_order = memory_order::release;
};

template <> struct memory_order_traits<memory_order::seq_cst> {
  static constexpr memory_order read_order = memory_order::seq_cst;
  static constexpr memory_order write_order = memory_order::seq_cst;
};

template <typename T, memory_order DefaultOrder, memory_scope DefaultScope,
          access::address_space AddressSpace = access::address_space::generic_space>
class atomic_ref {
 public:
  using value_type = T;
  static constexpr size_t required_alignment = /* implementation-defined */;
  static constexpr bool is_always_lock_free = /* implementation-defined */;
  static constexpr memory_order default_read_order =
      memory_order_traits<DefaultOrder>::read_order;
  static constexpr memory_order default_write_order =
      memory_order_traits<DefaultOrder>::write_order;
  static constexpr memory_order default_read_modify_write_order = DefaultOrder;
  static constexpr memory_scope default_scope = DefaultScope;

  bool is_lock_free() const noexcept;

  explicit atomic_ref(T&);
  atomic_ref(const atomic_ref&) noexcept;
  atomic_ref& operator=(const atomic_ref&) = delete;

  void store(T operand, memory_order order = default_write_order,
             memory_scope scope = default_scope) const noexcept;

  T operator=(T desired) const noexcept;

  T load(memory_order order = default_read_order,
         memory_scope scope = default_scope) const noexcept;

  operator T() const noexcept;

  T exchange(T operand, memory_order order = default_read_modify_write_order,
             memory_scope scope = default_scope) const noexcept;

  bool compare_exchange_weak(T& expected, T desired, memory_order success,
                             memory_order failure,
                             memory_scope scope = default_scope) const noexcept;

  bool
  compare_exchange_weak(T& expected, T desired,
                        memory_order order = default_read_modify_write_order,
                        memory_scope scope = default_scope) const noexcept;

  bool
  compare_exchange_strong(T& expected, T desired, memory_order success,
                          memory_order failure,
                          memory_scope scope = default_scope) const noexcept;

  bool
  compare_exchange_strong(T& expected, T desired,
                          memory_order order = default_read_modify_write_order,
                          memory_scope scope = default_scope) const noexcept;
};

// Partial specialization for integral types
template <memory_order DefaultOrder, memory_scope DefaultScope,
          access::address_space AddressSpace = access::address_space::generic_space>
class atomic_ref<Integral, DefaultOrder, DefaultScope, AddressSpace> {

  /* All other members from atomic_ref<T> are available */

  using difference_type = value_type;

  Integral fetch_add(Integral operand,
                     memory_order order = default_read_modify_write_order,
                     memory_scope scope = default_scope) const noexcept;

  Integral fetch_sub(Integral operand,
                     memory_order order = default_read_modify_write_order,
                     memory_scope scope = default_scope) const noexcept;

  Integral fetch_and(Integral operand,
                     memory_order order = default_read_modify_write_order,
                     memory_scope scope = default_scope) const noexcept;

  Integral fetch_or(Integral operand,
                    memory_order order = default_read_modify_write_order,
                    memory_scope scope = default_scope) const noexcept;

  Integral fetch_xor(Integral operand,
                     memory_order order = default_read_modify_write_order,
                     memory_scope scope = default_scope) const noexcept;

  Integral fetch_min(Integral operand,
                     memory_order order = default_read_modify_write_order,
                     memory_scope scope = default_scope) const noexcept;

  Integral fetch_max(Integral operand,
                     memory_order order = default_read_modify_write_order,
                     memory_scope scope = default_scope) const noexcept;

  Integral operator++(int) const noexcept;
  Integral operator--(int) const noexcept;
  Integral operator++() const noexcept;
  Integral operator--() const noexcept;
  Integral operator+=(Integral) const noexcept;
  Integral operator-=(Integral) const noexcept;
  Integral operator&=(Integral) const noexcept;
  Integral operator|=(Integral) const noexcept;
  Integral operator^=(Integral) const noexcept;
};

// Partial specialization for floating-point types
template <memory_order DefaultOrder, memory_scope DefaultScope,
          access::address_space AddressSpace = access::address_space::generic_space>
class atomic_ref<Floating, DefaultOrder, DefaultScope, AddressSpace> {

  /* All other members from atomic_ref<T> are available */

  using difference_type = value_type;

  Floating fetch_add(Floating operand,
                     memory_order order = default_read_modify_write_order,
                     memory_scope scope = default_scope) const noexcept;

  Floating fetch_sub(Floating operand,
                     memory_order order = default_read_modify_write_order,
                     memory_scope scope = default_scope) const noexcept;

  Floating fetch_min(Floating operand,
                     memory_order order = default_read_modify_write_order,
                     memory_scope scope = default_scope) const noexcept;

  Floating fetch_max(Floating operand,
                     memory_order order = default_read_modify_write_order,
                     memory_scope scope = default_scope) const noexcept;

  Floating operator+=(Floating) const noexcept;
  Floating operator-=(Floating) const noexcept;
};

// Partial specialization for pointers
template <typename T, memory_order DefaultOrder, memory_scope DefaultScope,
          access::address_space AddressSpace = access::address_space::generic_space>
class atomic_ref<T*, DefaultOrder, DefaultScope, AddressSpace> {

  using value_type = T*;
  using difference_type = ptrdiff_t;
  static constexpr size_t required_alignment = /* implementation-defined */;
  static constexpr bool is_always_lock_free = /* implementation-defined */;
  static constexpr memory_order default_read_order =
      memory_order_traits<DefaultOrder>::read_order;
  static constexpr memory_order default_write_order =
      memory_order_traits<DefaultOrder>::write_order;
  static constexpr memory_order default_read_modify_write_order = DefaultOrder;
  static constexpr memory_scope default_scope = DefaultScope;

  bool is_lock_free() const noexcept;

  explicit atomic_ref(T*&);
  atomic_ref(const atomic_ref&) noexcept;
  atomic_ref& operator=(const atomic_ref&) = delete;

  void store(T* operand, memory_order order = default_write_order,
             memory_scope scope = default_scope) const noexcept;

  T* operator=(T* desired) const noexcept;

  T* load(memory_order order = default_read_order,
          memory_scope scope = default_scope) const noexcept;

  operator T*() const noexcept;

  T* exchange(T* operand, memory_order order = default_read_modify_write_order,
              memory_scope scope = default_scope) const noexcept;

  bool compare_exchange_weak(T*& expected, T* desired, memory_order success,
                             memory_order failure,
                             memory_scope scope = default_scope) const noexcept;

  bool
  compare_exchange_weak(T*& expected, T* desired,
                        memory_order order = default_read_modify_write_order,
                        memory_scope scope = default_scope) const noexcept;

  bool
  compare_exchange_strong(T*& expected, T* desired, memory_order success,
                          memory_order failure,
                          memory_scope scope = default_scope) const noexcept;

  bool
  compare_exchange_strong(T*& expected, T* desired,
                          memory_order order = default_read_modify_write_order,
                          memory_scope scope = default_scope) const noexcept;

  T* fetch_add(difference_type,
               memory_order order = default_read_modify_write_order,
               memory_scope scope = default_scope) const noexcept;

  T* fetch_sub(difference_type,
               memory_order order = default_read_modify_write_order,
               memory_scope scope = default_scope) const noexcept;

  T* operator++(int) const noexcept;
  T* operator--(int) const noexcept;
  T* operator++() const noexcept;
  T* operator--() const noexcept;
  T* operator+=(difference_type) const noexcept;
  T* operator-=(difference_type) const noexcept;
};

} // namespace sycl
