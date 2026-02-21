// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

template <typename Group, typename InPtr, typename OutPtr,
          typename BinaryOperation>
OutPtr joint_exclusive_scan(Group g, InPtr first, InPtr last, OutPtr result,
                            BinaryOperation binary_op); // (1)

template <typename Group, typename InPtr, typename OutPtr, typename T,
          typename BinaryOperation>
OutPtr joint_exclusive_scan(Group g, InPtr first, InPtr last, OutPtr result,
                            T init, BinaryOperation binary_op); // (2)

template <typename Group, typename T, typename BinaryOperation>
T exclusive_scan_over_group(Group g, T x, BinaryOperation binary_op); // (3)

template <typename Group, typename V, typename T, typename BinaryOperation>
T exclusive_scan_over_group(Group g, V x, T init,
                            BinaryOperation binary_op); // (4)
