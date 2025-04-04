// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

template <typename BinaryOperation, typename AccumulatorT>
struct known_identity {
  static constexpr AccumulatorT value;
};

template <typename BinaryOperation, typename AccumulatorT>
inline constexpr AccumulatorT known_identity_v =
    known_identity<BinaryOperation, AccumulatorT>::value;

template <typename BinaryOperation, typename AccumulatorT>
struct has_known_identity {
  static constexpr bool value;
};

template <typename BinaryOperation, typename AccumulatorT>
inline constexpr bool has_known_identity_v =
    has_known_identity<BinaryOperation, AccumulatorT>::value;
