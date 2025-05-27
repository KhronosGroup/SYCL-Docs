// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
template <int Dimensions = 1> class range {
 public:
  static constexpr int dimensions = Dimensions;

  range();

  /* The following constructor is only available in the range class
   * specialization where: Dimensions==1 */
  range(size_t dim0);
  /* The following constructor is only available in the range class
   * specialization where: Dimensions==2 */
  range(size_t dim0, size_t dim1);
  /* The following constructor is only available in the range class
   * specialization where: Dimensions==3 */
  range(size_t dim0, size_t dim1, size_t dim2);

  /* -- common interface members -- */

  size_t get(int dimension) const;
  size_t& operator[](int dimension);
  size_t operator[](int dimension) const;

  size_t size() const;

  // OP is: +, -, *, /, %, <<, >>, &, |, ^, &&, ||, <, >, <=, >=
  friend range operatorOP(const range& lhs, const range& rhs) { /* ... */
  }
  friend range operatorOP(const range& lhs, const size_t& rhs) { /* ... */
  }

  // OP is: +=, -=, *=, /=, %=, <<=, >>=, &=, |=, ^=
  friend range& operatorOP(range& lhs, const range& rhs) { /* ... */
  }
  friend range& operatorOP(range& lhs, const size_t& rhs) { /* ... */
  }

  // OP is: +, -, *, /, %, <<, >>, &, |, ^, &&, ||, <, >, <=, >=
  friend range operatorOP(const size_t& lhs, const range& rhs) { /* ... */
  }

  // OP is unary +, -
  friend range operatorOP(const range& rhs) { /* ... */
  }

  // OP is prefix ++, --
  friend range& operatorOP(range& rhs) { /* ... */
  }

  // OP is postfix ++, --
  friend range operatorOP(range& lhs, int) { /* ... */
  }
};

// Deduction guides
range(size_t)->range<1>;
range(size_t, size_t)->range<2>;
range(size_t, size_t, size_t)->range<3>;

} // namespace sycl
