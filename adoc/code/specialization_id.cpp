// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

#include <sycl/sycl.hpp>
using namespace sycl; // (optional) avoids need for "sycl::" before SYCL names

struct Mixed {int i; float f;};

constexpr specialization_id<int> a{1};            // OK
static constexpr specialization_id<int> b{2};     // OK
specialization_id<int> c{3};                      // ERROR: not constexpr

namespace foo {
  constexpr specialization_id<Mixed> c{1, 3.14};  // OK
}
namespace {
  constexpr specialization_id<Mixed> d{2, 2.718}; // OK
}

struct Bar {
  static constexpr specialization_id<int> e{4};   // OK
};
struct Baz {
  struct Inner {
    static constexpr specialization_id<int> f{5}; // OK
  };
};
class Boo {
  static constexpr specialization_id<int> g{6};   // ERROR: not public member
};

void Func() {
  static constexpr specialization_id<int> h{7};   // ERROR: not at namespace or class scope
  /* ... */
}
