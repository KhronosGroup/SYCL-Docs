// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

template <typename Group, typename T>
T shift_group_left(Group g, T x, Group::linear_id_type delta = 1); // (1)

template <typename Group, typename T>
T shift_group_right(Group g, T x, Group::linear_id_type delta = 1); // (2)
