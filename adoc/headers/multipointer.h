// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
namespace access {

enum class address_space : /* unspecified */ {
  global_space,
  local_space,
  constant_space, // Deprecated in SYCL 2020
  private_space,
  generic_space
};

enum class decorated : /* unspecified */ {
  no,
  yes,
  legacy
};

}  // namespace access

template<typename T> struct remove_decoration {
  using type = /* ... */;
};

template<typename T>
using remove_decoration_t = remove_decoration<T>::type;

template <typename ElementType, access::address_space Space, access::decorated DecorateAddress>
class multi_ptr {
 public:
  static constexpr bool is_decorated = DecorateAddress == access::decorated::yes;
  static constexpr access::address_space address_space = Space;

  using value_type = ElementType;
  using pointer = std::conditional_t<is_decorated, __unspecified__ *,
                                     std::add_pointer_t<value_type>>;
  using reference = std::conditional_t<is_decorated, __unspecified__ &,
                                       std::add_lvalue_reference_t<value_type>>;
  using iterator_category = std::random_access_iterator_tag;
  using difference_type = std::ptrdiff_t;

  static_assert(std::is_same_v<remove_decoration_t<pointer>, std::add_pointer_t<value_type>>);
  static_assert(std::is_same_v<remove_decoration_t<reference>, std::add_lvalue_reference_t<value_type>>);
  // Legacy has a different interface.
  static_assert(DecorateAddress != access::decorated::legacy);

  // Constructors
  multi_ptr();
  multi_ptr(const multi_ptr&);
  multi_ptr(multi_ptr&&);
  explicit multi_ptr(typename multi_ptr<ElementType, Space, access::decorated::yes>::pointer);
  multi_ptr(std::nullptr_t);

  // Only if Space == global_space or generic_space
  template <int Dimensions, access_mode Mode, access::placeholder IsPlaceholder>
  multi_ptr(accessor<value_type, Dimensions, Mode, target::device, IsPlaceholder>);

  // Only if Space == local_space or generic_space
  template <int Dimensions>
  multi_ptr(local_accessor<ElementType, Dimensions>);

  // Deprecated
  // Only if Space == local_space or generic_space
  template <int Dimensions, access_mode Mode, access::placeholder IsPlaceholder>
  multi_ptr(accessor<value_type, Dimensions, Mode, target::local, IsPlaceholder>);

  // Assignment and access operators
  multi_ptr &operator=(const multi_ptr&);
  multi_ptr &operator=(multi_ptr&&);
  multi_ptr &operator=(std::nullptr_t);

  // Only if Space == address_space::generic_space
  // and AS != access::address_space::constant_space
  template<access::address_space AS, access::decorated IsDecorated>
  multi_ptr &operator=(const multi_ptr<value_type, AS, IsDecorated>&);
  // Only if Space == address_space::generic_space
  // and AS != access::address_space::constant_space
  template<access::address_space AS, access::decorated IsDecorated>
  multi_ptr &operator=(multi_ptr<value_type, AS, IsDecorated>&&);

  reference operator[](std::ptrdiff_t) const;

  reference operator*() const;
  pointer operator->() const;

  pointer get() const;
  std::add_pointer_t<value_type> get_raw() const;
  __unspecified__ * get_decorated() const;

  // Conversion to the underlying pointer type
  // Deprecated, get() should be used instead.
  operator pointer() const;

  // Only if Space == address_space::generic_space
  // Cast to private_ptr
  explicit operator multi_ptr<value_type, access::address_space::private_space,
                              DecorateAddress>();
  // Only if Space == address_space::generic_space
  // Cast to private_ptr
  explicit
  operator multi_ptr<const value_type, access::address_space::private_space,
                     DecorateAddress>() const;
  // Only if Space == address_space::generic_space
  // Cast to global_ptr
  explicit operator multi_ptr<value_type, access::address_space::global_space,
                              DecorateAddress>();
  // Only if Space == address_space::generic_space
  // Cast to global_ptr
  explicit
  operator multi_ptr<const value_type, access::address_space::global_space,
                     DecorateAddress>() const;
  // Only if Space == address_space::generic_space
  // Cast to local_ptr
  explicit operator multi_ptr<value_type, access::address_space::local_space,
                              DecorateAddress>();
  // Only if Space == address_space::generic_space
  // Cast to local_ptr
  explicit
  operator multi_ptr<const value_type, access::address_space::local_space,
                     DecorateAddress>() const;

  // Implicit conversion to a multi_ptr<void>.
  // Only available when value_type is not const-qualified.
  template<access::decorated DecorateAddress2>
  operator multi_ptr<void, Space, DecorateAddress2>() const;

  // Implicit conversion to a multi_ptr<const void>.
  // Only available when value_type is const-qualified.
  template<access::decorated DecorateAddress2>
  operator multi_ptr<const void, Space, DecorateAddress2>() const;

  // Implicit conversion to multi_ptr<const value_type, Space>.
  template<access::decorated DecorateAddress2>
  operator multi_ptr<const value_type, Space, DecorateAddress2>() const;

  // Implicit conversion to the non-decorated version of multi_ptr.
  // Only available when is_decorated is true.
  operator multi_ptr<value_type, Space, access::decorated::no>() const;

  // Implicit conversion to the decorated version of multi_ptr.
  // Only available when is_decorated is false.
  operator multi_ptr<value_type, Space, access::decorated::yes>() const;

  void prefetch(size_t numElements) const;

  // Arithmetic operators
  friend multi_ptr& operator++(multi_ptr& mp) { /* ... */ }
  friend multi_ptr operator++(multi_ptr& mp, int) { /* ... */ }
  friend multi_ptr& operator--(multi_ptr& mp) { /* ... */ }
  friend multi_ptr operator--(multi_ptr& mp, int) { /* ... */ }
  friend multi_ptr& operator+=(multi_ptr& lhs, difference_type r) { /* ... */ }
  friend multi_ptr& operator-=(multi_ptr& lhs, difference_type r) { /* ... */ }
  friend multi_ptr operator+(const multi_ptr& lhs, difference_type r) { /* ... */ }
  friend multi_ptr operator-(const multi_ptr& lhs, difference_type r) { /* ... */ }
  friend reference operator*(const multi_ptr& lhs) { /* ... */ }

  friend bool operator==(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */ }
  friend bool operator!=(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */ }
  friend bool operator<(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */ }
  friend bool operator>(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */ }
  friend bool operator<=(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */ }
  friend bool operator>=(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */ }

  friend bool operator==(const multi_ptr& lhs, std::nullptr_t) { /* ... */ }
  friend bool operator!=(const multi_ptr& lhs, std::nullptr_t) { /* ... */ }
  friend bool operator<(const multi_ptr& lhs, std::nullptr_t) { /* ... */ }
  friend bool operator>(const multi_ptr& lhs, std::nullptr_t) { /* ... */ }
  friend bool operator<=(const multi_ptr& lhs, std::nullptr_t) { /* ... */ }
  friend bool operator>=(const multi_ptr& lhs, std::nullptr_t) { /* ... */ }

  friend bool operator==(std::nullptr_t, const multi_ptr& rhs) { /* ... */ }
  friend bool operator!=(std::nullptr_t, const multi_ptr& rhs) { /* ... */ }
  friend bool operator<(std::nullptr_t, const multi_ptr& rhs) { /* ... */ }
  friend bool operator>(std::nullptr_t, const multi_ptr& rhs) { /* ... */ }
  friend bool operator<=(std::nullptr_t, const multi_ptr& rhs) { /* ... */ }
  friend bool operator>=(std::nullptr_t, const multi_ptr& rhs) { /* ... */ }

};

// Specialization of multi_ptr for void and const void
// VoidType can be either void or const void
template <access::address_space Space, access::decorated DecorateAddress>
class multi_ptr<VoidType, Space, DecorateAddress> {
 public:
  static constexpr bool is_decorated = DecorateAddress == access::decorated::yes;
  static constexpr access::address_space address_space = Space;

  using value_type = VoidType;
  using pointer = std::conditional_t<is_decorated, __unspecified__ *,
                                     std::add_pointer_t<value_type>>;
  using difference_type = std::ptrdiff_t;

  static_assert(std::is_same_v<remove_decoration_t<pointer>, std::add_pointer_t<value_type>>);
  // Legacy has a different interface.
  static_assert(DecorateAddress != access::decorated::legacy);

  // Constructors
  multi_ptr();
  multi_ptr(const multi_ptr&);
  multi_ptr(multi_ptr&&);
  explicit multi_ptr(typename multi_ptr<VoidType, Space, access::decorated::yes>::pointer);
  multi_ptr(std::nullptr_t);

  // Only if Space == global_space
  template <typename ElementType, int Dimensions, access_mode Mode,
            access::placeholder IsPlaceholder>
  multi_ptr(accessor<ElementType, Dimensions, Mode,
                     target::device, IsPlaceholder>);

  // Only if Space == local_space
  template <typename ElementType, int Dimensions>
  multi_ptr(local_accessor<ElementType, Dimensions>);

  // Deprecated
  // Only if Space == local_space
  template <typename ElementType, int Dimensions, access_mode Mode,
            access::placeholder IsPlaceholder>
  multi_ptr(accessor<ElementType, Dimensions, Mode, target::local,
                     IsPlaceholder>);

  // Assignment operators
  multi_ptr &operator=(const multi_ptr&);
  multi_ptr &operator=(multi_ptr&&);
  multi_ptr &operator=(std::nullptr_t);

  pointer get() const;

  // Conversion to the underlying pointer type
  explicit operator pointer() const;

  // Explicit conversion to a multi_ptr<ElementType>
  // If VoidType is const, ElementType must be as well
  template <typename ElementType>
  explicit operator multi_ptr<ElementType, Space, DecorateAddress>() const;

  // Implicit conversion to the non-decorated version of multi_ptr.
  // Only available when is_decorated is true.
  operator multi_ptr<value_type, Space, access::decorated::no>() const;

  // Implicit conversion to the decorated version of multi_ptr.
  // Only available when is_decorated is false.
  operator multi_ptr<value_type, Space, access::decorated::yes>() const;

  // Implicit conversion to multi_ptr<const void, Space>
  operator multi_ptr<const void, Space, DecorateAddress>() const;

  friend bool operator==(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */ }
  friend bool operator!=(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */ }
  friend bool operator<(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */ }
  friend bool operator>(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */ }
  friend bool operator<=(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */ }
  friend bool operator>=(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */ }

  friend bool operator==(const multi_ptr& lhs, std::nullptr_t) { /* ... */ }
  friend bool operator!=(const multi_ptr& lhs, std::nullptr_t) { /* ... */ }
  friend bool operator<(const multi_ptr& lhs, std::nullptr_t) { /* ... */ }
  friend bool operator>(const multi_ptr& lhs, std::nullptr_t) { /* ... */ }
  friend bool operator<=(const multi_ptr& lhs, std::nullptr_t) { /* ... */ }
  friend bool operator>=(const multi_ptr& lhs, std::nullptr_t) { /* ... */ }

  friend bool operator==(std::nullptr_t, const multi_ptr& rhs) { /* ... */ }
  friend bool operator!=(std::nullptr_t, const multi_ptr& rhs) { /* ... */ }
  friend bool operator<(std::nullptr_t, const multi_ptr& rhs) { /* ... */ }
  friend bool operator>(std::nullptr_t, const multi_ptr& rhs) { /* ... */ }
  friend bool operator<=(std::nullptr_t, const multi_ptr& rhs) { /* ... */ }
  friend bool operator>=(std::nullptr_t, const multi_ptr& rhs) { /* ... */ }

};

// Deprecated, address_space_cast should be used instead.
template <typename ElementType, access::address_space Space, access::decorated DecorateAddress>
multi_ptr<ElementType, Space, DecorateAddress> make_ptr(ElementType *);

template <access::address_space Space, access::decorated DecorateAddress,
          typename ElementType>
multi_ptr<ElementType, Space, DecorateAddress> address_space_cast(ElementType *);

// Deduction guides
template <int Dimensions, access_mode Mode, access::placeholder IsPlaceholder,
          class T>
multi_ptr(
    accessor<T, Dimensions, Mode, target::device, IsPlaceholder>)
    -> multi_ptr<T, access::address_space::global_space>;
template <int Dimensions, access_mode Mode, access::placeholder IsPlaceholder,
          class T>
multi_ptr(local_accessor<T, Dimensions>)
    -> multi_ptr<T, access::address_space::local_space>;

}  // namespace sycl
