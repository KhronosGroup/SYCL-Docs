// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

#include <sycl/sycl.hpp>
using namespace sycl;  // (optional) avoids need for "sycl::" before SYCL names

int main() {
  vec v{5, 6, 7, 8};
  vec<int, 2> slice = v.swizzle<2, 1>();  // slice has the value {7,6}
  slice = v.swizzle<2, 2>();              // slice is now {7,7}
  int i = v.swizzle<2, 1>()[1];           // i has the value 6
  v.swizzle<2>() = 0;                     // v is now {5,6,0,8}
  v.swizzle<1>()++;                       // v is now {5,7,0,8}
  v.swizzle<2, 3>();  // Has no effect because result of swizzle is
                      // neither read nor modified
}
