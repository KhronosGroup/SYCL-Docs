// Copyright (c) 2011-2025 The Khronos Group, Inc.
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

} // namespace access

// Shorthand aliases for address spaces
using addrspace = access::address_space;
constexpr inline addrspace addrspace_global = addrspace::global_space;
constexpr inline addrspace addrspace_local = addrspace::local_space;
constexpr inline addrspace addrspace_private = addrspace::private_space;
constexpr inline addrspace addrspace_generic = addrspace::generic_space;

template <typename T> struct remove_decoration {
  using type = /* ... */;
};

template <typename T> using remove_decoration_t = remove_decoration<T>::type;

template <typename ElementType, access::address_space Space,
          access::decorated DecorateAddress = access::decorated::legacy>
class multi_ptr {
 public:
  static constexpr bool is_decorated =
      DecorateAddress == access::decorated::yes;
  static constexpr access::address_space address_space = Space;

  using value_type = ElementType;
  using pointer = std::conditional_t<is_decorated, __unspecified__*,
                                     std::add_pointer_t<value_type>>;
  using reference = std::conditional_t<is_decorated, __unspecified__&,
                                       std::add_lvalue_reference_t<value_type>>;
  using iterator_category = std::random_access_iterator_tag;
  using difference_type = std::ptrdiff_t;

  static_assert(std::is_same_v<remove_decoration_t<pointer>,
                               std::add_pointer_t<value_type>>);
  static_assert(std::is_same_v<remove_decoration_t<reference>,
                               std::add_lvalue_reference_t<value_type>>);
  // Legacy has a different interface.
  static_assert(DecorateAddress != access::decorated::legacy);

  // Constructors
  multi_ptr();
  multi_ptr(const multi_ptr&);
  multi_ptr(multi_ptr&&);
  explicit multi_ptr(
      typename multi_ptr<ElementType, Space, access::decorated::yes>::pointer);
  multi_ptr(std::nullptr_t);

  // Available only when:
  //   (Space == access::address_space::global_space ||
  //    Space == access::address_space::generic_space) &&
  //   (std::is_same_v<std::remove_const_t<ElementType>, std::remove_const_t<AccDataT>>) &&
  //   (std::is_const_v<ElementType> ||
  //    !std::is_const_v<accessor<AccDataT, Dimensions, Mode, target::device,
  //                              IsPlaceholder>::value_type>)
  template <typename AccDataT, int Dimensions, access_mode Mode,
            access::placeholder IsPlaceholder>
  multi_ptr(
      accessor<AccDataT, Dimensions, Mode, target::device, IsPlaceholder>);

  // Available only when:
  //   (Space == access::address_space::local_space ||
  //    Space == access::address_space::generic_space) &&
  //   (std::is_same_v<std::remove_const_t<ElementType>, std::remove_const_t<AccDataT>>) &&
  //   (std::is_const_v<ElementType> || !std::is_const_v<AccDataT>)
  template <typename AccDataT, int Dimensions>
  multi_ptr(local_accessor<AccDataT, Dimensions>);

  // Deprecated
  // Available only when:
  //   (Space == access::address_space::local_space ||
  //    Space == access::address_space::generic_space) &&
  //   (std::is_same_v<std::remove_const_t<ElementType>, std::remove_const_t<AccDataT>>) &&
  //   (std::is_const_v<ElementType> || !std::is_const_v<AccDataT>)
  template <typename AccDataT, int Dimensions, access_mode Mode,
            access::placeholder IsPlaceholder>
  multi_ptr(
      accessor<AccDataT, Dimensions, Mode, target::local, IsPlaceholder>);

  // Deprecated
  // Available only when:
  //   Space == access::address_space::constant_space &&
  //   (std::is_same_v<std::remove_const_t<ElementType>, std::remove_const_t<AccDataT>>) &&
  //   (std::is_const_v<ElementType> || !std::is_const_v<AccDataT>)
  template <typename AccDataT, int Dimensions, access::placeholder IsPlaceholder>
  multi_ptr(
      accessor<AccDataT, Dimensions, access_mode::read, target::constant_buffer, IsPlaceholder>);

  // Assignment and access operators
  multi_ptr& operator=(const multi_ptr&);
  multi_ptr& operator=(multi_ptr&&);
  multi_ptr& operator=(std::nullptr_t);

  // Available only when:
  //   (Space == access::address_space::generic_space &&
  //    AS != access::address_space::constant_space)
  template <access::address_space AS, access::decorated IsDecorated>
  multi_ptr& operator=(const multi_ptr<value_type, AS, IsDecorated>&);

  // Available only when:
  //   (Space == access::address_space::generic_space &&
  //    AS != access::address_space::constant_space)
  template <access::address_space AS, access::decorated IsDecorated>
  multi_ptr& operator=(multi_ptr<value_type, AS, IsDecorated>&&);

  reference operator[](std::ptrdiff_t) const;

  reference operator*() const;
  pointer operator->() const;

  pointer get() const;
  std::add_pointer_t<value_type> get_raw() const;
  __unspecified__* get_decorated() const;

  // Conversion to the underlying pointer type
  // Deprecated, get() should be used instead.
  operator pointer() const;

  // Cast to private_ptr
  // Available only when: (Space == access::address_space::generic_space)
  template <access::decorated IsDecorated>
  explicit operator multi_ptr<value_type, access::address_space::private_space,
                              IsDecorated>() const;

  // Cast to private_ptr of const data
  // Available only when: (Space == access::address_space::generic_space)
  template <access::decorated IsDecorated>
  explicit operator multi_ptr<const value_type, access::address_space::private_space,
                              IsDecorated>() const;

  // Cast to global_ptr
  // Available only when: (Space == access::address_space::generic_space)
  template <access::decorated IsDecorated>
  explicit operator multi_ptr<value_type, access::address_space::global_space,
                              IsDecorated>() const;

  // Cast to global_ptr of const data
  // Available only when: (Space == access::address_space::generic_space)
  template <access::decorated IsDecorated>
  explicit operator multi_ptr<const value_type, access::address_space::global_space,
                              IsDecorated>() const;

  // Cast to local_ptr
  // Available only when: (Space == access::address_space::generic_space)
  template <access::decorated IsDecorated>
  explicit operator multi_ptr<value_type, access::address_space::local_space,
                              IsDecorated>() const;

  // Cast to local_ptr of const data
  // Available only when: (Space == access::address_space::generic_space)
  template <access::decorated IsDecorated>
  explicit operator multi_ptr<const value_type, access::address_space::local_space,
                              IsDecorated>() const;

  // Implicit conversion to a multi_ptr<void>.
  // Available only when: (!std::is_const_v<value_type>)
  template <access::decorated IsDecorated>
  operator multi_ptr<void, Space, IsDecorated>() const;

  // Implicit conversion to a multi_ptr<const void>.
  // Available only when: (std::is_const_v<value_type>)
  template <access::decorated IsDecorated>
  operator multi_ptr<const void, Space, IsDecorated>() const;

  // Implicit conversion to multi_ptr<const value_type, Space>.
  template <access::decorated IsDecorated>
  operator multi_ptr<const value_type, Space, IsDecorated>() const;

  // Implicit conversion to the non-decorated version of multi_ptr.
  // Available only when: (is_decorated == true)
  operator multi_ptr<value_type, Space, access::decorated::no>() const;

  // Implicit conversion to the decorated version of multi_ptr.
  // Available only when: (is_decorated == false)
  operator multi_ptr<value_type, Space, access::decorated::yes>() const;

  // Available only when: (Space == address_space::global_space)
  void prefetch(size_t numElements) const;

  // Arithmetic operators
  friend multi_ptr& operator++(multi_ptr& mp) { /* ... */
  }
  friend multi_ptr operator++(multi_ptr& mp, int) { /* ... */
  }
  friend multi_ptr& operator--(multi_ptr& mp) { /* ... */
  }
  friend multi_ptr operator--(multi_ptr& mp, int) { /* ... */
  }
  friend multi_ptr& operator+=(multi_ptr& lhs, difference_type r) { /* ... */
  }
  friend multi_ptr& operator-=(multi_ptr& lhs, difference_type r) { /* ... */
  }
  friend multi_ptr operator+(const multi_ptr& lhs,
                             difference_type r) { /* ... */
  }
  friend multi_ptr operator-(const multi_ptr& lhs,
                             difference_type r) { /* ... */
  }
  friend reference operator*(const multi_ptr& lhs) { /* ... */
  }

  friend bool operator==(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator!=(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator<(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator>(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator<=(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator>=(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */
  }

  friend bool operator==(const multi_ptr& lhs, std::nullptr_t) { /* ... */
  }
  friend bool operator!=(const multi_ptr& lhs, std::nullptr_t) { /* ... */
  }
  friend bool operator<(const multi_ptr& lhs, std::nullptr_t) { /* ... */
  }
  friend bool operator>(const multi_ptr& lhs, std::nullptr_t) { /* ... */
  }
  friend bool operator<=(const multi_ptr& lhs, std::nullptr_t) { /* ... */
  }
  friend bool operator>=(const multi_ptr& lhs, std::nullptr_t) { /* ... */
  }

  friend bool operator==(std::nullptr_t, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator!=(std::nullptr_t, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator<(std::nullptr_t, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator>(std::nullptr_t, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator<=(std::nullptr_t, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator>=(std::nullptr_t, const multi_ptr& rhs) { /* ... */
  }
};

// Specialization of multi_ptr for void and const void
// VoidType can be either void or const void
template <access::address_space Space, access::decorated DecorateAddress>
class multi_ptr<VoidType, Space, DecorateAddress> {
 public:
  static constexpr bool is_decorated =
      DecorateAddress == access::decorated::yes;
  static constexpr access::address_space address_space = Space;

  using value_type = VoidType;
  using pointer = std::conditional_t<is_decorated, __unspecified__*,
                                     std::add_pointer_t<value_type>>;
  using difference_type = std::ptrdiff_t;

  static_assert(std::is_same_v<remove_decoration_t<pointer>,
                               std::add_pointer_t<value_type>>);
  // Legacy has a different interface.
  static_assert(DecorateAddress != access::decorated::legacy);

  // Constructors
  multi_ptr();
  multi_ptr(const multi_ptr&);
  multi_ptr(multi_ptr&&);
  explicit multi_ptr(
      typename multi_ptr<VoidType, Space, access::decorated::yes>::pointer);
  multi_ptr(std::nullptr_t);

  // Available only when:
  //   (Space == access::address_space::global_space ||
  //    Space == access::address_space::generic_space) &&
  //   (std::is_const_v<VoidType> ||
  //    !std::is_const_v<accessor<ElementType, Dimensions, Mode, target::device,
  //                              IsPlaceholder>::value_type>)
  template <typename ElementType, int Dimensions, access_mode Mode,
            access::placeholder IsPlaceholder>
  multi_ptr(
      accessor<ElementType, Dimensions, Mode, target::device, IsPlaceholder>);

  // Available only when:
  //   (Space == access::address_space::local_space ||
  //    Space == access::address_space::generic_space) &&
  //   (std::is_const_v<VoidType> || !std::is_const_v<ElementType>)
  template <typename ElementType, int Dimensions>
  multi_ptr(local_accessor<ElementType, Dimensions>);

  // Deprecated
  // Available only when:
  //   (Space == access::address_space::local_space ||
  //    Space == access::address_space::generic_space) &&
  //   (std::is_const_v<VoidType> || !std::is_const_v<ElementType>)
  template <typename ElementType, int Dimensions, access_mode Mode,
            access::placeholder IsPlaceholder>
  multi_ptr(
      accessor<ElementType, Dimensions, Mode, target::local, IsPlaceholder>);

  // Deprecated
  // Available only when:
  //   Space == access::address_space::constant_space &&
  //   (std::is_const_v<VoidType> || !std::is_const_v<ElementType>)
  template <typename ElementType, int Dimensions, access::placeholder IsPlaceholder>
  multi_ptr(
      accessor<ElementType, Dimensions, access_mode::read, target::constant_buffer, IsPlaceholder>);

  // Assignment operators
  multi_ptr& operator=(const multi_ptr&);
  multi_ptr& operator=(multi_ptr&&);
  multi_ptr& operator=(std::nullptr_t);

  pointer get() const;

  // Conversion to the underlying pointer type
  operator pointer() const;

  // Explicit conversion to a multi_ptr<ElementType>
  // Available only when: (std::is_const_v<ElementType> || !std::is_const_v<VoidType>)
  template <typename ElementType>
  explicit operator multi_ptr<ElementType, Space, DecorateAddress>() const;

  // Implicit conversion to the non-decorated version of multi_ptr.
  // Available only when: (is_decorated == true)
  operator multi_ptr<value_type, Space, access::decorated::no>() const;

  // Implicit conversion to the decorated version of multi_ptr.
  // Available only when: (is_decorated == false)
  operator multi_ptr<value_type, Space, access::decorated::yes>() const;

  // Implicit conversion to multi_ptr<const void, Space>
  operator multi_ptr<const void, Space, DecorateAddress>() const;

  friend bool operator==(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator!=(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator<(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator>(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator<=(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator>=(const multi_ptr& lhs, const multi_ptr& rhs) { /* ... */
  }

  friend bool operator==(const multi_ptr& lhs, std::nullptr_t) { /* ... */
  }
  friend bool operator!=(const multi_ptr& lhs, std::nullptr_t) { /* ... */
  }
  friend bool operator<(const multi_ptr& lhs, std::nullptr_t) { /* ... */
  }
  friend bool operator>(const multi_ptr& lhs, std::nullptr_t) { /* ... */
  }
  friend bool operator<=(const multi_ptr& lhs, std::nullptr_t) { /* ... */
  }
  friend bool operator>=(const multi_ptr& lhs, std::nullptr_t) { /* ... */
  }

  friend bool operator==(std::nullptr_t, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator!=(std::nullptr_t, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator<(std::nullptr_t, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator>(std::nullptr_t, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator<=(std::nullptr_t, const multi_ptr& rhs) { /* ... */
  }
  friend bool operator>=(std::nullptr_t, const multi_ptr& rhs) { /* ... */
  }
};

// Deprecated, address_space_cast should be used instead.
template <typename ElementType, access::address_space Space,
          access::decorated DecorateAddress>
multi_ptr<ElementType, Space, DecorateAddress> make_ptr(ElementType*);

template <access::address_space Space, access::decorated DecorateAddress,
          typename ElementType>
multi_ptr<ElementType, Space, DecorateAddress> address_space_cast(ElementType*);

// Deduction guides
template <typename T, int Dimensions, access::placeholder IsPlaceholder>
multi_ptr(accessor<T, Dimensions, access_mode::read, target::device, IsPlaceholder>)
    -> multi_ptr<const T, access::address_space::global_space, access::decorated::no>;

template <typename T, int Dimensions, access::placeholder IsPlaceholder>
multi_ptr(accessor<T, Dimensions, access_mode::write, target::device, IsPlaceholder>)
    -> multi_ptr<T, access::address_space::global_space, access::decorated::no>;

template <typename T, int Dimensions, access::placeholder IsPlaceholder>
multi_ptr(accessor<T, Dimensions, access_mode::read_write, target::device, IsPlaceholder>)
    -> multi_ptr<T, access::address_space::global_space, access::decorated::no>;

template <typename T, int Dimensions, access::placeholder IsPlaceholder>
multi_ptr(accessor<T, Dimensions, access_mode::read, target::constant_buffer, IsPlaceholder>)
    -> multi_ptr<const T, access::address_space::constant_space, access::decorated::no>;

template <typename T, int Dimensions, access_mode Mode, access::placeholder IsPlaceholder>
multi_ptr(accessor<T, Dimensions, Mode, target::local, IsPlaceholder>)
    -> multi_ptr<T, access::address_space::local_space, access::decorated::no>;

template <typename T, int Dimensions>
multi_ptr(local_accessor<T, Dimensions>)
    -> multi_ptr<T, access::address_space::local_space, access::decorated::no>;

} // namespace sycl
