// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
template <int Dimensions = 1> class id {
 public:
  static constexpr int dimensions = Dimensions;

  id();

  /* The following constructor is only available in the id class
   * specialization where: Dimensions==1 */
  id(size_t dim0);
  /* The following constructor is only available in the id class
   * specialization where: Dimensions==2 */
  id(size_t dim0, size_t dim1);
  /* The following constructor is only available in the id class
   * specialization where: Dimensions==3 */
  id(size_t dim0, size_t dim1, size_t dim2);

  /* -- common interface members -- */

  id(const range<Dimensions>& range);
  id(const item<Dimensions>& item);

  size_t get(int dimension) const;
  size_t& operator[](int dimension);
  size_t operator[](int dimension) const;

  // only available if Dimensions == 1
  operator size_t() const;

  // OP is: +, -, *, /, %, <<, >>, &, |, ^, &&, ||, <, >, <=, >=
  friend id operatorOP(const id& lhs, const id& rhs) { /* ... */
  }
  friend id operatorOP(const id& lhs, const size_t& rhs) { /* ... */
  }

  // OP is: +=, -=, *=, /=, %=, <<=, >>=, &=, |=, ^=
  friend id& operatorOP(id& lhs, const id& rhs) { /* ... */
  }
  friend id& operatorOP(id& lhs, const size_t& rhs) { /* ... */
  }

  // OP is: +, -, *, /, %, <<, >>, &, |, ^, &&, ||, <, >, <=, >=
  friend id operatorOP(const size_t& lhs, const id& rhs) { /* ... */
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
id(size_t)->id<1>;
id(size_t, size_t)->id<2>;
id(size_t, size_t, size_t)->id<3>;

} // namespace sycl
