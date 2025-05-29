// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
template <int Dimensions = 1> class id {
 public:
  static constexpr int dimensions = Dimensions;

  id();

  /* The following constructor is only available in the id class
   * specialization where: Dimensions==1 */
  id(std::size_t dim0);
  /* The following constructor is only available in the id class
   * specialization where: Dimensions==2 */
  id(std::size_t dim0, std::size_t dim1);
  /* The following constructor is only available in the id class
   * specialization where: Dimensions==3 */
  id(std::size_t dim0, std::size_t dim1, std::size_t dim2);

  /* -- common interface members -- */

  id(const range<Dimensions>& range);
  id(const item<Dimensions>& item);

  std::size_t get(int dimension) const;
  std::size_t& operator[](int dimension);
  std::size_t operator[](int dimension) const;

  // only available if Dimensions == 1
  operator std::size_t() const;

  // OP is: +, -, *, /, %, <<, >>, &, |, ^, &&, ||, <, >, <=, >=
  friend id operatorOP(const id& lhs, const id& rhs) { /* ... */
  }
  friend id operatorOP(const id& lhs, const std::size_t& rhs) { /* ... */
  }

  // OP is: +=, -=, *=, /=, %=, <<=, >>=, &=, |=, ^=
  friend id& operatorOP(id& lhs, const id& rhs) { /* ... */
  }
  friend id& operatorOP(id& lhs, const std::size_t& rhs) { /* ... */
  }

  // OP is: +, -, *, /, %, <<, >>, &, |, ^, &&, ||, <, >, <=, >=
  friend id operatorOP(const std::size_t& lhs, const id& rhs) { /* ... */
  }

  // OP is unary +, -
  friend id operatorOP(const id& rhs) { /* ... */
  }

  // OP is prefix ++, --
  friend id& operatorOP(id& rhs) { /* ... */
  }

  // OP is postfix ++, --
  friend id operatorOP(id& lhs, int) { /* ... */
  }
};

// Deduction guides
id(std::size_t)->id<1>;
id(std::size_t, std::size_t)->id<2>;
id(std::size_t, std::size_t, std::size_t)->id<3>;

} // namespace sycl
