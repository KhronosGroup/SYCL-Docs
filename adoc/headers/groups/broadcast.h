// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

template <typename Group, typename T> T group_broadcast(Group g, T x); // (1)

template <typename Group, typename T>
T group_broadcast(Group g, T x, Group::linear_id_type local_linear_id); // (2)

template <typename Group, typename T>
T group_broadcast(Group g, T x, Group::id_type local_id); // (3)
