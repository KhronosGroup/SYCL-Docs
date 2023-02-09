// Copyright (c) 2011-2023 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

template <typename Group>
void group_barrier(Group g,
                   memory_scope fence_scope = Group::fence_scope); // (1)
