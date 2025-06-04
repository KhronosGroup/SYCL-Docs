// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
template <int Dimensions = 1> class id {
 public:
  static constexpr int dimensions = Dimensions;

  id() noexcept;

  /* The following constructor is only available in the id class
   * specialization where: Dimensions==1 */
  id(size_t dim0) noexcept;
  /* The following constructor is only available in the id class
   * specialization where: Dimensions==2 */
  id(size_t dim0, size_t dim1) noexcept;
  /* The following constructor is only available in the id class
   * specialization where: Dimensions==3 */
  id(size_t dim0, size_t dim1, size_t dim2) noexcept;

  /* -- common interface members -- */

  id(const range<Dimensions>& range) noexcept;
  id(const item<Dimensions>& item) noexcept;

  size_t get(int dimension) const noexcept;
  size_t& operator[](int dimension) noexcept;
  size_t operator[](int dimension) const noexcept;

  // only available if Dimensions == 1
  operator size_t() const noexcept;

  // OP is: +, -, *, /, %, <<, >>, &, |, ^, &&, ||, <, >, <=, >=
  friend id operatorOP(const id& lhs, const id& rhs) noexcept { /* ... */
  }
  friend id operatorOP(const id& lhs, const size_t& rhs) noexcept { /* ... */
  }

  // OP is: +=, -=, *=, /=, %=, <<=, >>=, &=, |=, ^=
  friend id& operatorOP(id& lhs, const id& rhs) noexcept { /* ... */
  }
  friend id& operatorOP(id& lhs, const size_t& rhs) noexcept { /* ... */
  }

  // OP is: +, -, *, /, %, <<, >>, &, |, ^, &&, ||, <, >, <=, >=
  friend id operatorOP(const size_t& lhs, const id& rhs) noexcept { /* ... */
  }

  // OP is unary +, -
  friend id operatorOP(const id& rhs) noexcept { /* ... */
  }

  // OP is prefix ++, --
  friend id& operatorOP(id& rhs) noexcept { /* ... */
  }

  // OP is postfix ++, --
  friend id operatorOP(id& lhs, int) noexcept { /* ... */
  }
};

// Deduction guides
id(size_t)->id<1>;
id(size_t, size_t)->id<2>;
id(size_t, size_t, size_t)->id<3>;

} // namespace sycl
