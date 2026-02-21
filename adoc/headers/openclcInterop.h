// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

extern "C" typename sycl::decorated_global_ptr<std::int32_t>::pointer
my_func(sycl::float4::vector_t x, double y);
