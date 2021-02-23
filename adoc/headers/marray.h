// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

template <typename dataT, std::size_t numElements>
class marray {
 public:
  using value_type = dataT;
  using reference = dataT&;
  using const_reference = const dataT&;
  using iterator = dataT*;
  using const_iterator = const dataT*;

  marray();

  explicit marray(const dataT &arg);

  template <typename... argTN>
  marray(const argTN&... args);

  marray(const marray<dataT, numElements> &rhs);
  marray(marray<dataT, numElements> &&rhs);

  // Available only when: numElements == 1
  operator dataT() const;

  static constexpr std::size_t size() noexcept;

  // subscript operator
  reference operator[](std::size_t index);
  const_reference operator[](std::size_t index) const;

  marray &operator=(const marray<dataT, numElements> &rhs);
  marray &operator=(const dataT &rhs);

  // iterator functions
  iterator begin();
  const_iterator begin() const;

  iterator end();
  const_iterator end() const;


  // OP is: +, -, *, /, %
  /* If OP is %, available only when: dataT != float && dataT != double && dataT != half. */
  friend marray operatorOP(const marray &lhs, const marray &rhs) { /* ... */ }
  friend marray operatorOP(const marray &lhs, const dataT &rhs) { /* ... */ }

  // OP is: +=, -=, *=, /=, %=
  /* If OP is %=, available only when: dataT != float && dataT != double && dataT != half. */
  friend marray &operatorOP(marray &lhs, const marray &rhs) { /* ... */ }
  friend marray &operatorOP(marray &lhs, const dataT &rhs) { /* ... */ }

  // OP is prefix ++, --
  friend marray &operatorOP(marray &rhs) { /* ... */ }

  // OP is postfix ++, --
  friend marray operatorOP(marray& lhs, int) { /* ... */ }

  // OP is unary +, -
  friend marray operatorOP(marray &rhs) { /* ... */ }

  // OP is: &, |, ^
  /* Available only when: dataT != float && dataT != double && dataT != half. */
  friend marray operatorOP(const marray &lhs, const marray &rhs) { /* ... */ }
  friend marray operatorOP(const marray &lhs, const dataT &rhs) { /* ... */ }

  // OP is: &=, |=, ^=
  /* Available only when: dataT != float && dataT != double && dataT != half. */
  friend marray &operatorOP(marray &lhs, const marray &rhs) { /* ... */ }
  friend marray &operatorOP(marray &lhs, const dataT &rhs) { /* ... */ }

  // OP is: &&, ||
  friend marray<bool, numElements> operatorOP(const marray &lhs, const marray &rhs) {
    /* ... */ }
  friend marray<bool, numElements> operatorOP(const marray& lhs, const dataT &rhs) {
    /* ... */ }

  // OP is: <<, >>
  /* Available only when: dataT != float && dataT != double && dataT != half. */
  friend marray operatorOP(const marray &lhs, const marray &rhs) { /* ... */ }
  friend marray operatorOP(const marray &lhs, const dataT &rhs) { /* ... */ }

  // OP is: <<=, >>=
  /* Available only when: dataT != float && dataT != double && dataT != half. */
  friend marray &operatorOP(marray &lhs, const marray &rhs) { /* ... */ }
  friend marray &operatorOP(marray &lhs, const dataT &rhs) { /* ... */ }

  // OP is: ==, !=, <, >, <=, >=
  friend marray<bool, numElements> operatorOP(const marray &lhs, const marray &rhs) {
    /* ... */ }
  friend marray<bool, numElements> operatorOP(const marray &lhs, const dataT &rhs) {
    /* ... */ }

  /* Available only when: dataT != float && dataT != double && dataT != half. */
  friend marray operator~(const marray &v) { /* ... */ }

  // OP is: +, -, *, /, %
  /* operator% is only available when: dataT != float && dataT != double && dataT != half. */
  friend marray operatorOP(const dataT &lhs, const marray &rhs) { /* ... */ }

  // OP is: &, |, ^
  /* Available only when: dataT != float && dataT != double
  && dataT != half. */
  friend marray operatorOP(const dataT &lhs, const marray &rhs) { /* ... */ }

  // OP is: &&, ||
  friend marray<bool, numElements> operatorOP(const dataT &lhs, const marray &rhs) {
    /* ... */ }

  // OP is: <<, >>
  /* Available only when: dataT != float && dataT != double && dataT != half. */
  friend marray operatorOP(const dataT &lhs, const marray &rhs) { /* ... */ }

  // OP is: ==, !=, <, >, <=, >=
  friend marray<bool, numElements> operatorOP(const dataT &lhs, const marray &rhs) {
    /* ... */ }

  friend marray<bool, numElements> operator!(const marray &v) { /* ... */ }

};

}  // namespace sycl
