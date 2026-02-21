// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
template <int Dimensions = 1> class range {
 public:
  static constexpr int dimensions = Dimensions;

  range() noexcept;

  /* The following constructor is only available in the range class
   * specialization where: Dimensions==1 */
  range(std::size_t dim0) noexcept;
  /* The following constructor is only available in the range class
   * specialization where: Dimensions==2 */
  range(std::size_t dim0, std::size_t dim1) noexcept;
  /* The following constructor is only available in the range class
   * specialization where: Dimensions==3 */
  range(std::size_t dim0, std::size_t dim1, std::size_t dim2) noexcept;

  /* -- common interface members -- */

  std::size_t get(int dimension) const noexcept;
  std::size_t& operator[](int dimension) noexcept;
  std::size_t operator[](int dimension) const noexcept;

  std::size_t size() const noexcept;

  // OP is: +, -, *, /, %, <<, >>, &, |, ^, &&, ||, <, >, <=, >=
  friend range operatorOP(const range& lhs, const range& rhs) noexcept { /* ... */
  }

  // OP is: +, -, *, /, %, <<, >>, &, |, ^, &&, ||, <, >, <=, >=
  // Available only when std::is_integral_v<T> is true
  template <typename T>
  friend range operatorOP(const range& lhs, const T& rhs) noexcept { /* ... */
  }

  // OP is: +, -, *, /, %, <<, >>, &, |, ^, &&, ||, <, >, <=, >=
  // Available only when std::is_integral_v<T> is true
  template <typename T>
  friend range operatorOP(const T& lhs, const range& rhs) noexcept { /* ... */
  }

  // OP is: +=, -=, *=, /=, %=, <<=, >>=, &=, |=, ^=
  friend range& operatorOP(range& lhs, const range& rhs) noexcept { /* ... */
  }

  // OP is: +=, -=, *=, /=, %=, <<=, >>=, &=, |=, ^=
  // Available only when std::is_integral_v<T> is true
  template <typename T>
  friend range& operatorOP(range& lhs, const T& rhs) noexcept { /* ... */
  }

  // OP is unary +, -
  friend range operatorOP(const range& rhs) noexcept { /* ... */
  }

  // OP is prefix ++, --
  friend range& operatorOP(range& rhs) noexcept { /* ... */
  }

  // OP is postfix ++, --
  friend range operatorOP(range& lhs, int) noexcept { /* ... */
  }
};

// Deduction guides
range(std::size_t)->range<1>;
range(std::size_t, std::size_t)->range<2>;
range(std::size_t, std::size_t, std::size_t)->range<3>;

} // namespace sycl
