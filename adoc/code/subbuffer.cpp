// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

buffer<int, 2> parent_buffer{
    range<2>{8, 8}};  // Create 2-d buffer with 8x8 ints

// OK: Contiguous region from middle of buffer
buffer<int, 2> sub_buf1{parent_buffer, /*offset*/ range<2>{2, 0},
                        /*size*/ range<2>{2, 8}};

// invalid exception: Non-contiguous regions of 2-d buffer
buffer<int, 2> sub_buf2{parent_buffer, /*offset*/ range<2>{2, 0},
                        /*size*/ range<2>{2, 2}};
buffer<int, 2> sub_buf3{parent_buffer, /*offset*/ range<2>{2, 2},
                        /*size*/ range<2>{2, 6}};

// invalid exception: Out-of-bounds size
buffer<int, 2> sub_buf4{parent_buffer, /*offset*/ range<2>{2, 2},
                        /*size*/ range<2>{2, 8}};
