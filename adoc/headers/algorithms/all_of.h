// Copyright (c) 2011-2024 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

template <typename Group, typename Ptr, typename Predicate>
bool joint_all_of(Group g, Ptr first, Ptr last, Predicate pred); // (1)

template <typename Group, typename T, typename Predicate>
bool all_of_group(Group g, T x, Predicate pred); // (2)

template <typename Group> bool all_of_group(Group g, bool pred); // (3)
