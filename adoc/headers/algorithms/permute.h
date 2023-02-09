// Copyright (c) 2011-2023 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

template <typename Group, typename T>
T permute_group_by_xor(Group g, T x, Group::linear_id_type mask); // (1)
