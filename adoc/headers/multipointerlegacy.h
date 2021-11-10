// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

// Legacy interface, inherited from 1.2.1.
// Deprecated.
template <typename ElementType, access::address_space Space>
class [[deprecated]] multi_ptr<ElementType, Space, access::decorated::legacy> {
 public:
  using element_type = ElementType;
  using difference_type = std::ptrdiff_t;

  // Implementation defined pointer and reference types that correspond to
  // SYCL/OpenCL interoperability types for OpenCL C functions.
  using pointer_t = multi_ptr<ElementType, Space, access::decorated::yes>::pointer;
  using const_pointer_t = multi_ptr<const ElementType, Space, access::decorated::yes>::pointer;
  using reference_t = multi_ptr<ElementType, Space, access::decorated::yes>::reference;
  using const_reference_t = multi_ptr<const ElementType, Space, access::decorated::yes>::reference;

  static constexpr access::address_space address_space = Space;

  // Constructors
  multi_ptr();
  multi_ptr(const multi_ptr&);
  multi_ptr(multi_ptr&&);
  multi_ptr(pointer_t);
  multi_ptr(ElementType*);
  multi_ptr(std::nullptr_t);
  ~multi_ptr();

  // Assignment and access operators
  multi_ptr &operator=(const multi_ptr&);
  multi_ptr &operator=(multi_ptr&&);
  multi_ptr &operator=(pointer_t);
  multi_ptr &operator=(ElementType*);
  multi_ptr &operator=(std::nullptr_t);
  friend ElementType& operator*(const multi_ptr& mp) { /* ... */ }
  ElementType* operator->() const;

  // Only if Space == global_space
  template <int Dimensions, access_mode Mode, access::placeholder IsPlaceholder>
  multi_ptr(accessor<ElementType, Dimensions, Mode, target::device, IsPlaceholder>);

  // Only if Space == local_space
  template <int Dimensions, access_mode Mode, access::placeholder IsPlaceholder>
  multi_ptr(accessor<ElementType, Dimensions, Mode, target::local, IsPlaceholder>);

  // Only if Space == constant_space
  template <int Dimensions, access_mode Mode, access::placeholder IsPlaceholder>
  multi_ptr(accessor<ElementType, Dimensions, Mode, target::constant_buffer, IsPlaceholder>);

  // Returns the underlying OpenCL C pointer
  pointer_t get() const;

  // Implicit conversion to the underlying pointer type
  operator ElementType*() const;

  // Implicit conversion to a multi_ptr<void>
  // Only available when ElementType is not const-qualified
  operator multi_ptr<void, Space, access::decorated::legacy>() const;

  // Implicit conversion to a multi_ptr<const void>
  // Only available when ElementType is const-qualified
  operator multi_ptr<const void, Space, access::decorated::legacy>() const;

  // Implicit conversion to multi_ptr<const ElementType, Space>
  operator multi_ptr<const ElementType, Space, access::decorated::legacy>() const;

  // Arithmetic operators
  friend multi_ptr& operator++(multi_ptr& mp) { /* ... */ }
  friend multi_ptr operator++(multi_ptr& mp, int) { /* ... */ }
  friend multi_ptr& operator--(multi_ptr& mp) { /* ... */ }
  friend multi_ptr operator--(multi_ptr& mp, int) { /* ... */ }
  friend multi_ptr& operator+=(multi_ptr& lhs, difference_type r) { /* ... */ }
  friend multi_ptr& operator-=(multi_ptr& lhs, difference_type r) { /* ... */ }
  friend multi_ptr operator+(const multi_ptr& lhs, difference_type r) { /* ... */ }
  friend multi_ptr operator-(const multi_ptr& lhs, difference_type r) { /* ... */ }

  void prefetch(size_t numElements) const;

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

// Legacy interface, inherited from 1.2.1.
// Deprecated.
// Specialization of multi_ptr for void and const void
// VoidType can be either void or const void
template <access::address_space Space>
class [[deprecated]] multi_ptr<VoidType, Space, access::decorated::legacy> {
 public:
  using element_type = VoidType;
  using difference_type = std::ptrdiff_t;

  // Implementation defined pointer types that correspond to
  // SYCL/OpenCL interoperability types for OpenCL C functions
  using pointer_t = multi_ptr<VoidType, Space, access::decorated::yes>::pointer;
  using const_pointer_t = multi_ptr<const VoidType, Space, access::decorated::yes>::pointer;

  static constexpr access::address_space address_space = Space;

  // Constructors
  multi_ptr();
  multi_ptr(const multi_ptr&);
  multi_ptr(multi_ptr&&);
  multi_ptr(pointer_t);
  multi_ptr(VoidType*);
  multi_ptr(std::nullptr_t);
  ~multi_ptr();

  // Assignment operators
  multi_ptr &operator=(const multi_ptr&);
  multi_ptr &operator=(multi_ptr&&);
  multi_ptr &operator=(pointer_t);
  multi_ptr &operator=(VoidType*);
  multi_ptr &operator=(std::nullptr_t);

  // Only if Space == global_space
  template <typename ElementType, int Dimensions, access_mode Mode>
  multi_ptr(accessor<ElementType, Dimensions, Mode, target::device>);

  // Only if Space == local_space
  template <typename ElementType, int Dimensions, access_mode Mode>
  multi_ptr(accessor<ElementType, Dimensions, Mode, target::local>);

  // Only if Space == constant_space
  template <typename ElementType, int Dimensions, access_mode Mode>
  multi_ptr(accessor<ElementType, Dimensions, Mode, target::constant_buffer>);

  // Returns the underlying OpenCL C pointer
  pointer_t get() const;

  // Implicit conversion to the underlying pointer type
  operator VoidType*() const;

  // Explicit conversion to a multi_ptr<ElementType>
  // If VoidType is const, ElementType must be as well
  template <typename ElementType>
  explicit operator multi_ptr<ElementType, Space, access::decorated::legacy>() const;

  // Implicit conversion to multi_ptr<const void, Space>
  operator multi_ptr<const void, Space, access::decorated::legacy>() const;

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

}  // namespace sycl
