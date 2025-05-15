// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

template <typename DataT, std::size_t NumElements> class marray {
 public:
  using value_type = DataT;
  using reference = DataT&;
  using const_reference = const DataT&;
  using iterator = DataT*;
  using const_iterator = const DataT*;

  marray();

  explicit constexpr marray(const DataT& arg);

  template <typename... ArgTN> constexpr marray(const ArgTN&... args);

  constexpr marray(const marray<DataT, NumElements>& rhs);
  constexpr marray(marray<DataT, NumElements>&& rhs);

  // Available only when: NumElements == 1
  operator DataT() const;

  static constexpr std::size_t size() noexcept;

  // subscript operator
  reference operator[](std::size_t index);
  const_reference operator[](std::size_t index) const;

  marray& operator=(const marray<DataT, NumElements>& rhs);
  marray& operator=(const DataT& rhs);

  // iterator functions
  iterator begin();
  const_iterator begin() const;

  iterator end();
  const_iterator end() const;

  // OP is: +, -, *, /, %
  /* If OP is %, available only when: DataT != float && DataT != double && DataT
   * != half. */
  friend marray operatorOP(const marray& lhs, const marray& rhs) { /* ... */
  }
  friend marray operatorOP(const marray& lhs, const DataT& rhs) { /* ... */
  }

  // OP is: +=, -=, *=, /=, %=
  /* If OP is %=, available only when: DataT != float && DataT != double &&
   * DataT != half. */
  friend marray& operatorOP(marray& lhs, const marray& rhs) { /* ... */
  }
  friend marray& operatorOP(marray& lhs, const DataT& rhs) { /* ... */
  }

  // OP is prefix ++, --
  friend marray& operatorOP(marray& v) { /* ... */
  }

  // OP is postfix ++, --
  friend marray operatorOP(marray& v, int) { /* ... */
  }

  // OP is unary +, -
  friend marray operatorOP(marray& v) { /* ... */
  }

  // OP is: &, |, ^
  /* Available only when: DataT != float && DataT != double && DataT != half. */
  friend marray operatorOP(const marray& lhs, const marray& rhs) { /* ... */
  }
  friend marray operatorOP(const marray& lhs, const DataT& rhs) { /* ... */
  }

  // OP is: &=, |=, ^=
  /* Available only when: DataT != float && DataT != double && DataT != half. */
  friend marray& operatorOP(marray& lhs, const marray& rhs) { /* ... */
  }
  friend marray& operatorOP(marray& lhs, const DataT& rhs) { /* ... */
  }

  // OP is: &&, ||
  friend marray<bool, NumElements> operatorOP(const marray& lhs,
                                              const marray& rhs) {
  /* ... */ }
  friend marray<bool, NumElements> operatorOP(const marray& lhs,
                                              const DataT& rhs) {
  /* ... */ }

  // OP is: <<, >>
  /* Available only when: DataT != float && DataT != double && DataT != half.
   */
  friend marray operatorOP(const marray& lhs, const marray& rhs) { /* ... */
  }
  friend marray operatorOP(const marray& lhs, const DataT& rhs) { /* ... */
  }

  // OP is: <<=, >>=
  /* Available only when: DataT != float && DataT != double && DataT != half.
   */
  friend marray& operatorOP(marray& lhs, const marray& rhs) { /* ... */
  }
  friend marray& operatorOP(marray& lhs, const DataT& rhs) { /* ... */
  }

  // OP is: ==, !=, <, >, <=, >=
  friend marray<bool, NumElements> operatorOP(const marray& lhs,
                                              const marray& rhs) {
  /* ... */ }
  friend marray<bool, NumElements> operatorOP(const marray& lhs,
                                              const DataT& rhs) {
  /* ... */ }

  /* Available only when: DataT != float && DataT != double && DataT != half.
   */
  friend marray operator~(const marray& v) { /* ... */
  }

  // OP is: +, -, *, /, %
  /* operator% is only available when: DataT != float && DataT != double &&
   * DataT != half. */
  friend marray operatorOP(const DataT& lhs, const marray& rhs) { /* ... */
  }

  // OP is: &, |, ^
  /* Available only when: DataT != float && DataT != double
  && DataT != half. */
  friend marray operatorOP(const DataT& lhs, const marray& rhs) { /* ... */
  }

  // OP is: &&, ||
  friend marray<bool, NumElements> operatorOP(const DataT& lhs,
                                              const marray& rhs) {
  /* ... */ }

  // OP is: <<, >>
  /* Available only when: DataT != float && DataT != double && DataT != half.
   */
  friend marray operatorOP(const DataT& lhs, const marray& rhs) { /* ... */
  }

  // OP is: ==, !=, <, >, <=, >=
  friend marray<bool, NumElements> operatorOP(const DataT& lhs,
                                              const marray& rhs) {
  /* ... */ }

  friend marray<bool, NumElements> operator!(const marray& v) { /* ... */
  }
};

} // namespace sycl
