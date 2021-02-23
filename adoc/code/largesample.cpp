// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

#include <iostream>
#include <sycl/sycl.hpp>
using namespace sycl; // (optional) avoids need for "sycl::" before SYCL names

// Size of the matrices
constexpr size_t N = 2000;
constexpr size_t M = 3000;

int main() {
  // Create a queue to work on
  queue myQueue;

  // Create some 2D buffers of float for our matrices
  buffer<float, 2> a { range<2>{N, M} };
  buffer<float, 2> b { range<2>{N, M} };
  buffer<float, 2> c { range<2>{N, M} };

  // Launch an asynchronous kernel to initialize a
  myQueue.submit([&](handler& cgh) {
    // The kernel writes a, so get a write accessor on it
    accessor A { a, cgh, write_only };

    // Enqueue a parallel kernel iterating on a N*M 2D iteration space
    cgh.parallel_for(range<2> {N, M}, [=](id<2> index) {
      A[index] = index[0] * 2 + index[1];
    });
  });

  // Launch an asynchronous kernel to initialize b
  myQueue.submit([&](handler& cgh) {
    // The kernel writes b, so get a write accessor on it
    accessor B { b, cgh, write_only };

    // From the access pattern above, the SYCL runtime detects that this
    // command_group is independent from the first one and can be
    // scheduled independently

    // Enqueue a parallel kernel iterating on a N*M 2D iteration space
    cgh.parallel_for(range<2> {N, M}, [=](id<2> index) {
      B[index] = index[0] * 2014 + index[1] * 42;
    });
  });

  // Launch an asynchronous kernel to compute matrix addition c = a + b
  myQueue.submit([&](handler& cgh) {
    // In the kernel a and b are read, but c is written
    accessor A { a, cgh, read_only };
    accessor B { b, cgh, read_only };
    accessor C { c, cgh, write_only };

    // From these accessors, the SYCL runtime will ensure that when
    // this kernel is run, the kernels computing a and b have completed

    // Enqueue a parallel kernel iterating on a N*M 2D iteration space
    cgh.parallel_for(range<2> {N, M}, [=](id<2> index) {
        C[index] = A[index] + B[index];
     });
    });

  // Ask for an accessor to read c from application scope.  The SYCL runtime
  // waits for c to be ready before returning from the constructor
  host_accessor C { c, read_only };
  std::cout << std::endl << "Result:" << std::endl;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      // Compare the result to the analytic value
      if (C[i][j] != i * (2 + 2014) + j * (1 + 42)) {
        std::cout << "Wrong value " << C[i][j] << " on element " << i << " "
                  << j << std::endl;
        exit(-1);
      }
    }
  }

  std::cout << "Good computation!" << std::endl;
  return 0;
}
