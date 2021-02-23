// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

// Exposition only
template <typename T, typename BinaryOperation, int Dimensions, /* unspecified */>
class reducer {

  reducer(const reducer<T,BinaryOperation,Dimensions>&) = delete;
  reducer<T,BinaryOperation,Dimensions>& operator(const reducer<T,BinaryOperation,Dimensions>&) = delete;

  /* Only available if Dimensions == 0 */
  void combine(const T& partial);

  /* Only available if Dimensions > 0 */
  __unspecified__ &operator[](size_t index) const;

  /* Only available if identity value is known */
  T identity() const;

};

template <typename T>
void operator+=(reducer<T,plus<T>,0>&, const T&);

template <typename T>
void operator*=(reducer<T,multiplies<T>,0>&, const T&);

/* Only available for integral types */
template <typename T>
void operator&=(reducer<T,bit_and<T>,0>&, const T&);

/* Only available for integral types */
template <typename T>
void operator|=(reducer<T,bit_or<T>,0>&, const T&);

/* Only available for integral types */
template <typename T>
void operator^=(reducer<T,bit_xor<T>,0>&, const T&);

/* Only available for integral types */
template <typename T>
void operator++(reducer<T,plus<T>,0>&);
