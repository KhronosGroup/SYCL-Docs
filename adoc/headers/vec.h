// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

enum class rounding_mode {
  automatic,
  rte,
  rtz,
  rtp,
  rtn
};

struct elem {
  static constexpr int x = 0;
  static constexpr int y = 1;
  static constexpr int z = 2;
  static constexpr int w = 3;
  static constexpr int r = 0;
  static constexpr int g = 1;
  static constexpr int b = 2;
  static constexpr int a = 3;
  static constexpr int s0 = 0;
  static constexpr int s1 = 1;
  static constexpr int s2 = 2;
  static constexpr int s3 = 3;
  static constexpr int s4 = 4;
  static constexpr int s5 = 5;
  static constexpr int s6 = 6;
  static constexpr int s7 = 7;
  static constexpr int s8 = 8;
  static constexpr int s9 = 9;
  static constexpr int sA = 10;
  static constexpr int sB = 11;
  static constexpr int sC = 12;
  static constexpr int sD = 13;
  static constexpr int sE = 14;
  static constexpr int sF = 15;
};

template <typename dataT, int numElements>
class vec {
 public:
  using element_type = dataT;

#ifdef __SYCL_DEVICE_ONLY__
  using vector_t = __unspecified__;
#endif

  vec();

  explicit constexpr vec(const dataT &arg);

  template <typename... argTN>
  constexpr vec(const argTN&... args);

  constexpr vec(const vec<dataT, numElements> &rhs);

#ifdef __SYCL_DEVICE_ONLY__
  vec(vector_t nativeVector);

  operator vector_t() const;
#endif

  // Available only when: numElements == 1
  operator dataT() const;
  
  static constexpr size_t byte_size() noexcept;

  static constexpr size_t size() noexcept;

  // Deprecated
  size_t get_size() const;

  // Deprecated
  size_t get_count() const;

  template <typename convertT, rounding_mode roundingMode = rounding_mode::automatic>
  vec<convertT, numElements> convert() const;

  template <typename asT>
  asT as() const;

  template<int... swizzleIndexes>
  __swizzled_vec__ swizzle() const;

  // Available only when numElements <= 4.
  // XYZW_ACCESS is: x, y, z, w, subject to numElements.
  __swizzled_vec__ XYZW_ACCESS() const;

  // Available only numElements == 4.
  // RGBA_ACCESS is: r, g, b, a.
  __swizzled_vec__ RGBA_ACCESS() const;

  // INDEX_ACCESS is: s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD,
  // sE, sF, subject to numElements.
  __swizzled_vec__ INDEX_ACCESS() const;

#ifdef SYCL_SIMPLE_SWIZZLES
  // Available only when numElements <= 4.
  // XYZW_SWIZZLE is all permutations with repetition of: x, y, z, w, subject to
  // numElements.
  __swizzled_vec__ XYZW_SWIZZLE() const;

  // Available only when numElements == 4.
  // RGBA_SWIZZLE is all permutations with repetition of: r, g, b, a.
  __swizzled_vec__ RGBA_SWIZZLE() const;

#endif  // #ifdef SYCL_SIMPLE_SWIZZLES

  // Available only when: numElements > 1.
  __swizzled_vec__ lo() const;
  __swizzled_vec__ hi() const;
  __swizzled_vec__ odd() const;
  __swizzled_vec__ even() const;

  // load and store member functions
  template <access::address_space addressSpace, access::decorated IsDecorated>
  void load(size_t offset, multi_ptr<const dataT, addressSpace, IsDecorated> ptr);
  template <access::address_space addressSpace, access::decorated IsDecorated>
  void store(size_t offset, multi_ptr<dataT, addressSpace, IsDecorated> ptr) const;

  // subscript operator
  dataT &operator[](int index);
  const dataT &operator[](int index) const;

  // OP is: +, -, *, /, %
  /* If OP is %, available only when: dataT != float && dataT != double
  && dataT != half. */
  friend vec operatorOP(const vec &lhs, const vec &rhs) { /* ... */ }
  friend vec operatorOP(const vec &lhs, const dataT &rhs) { /* ... */ }

  // OP is: +=, -=, *=, /=, %=
  /* If OP is %=, available only when: dataT != float && dataT != double
  && dataT != half. */
  friend vec &operatorOP(vec &lhs, const vec &rhs) { /* ... */ }
  friend vec &operatorOP(vec &lhs, const dataT &rhs) { /* ... */ }

  // OP is prefix ++, --
  friend vec &operatorOP(vec &rhs) { /* ... */ }

  // OP is postfix ++, --
  friend vec operatorOP(vec& lhs, int) { /* ... */ }

  // OP is unary +, -
  friend vec operatorOP(const vec &rhs) { /* ... */ }

  // OP is: &, |, ^
  /* Available only when: dataT != float && dataT != double
  && dataT != half. */
  friend vec operatorOP(const vec &lhs, const vec &rhs) { /* ... */ }
  friend vec operatorOP(const vec &lhs, const dataT &rhs) { /* ... */ }

  // OP is: &=, |=, ^=
  /* Available only when: dataT != float && dataT != double
  && dataT != half. */
  friend vec &operatorOP(vec &lhs, const vec &rhs) { /* ... */ }
  friend vec &operatorOP(vec &lhs, const dataT &rhs) { /* ... */ }

  // OP is: &&, ||
  friend vec<RET, numElements> operatorOP(const vec &lhs, const vec &rhs) {
    /* ... */ }
  friend vec<RET, numElements> operatorOP(const vec& lhs, const dataT &rhs) {
    /* ... */ }

  // OP is: <<, >>
  /* Available only when: dataT != float && dataT != double
  && dataT != half. */
  friend vec operatorOP(const vec &lhs, const vec &rhs) { /* ... */ }
  friend vec operatorOP(const vec &lhs, const dataT &rhs) { /* ... */ }

  // OP is: <<=, >>=
  /* Available only when: dataT != float && dataT != double
  && dataT != half. */
  friend vec &operatorOP(vec &lhs, const vec &rhs) { /* ... */ }
  friend vec &operatorOP(vec &lhs, const dataT &rhs) { /* ... */ }

  // OP is: ==, !=, <, >, <=, >=
  friend vec<RET, numElements> operatorOP(const vec &lhs, const vec &rhs) {
    /* ... */ }
  friend vec<RET, numElements> operatorOP(const vec &lhs, const dataT &rhs) {
    /* ... */ }

  vec &operator=(const vec<dataT, numElements> &rhs);
  vec &operator=(const dataT &rhs);

  /* Available only when: dataT != float && dataT != double
  && dataT != half. */
  friend vec operator~(const vec &v) { /* ... */ }
  friend vec<RET, numElements> operator!(const vec &v) { /* ... */ }

  // OP is: +, -, *, /, %
  /* operator% is only available when: dataT != float && dataT != double &&
  dataT != half. */
  friend vec operatorOP(const dataT &lhs, const vec &rhs) { /* ... */ }

  // OP is: &, |, ^
  /* Available only when: dataT != float && dataT != double
  && dataT != half. */
  friend vec operatorOP(const dataT &lhs, const vec &rhs) { /* ... */ }

  // OP is: &&, ||
  friend vec<RET, numElements> operatorOP(const dataT &lhs, const vec &rhs) {
    /* ... */ }

  // OP is: <<, >>
  /* Available only when: dataT != float && dataT != double
  && dataT != half. */
  friend vec operatorOP(const dataT &lhs, const vec &rhs) { /* ... */ }

  // OP is: ==, !=, <, >, <=, >=
  friend vec<RET, numElements> operatorOP(const dataT &lhs, const vec &rhs) {
    /* ... */ }

};

// Deduction guides
// Available only when: (std::is_same_v<T, U> && ...)
template <class T, class... U>
vec(T, U...) -> vec<T, sizeof...(U) + 1>;

}  // namespace sycl
