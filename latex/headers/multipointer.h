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
namespace access {
enum class address_space : int {
  global_space,
  local_space,
  constant_space,
  private_space
};
}  // namespace access

template <typename ElementType, access::address_space Space>
class multi_ptr {
 public:
  using element_type = ElementType;
  using difference_type = std::ptrdiff_t;

  // Implementation defined pointer and reference types that correspond to
  // SYCL/OpenCL interoperability types for OpenCL C functions
  using pointer_t = __unspecified__ ElementType*;
  using const_pointer_t = __unspecified__ const ElementType*;
  using reference_t = __unspecified__ ElementType&;
  using const_reference_t = __unspecified__ const ElementType&;

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
  template <int dimensions, access::mode Mode, access::placeholder isPlaceholder>
  multi_ptr(accessor<ElementType, dimensions, Mode, access::target::global_buffer, isPlaceholder>);

  // Only if Space == local_space
  template <int dimensions, access::mode Mode, access::placeholder isPlaceholder>
  multi_ptr(accessor<ElementType, dimensions, Mode, access::target::local, isPlaceholder>);

  // Only if Space == constant_space
  template <int dimensions, access::mode Mode, access::placeholder isPlaceholder>
  multi_ptr(accessor<ElementType, dimensions, Mode, access::target::constant_buffer, isPlaceholder>);

  // Returns the underlying OpenCL C pointer
  pointer_t get() const;

  // Implicit conversion to the underlying pointer type
  operator ElementType*() const;

  // Implicit conversion to a multi_ptr<void>
  // Only available when ElementType is not const-qualified
  operator multi_ptr<void, Space>() const;

  // Implicit conversion to a multi_ptr<const void>
  // Only available when ElementType is const-qualified
  operator multi_ptr<const void, Space>() const;

  // Implicit conversion to multi_ptr<const ElementType, Space>
  operator multi_ptr<const ElementType, Space>() const;

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

// Specialization of multi_ptr for void and const void
// VoidType can be either void or const void
template <access::address_space Space>
class multi_ptr<VoidType, Space> {
 public:
  using element_type = VoidType;
  using difference_type = std::ptrdiff_t;

  // Implementation defined pointer types that correspond to
  // SYCL/OpenCL interoperability types for OpenCL C functions
  using pointer_t = __unspecified__ VoidType*;
  using const_pointer_t = __unspecified__ const VoidType*;

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
  template <typename ElementType, int dimensions, access::mode Mode>
  multi_ptr(accessor<ElementType, dimensions, Mode, access::target::global_buffer>);

  // Only if Space == local_space
  template <typename ElementType, int dimensions, access::mode Mode>
  multi_ptr(accessor<ElementType, dimensions, Mode, access::target::local>);

  // Only if Space == constant_space
  template <typename ElementType, int dimensions, access::mode Mode>
  multi_ptr(accessor<ElementType, dimensions, Mode, access::target::constant_buffer>);

  // Returns the underlying OpenCL C pointer
  pointer_t get() const;

  // Implicit conversion to the underlying pointer type
  operator VoidType*() const;

  // Explicit conversion to a multi_ptr<ElementType>
  // If VoidType is const, ElementType must be as well
  template <typename ElementType>
  explicit operator multi_ptr<ElementType, Space>() const;

  // Implicit conversion to multi_ptr<const void, Space>
  operator multi_ptr<const void, Space>() const;
    
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

template <typename ElementType, access::address_space Space>
multi_ptr<ElementType, Space> make_ptr(multi_ptr<ElementType, Space>::pointer_t);

template <typename ElementType, access::address_space Space>
multi_ptr<ElementType, Space> make_ptr(ElementType*);

}  // namespace sycl
}  // namespace cl
