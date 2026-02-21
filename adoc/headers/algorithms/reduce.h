// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

template <typename Group, typename Ptr, typename BinaryOperation>
std::iterator_traits<Ptr>::value_type
joint_reduce(Group g, Ptr first, Ptr last, BinaryOperation binary_op); // (1)

template <typename Group, typename Ptr, typename T, typename BinaryOperation>
T joint_reduce(Group g, Ptr first, Ptr last, T init,
               BinaryOperation binary_op); // (2)

template <typename Group, typename T, typename BinaryOperation>
T reduce_over_group(Group g, T x, BinaryOperation binary_op); // (3)

template <typename Group, typename V, typename T, typename BinaryOperation>
T reduce_over_group(Group g, V x, T init, BinaryOperation binary_op); // (4)
