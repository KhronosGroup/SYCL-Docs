// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

// Explicit kernel names can be optionally forward declared at namespace scope
class MyForwardDeclName;

template <typename T>
class MyTemplatedKernelName;

// Define and launch templated kernel
template <typename T>
void templatedFunction() {
  queue myQueue;

  // Launch A: No explicit kernel name
  myQueue.submit([&](handler& h) {
    h.single_task([=] {
      // [kernel code that depends on type T]
    });
  });

  // Launch B: Name the kernel when invoking (this is optional)
  myQueue.submit([&](handler& h) {
    h.single_task<MyTemplatedKernelName<T>>([=] {
      // The provided kernel name (MyTemplatedKernelName<T>) depends on T
      // because the kernel does.  T must also be forward declarable at
      // namespace scope.

      // [kernel code that depends on type T]
    });
  });
}

int main() {
  queue myQueue;

  myQueue.submit([&](handler& h) {
    // Declare MyKernel within this kernel invocation.  Legal because
    // forward declaration at namespace scope is optional
    h.single_task<class MyKernel>([=] {
      // [kernel code]
    });
  });

  myQueue.submit([&](handler& h) {
    // Use kernel name that was forward declared at namespace scope
    h.single_task<MyForwardDeclName>([=] {
      // [kernel code]
    });
  });

  templatedFunction<int>();  // OK

  templatedFunction<std::complex<float>>();  // Launch A is OK, Launch B illegal
  // because std::complex is not forward declarable according to C++, and was
  // used in an explicit kernel name which must be forward declarable.
}
