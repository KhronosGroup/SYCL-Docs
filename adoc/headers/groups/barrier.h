// Copyright (c) 2011-2024 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

template <typename Group>
void group_barrier(Group g,
                   memory_scope scope = Group::fence_scope); // (1)
