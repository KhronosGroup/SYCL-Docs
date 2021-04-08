// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

#include <sycl/sycl.hpp>
using namespace sycl; // (optional) avoids need for "sycl::" before SYCL names

struct Mixed {int i; float f;};

constexpr specialization_id<int> a{1};            // OK
constexpr specialization_id<Mixed> b{2, 3.14};    // OK
inline constexpr specialization_id<int> c{3};     // OK
static constexpr specialization_id<int> d{4};     // OK
specialization_id<int> e{5};                      // ILLEGAL: not constexpr

namespace foo {
  constexpr specialization_id<int> same_name{6};  // OK
}
namespace bar {
  constexpr specialization_id<int> same_name{7};  // OK
}
namespace {
  constexpr specialization_id<int> other_name{8}; // OK
}
namespace {
  constexpr specialization_id<int> same_name{9};  // ILLEGAL: ambiguous name in anonymous
                                                  // namespace
}

struct Bar {
  static constexpr specialization_id<int> f{10};  // OK
};
struct Baz {
  struct Inner {
    static constexpr specialization_id<int> g{11};// OK
  };
};
class Boo {
  static constexpr specialization_id<int> h{12};  // ILLEGAL: not public member
};

void Func() {
  static constexpr specialization_id<int> i{13};  // ILLEGAL: not at namespace or class scope
  /* ... */
}
