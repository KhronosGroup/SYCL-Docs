// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

#include <sycl/sycl.hpp>

SYCL_EXTERNAL void A1();               // OK
void A1() { /* ... */ }                // OK; redeclaration
void A2();                             // OK
SYCL_EXTERNAL void A2() { /* ... */ }  // ERROR: SYCL_EXTERNAL not on first declaration.
SYCL_EXTERNAL void A3() { /* ... */ }  // OK

SYCL_EXTERNAL extern void B1();  // OK
extern SYCL_EXTERNAL void B2();  // ERROR: SYCL_EXTERNAL after declaration specifiers.

[[maybe_unused]] SYCL_EXTERNAL void C1();  // OK
SYCL_EXTERNAL [[maybe_unused]] void C2();  // OK

template <typename T> SYCL_EXTERNAL void D();    // OK
template <> SYCL_EXTERNAL inline void D<int>();  // OK
