// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

#include <sycl/sycl.hpp>
using namespace sycl;  // (optional) avoids need for "sycl::" before SYCL names

struct Compound {
  int i;
  float f;
};

constexpr specialization_id<int> a{1};             // OK
constexpr specialization_id<Compound> b{2, 3.14};  // OK
inline constexpr specialization_id<int> c{3};      // OK
static constexpr specialization_id<int> d{4};      // OK
specialization_id<int> e{5};                       // ILLEGAL: not constexpr

struct Bar {
  static constexpr specialization_id<int> f{6};  // OK
};
struct Baz {
  struct Inner {
    static constexpr specialization_id<int> g{7};  // OK
  };
};
class Boo {
  static constexpr specialization_id<int> h{8};  // ILLEGAL: not public member
};

void Func() {
  static constexpr specialization_id<int> i{9};  // ILLEGAL: not at namespace
                                                 // or class scope
  /* ... */
}

constexpr specialization_id<int> same_name{10};  // OK
namespace foo {
constexpr specialization_id<int> same_name{11};  // OK
}
namespace {
constexpr specialization_id<int> same_name{12};  // OK
}
inline namespace other {
int same_name;  // ILLEGAL: shadows "specialization_id" variable with same name
                // in enclosing namespace scope
}
inline namespace other2 {
namespace foo {  // ILLEGAL: namespace name shadows "::foo" namespace which
                 // contains "specialization_id" variable.
}  // namespace foo
}  // namespace other2
