// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

// Exposition only
template <typename T, typename BinaryOperation, int Dimensions,
          /* unspecified */>
class reducer {
 public:
  using value_type = T;
  using binary_operation = BinaryOperation;
  static constexpr int dimensions = Dimensions;

  reducer(const reducer&) = delete;
  reducer(reducer&&) = delete;
  reducer& operator=(const reducer&) = delete;
  reducer& operator=(reducer&&) = delete;

  ~reducer();

  /* Only available if Dimensions == 0 */
  reducer& combine(const T& partial);

  /* Only available if Dimensions > 0 */
  __unspecified__ operator[](size_t index)

      /* Only available if identity value is known */
      T identity() const;

  /* Only available if Dimensions == 0 and either
   * BinaryOperation == plus<> or BinaryOperation == plus<T> */
  friend reducer& operator+=(reducer&, const T&) { /* ... */
  }

  /* Only available if Dimensions == 0 and either
   * BinaryOperation == multiplies<> or BinaryOperation == multiplies<T> */
  friend reducer& operator*=(reducer&, const T&) { /* ... */
  }

  /* Only available if Dimensions == 0, T is an integral type and either
   * BinaryOperation == bit_and<> or BinaryOperation == bit_and<T> */
  friend reducer& operator&=(reducer&, const T&) { /* ... */
  }

  /* Only available if Dimensions == 0, T is an integral type and either
   * BinaryOperation == bit_or<> or BinaryOperation == bit_or<T> */
  friend reducer& operator|=(reducer&, const T&) { /* ... */
  }

  /* Only available if Dimensions == 0, T is an integral type and either
   * BinaryOperation == bit_xor<> or BinaryOperation == bit_xor<T> */
  friend reducer& operator^=(reducer&, const T&) { /* ... */
  }

  /* Only available if Dimensions == 0, T is an integral type, T is not bool and
   * either BinaryOperation == plus<> or BinaryOperation == plus<T> */
  friend reducer& operator++(reducer&) { /* ... */
  }
};
