// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

enum class rounding_mode : /* unspecified */ { automatic, rte, rtz, rtp, rtn };

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

template <typename DataT, int NumElements> class vec {
 public:
  using element_type = DataT;
  using value_type = DataT;

  vec();

  // Available only when: NumElements > 1
  explicit constexpr vec(const DataT& arg);

  // Available only when: NumElements == 1
  constexpr vec(const DataT& arg);

  template <typename... ArgTN> constexpr vec(const ArgTN&... args);

  constexpr vec(const vec<DataT, NumElements>& rhs);

  // Available only when: NumElements == 1
  operator DataT() const;

  // Available only when: NumElements == 1 and T is explicitly convertible to DataT
  template<typename T>
  explicit operator T() const;

  static constexpr size_t byte_size() noexcept;

  static constexpr size_t size() noexcept;

  // Deprecated
  size_t get_size() const;

  // Deprecated
  size_t get_count() const;

  template <typename ConvertT,
            rounding_mode RoundingMode = rounding_mode::automatic>
  vec<ConvertT, NumElements> convert() const;

  template <typename AsT> AsT as() const;

  // Available on when the number of swizzleIndexes template parameters is
  // 1, 2, 3, 4, 8, or 16.
  // Available only when each of the swizzleIndexes template parameters is
  // greater or equal to 0 and less than NumElements.
  template <int... swizzleIndexes> __writeable_swizzle__ swizzle();
  template <int... swizzleIndexes> __const_swizzle__ swizzle() const;

  // Available only when NumElements <= 4.
  // XYZW_ACCESS is: x, y, z, w, subject to NumElements.
  DataT& XYZW_ACCESS();
  const DataT& XYZW_ACCESS() const;

  // Available only NumElements == 4.
  // RGBA_ACCESS is: r, g, b, a.
  DataT& RGBA_ACCESS();
  const DataT& RGBA_ACCESS() const;

  // INDEX_ACCESS is: s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD,
  // sE, sF, subject to NumElements.
  DataT& INDEX_ACCESS();
  const DataT& INDEX_ACCESS() const;

#ifdef SYCL_SIMPLE_SWIZZLES
  // Available only when NumElements <= 4.
  // XYZW_SWIZZLE is all permutations with repetition of: x, y, z, w, subject to
  // NumElements.
  __writeable_swizzle__ XYZW_SWIZZLE();
  __const_swizzle__ XYZW_SWIZZLE() const;

  // Available only when NumElements == 4.
  // RGBA_SWIZZLE is all permutations with repetition of: r, g, b, a.
  __writeable_swizzle__ RGBA_SWIZZLE();
  __const_swizzle__ RGBA_SWIZZLE() const;

#endif // #ifdef SYCL_SIMPLE_SWIZZLES

  // Available only when: NumElements > 1.
  __writeable_swizzle__ lo();
  __const_swizzle__ lo() const;

  __writeable_swizzle__ hi();
  __const_swizzle__ hi() const;

  __writeable_swizzle__ odd();
  __const_swizzle__ odd() const;

  __writeable_swizzle__ even();
  __const_swizzle__ even() const;

  // load and store member functions
  template <access::address_space AddressSpace, access::decorated IsDecorated>
  void load(size_t offset,
            multi_ptr<const DataT, AddressSpace, IsDecorated> ptr);

  void load(size_t offset, const DataT* ptr);

  template <access::address_space AddressSpace, access::decorated IsDecorated>
  void store(size_t offset,
             multi_ptr<DataT, AddressSpace, IsDecorated> ptr) const;

  void store(size_t offset, DataT* ptr) const;

  // subscript operator
  DataT& operator[](int index);
  const DataT& operator[](int index) const;

  vec& operator=(const vec& rhs);

  // Available only when: T is convertible to DataT
  template<typename T>
  vec& operator=(const T& rhs);

  // OP is: +, -, *, /, %
  //
  // Available only when: T is convertible to DataT
  // If OP is %, available only when: DataT != float && DataT != double && DataT != half
  friend vec operatorOP(const vec& lhs, const vec& rhs);

  template<typename T>
  friend vec operatorOP(const vec& lhs, const T& rhs);

  template<typename T>
  friend vec operatorOP(const T& lhs, const vec& rhs);

  // OP is: +=, -=, *=, /=, %=
  //
  // Available only when: T is convertible to DataT
  // If OP is %=, available only when: DataT != float && DataT != double && DataT != half
  friend vec& operatorOP(vec& lhs, const vec& rhs);

  template<typename T>
  friend vec& operatorOP(vec& lhs, const T& rhs);

  // OP is prefix ++, --
  //
  // Available only when: DataT != bool
  friend vec& operatorOP(vec& rhs);

  // OP is postfix ++, --
  //
  // Available only when: DataT != bool
  friend vec operatorOP(vec& lhs, int);

  // OP is unary +, -
  friend vec operatorOP(const vec& rhs);

  // OP is: &, |, ^
  //
  // Available only when: T is convertible to DataT
  // Available only when: DataT != float && DataT != double && DataT != half
  friend vec operatorOP(const vec& lhs, const vec& rhs);

  template<typename T>
  friend vec operatorOP(const vec& lhs, const T& rhs);

  template<typename T>
  friend vec operatorOP(const T& lhs, const vec& rhs);

  // OP is: &=, |=, ^=
  //
  // Available only when: T is convertible to DataT
  // Available only when: DataT != float && DataT != double && DataT != half
  friend vec& operatorOP(vec& lhs, const vec& rhs);

  template<typename T>
  friend vec& operatorOP(vec& lhs, const T& rhs);

  // OP is: <<, >>
  //
  // Available only when: T is convertible to DataT
  // Available only when: DataT != float && DataT != double && DataT != half
  friend vec operatorOP(const vec& lhs, const vec& rhs);

  template<typename T>
  friend vec operatorOP(const vec& lhs, const T& rhs);

  template<typename T>
  friend vec operatorOP(const T& lhs, const vec& rhs);

  // OP is: <<=, >>=
  //
  // Available only when: T is convertible to DataT
  // Available only when: DataT != float && DataT != double && DataT != half
  friend vec& operatorOP(vec& lhs, const vec& rhs);

  template<typename T>
  friend vec& operatorOP(vec& lhs, const T& rhs);

  // OP is: &&, ||
  //
  // Available only when: T is convertible to DataT
  friend vec<RET, NumElements> operatorOP(const vec& lhs, const vec& rhs);

  template<typename T>
  friend vec<RET, NumElements> operatorOP(const vec& lhs, const T& rhs);

  template<typename T>
  friend vec<RET, NumElements> operatorOP(const T& lhs, const vec& rhs);

  // OP is: ==, !=, <, >, <=, >=
  //
  // Available only when: T is convertible to DataT
  friend vec<RET, NumElements> operatorOP(const vec& lhs, const vec& rhs);

  template<typename T>
  friend vec<RET, NumElements> operatorOP(const vec& lhs, const T& rhs);

  template<typename T>
  friend vec<RET, NumElements> operatorOP(const T& lhs, const vec& rhs);

  // Available only when: DataT != float && DataT != double && DataT != half
  friend vec operator~(const vec& v);

  friend vec<RET, NumElements> operator!(const vec& v);
};

// Deduction guides
// Available only when: (std::is_same_v<T, U> && ...)
template <class T, class... U> vec(T, U...) -> vec<T, sizeof...(U) + 1>;

} // namespace sycl
