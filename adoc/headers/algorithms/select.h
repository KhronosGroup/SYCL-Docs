// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

template <typename Group, typename T>
T select_from_group(Group g, T x, Group::id_type remote_local_id); // (1)
