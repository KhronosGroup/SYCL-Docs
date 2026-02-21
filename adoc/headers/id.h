// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
template <int Dimensions = 1> class id {
 public:
  static constexpr int dimensions = Dimensions;

  id() noexcept;

  /* The following constructor is only available in the id class
   * specialization where: Dimensions==1 */
  id(std::size_t dim0) noexcept;
  /* The following constructor is only available in the id class
   * specialization where: Dimensions==2 */
  id(std::size_t dim0, std::size_t dim1) noexcept;
  /* The following constructor is only available in the id class
   * specialization where: Dimensions==3 */
  id(std::size_t dim0, std::size_t dim1, std::size_t dim2) noexcept;

  /* -- common interface members -- */

  id(const range<Dimensions>& range) noexcept;
  id(const item<Dimensions>& item) noexcept;

  std::size_t get(int dimension) const noexcept;
  std::size_t& operator[](int dimension) noexcept;
  std::size_t operator[](int dimension) const noexcept;

  // only available if Dimensions == 1
  operator std::size_t() const noexcept;

  // OP is: +, -, *, /, %, <<, >>, &, |, ^, &&, ||, <, >, <=, >=
  friend id operatorOP(const id& lhs, const id& rhs) noexcept { /* ... */
  }

  // OP is: +, -, *, /, %, <<, >>, &, |, ^, &&, ||, <, >, <=, >=
  // Available only when std::is_integral_v<T> is true
  template <typename T>
  friend id operatorOP(const id& lhs, const T& rhs) noexcept { /* ... */
  }

  // OP is: +, -, *, /, %, <<, >>, &, |, ^, &&, ||, <, >, <=, >=
  // Available only when std::is_integral_v<T> is true
  template <typename T>
  friend id operatorOP(const T& lhs, const id& rhs) noexcept { /* ... */
  }

  // OP is: +=, -=, *=, /=, %=, <<=, >>=, &=, |=, ^=
  friend id& operatorOP(id& lhs, const id& rhs) noexcept { /* ... */
  }

  // OP is: +=, -=, *=, /=, %=, <<=, >>=, &=, |=, ^=
  // Available only when std::is_integral_v<T> is true
  template <typename T>
  friend id& operatorOP(id& lhs, const T& rhs) noexcept { /* ... */
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
id(std::size_t)->id<1>;
id(std::size_t, std::size_t)->id<2>;
id(std::size_t, std::size_t, std::size_t)->id<3>;

} // namespace sycl
