// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

buffer<int> valuesBuf{1024};
{
  // Initialize buffer on the host with 0, 1, 2, 3, ..., 1023
  host_accessor a{valuesBuf};
  std::iota(a.begin(), a.end(), 0);
}

// Buffers with just 1 element to get the reduction results
int sumResult = 0;
buffer<int> sumBuf{&sumResult, 1};
int maxResult = 0;
buffer<int> maxBuf{&maxResult, 1};

myQueue.submit([&](handler& cgh) {
  // Input values to reductions are standard accessors
  auto inputValues = valuesBuf.get_access<access_mode::read>(cgh);

  // Create temporary objects describing variables with reduction semantics
  auto sumReduction = reduction(sumBuf, cgh, plus<>());
  auto maxReduction = reduction(maxBuf, cgh, maximum<>());

  // parallel_for performs two reduction operations
  // For each reduction variable, the implementation:
  // - Creates a corresponding reducer
  // - Passes a reference to the reducer to the lambda as a parameter
  cgh.parallel_for(range<1>{1024}, sumReduction, maxReduction,
                   [=](id<1> idx, auto& sum, auto& max) {
                     // plus<>() corresponds to += operator, so sum can be
                     // updated via += or combine()
                     sum += inputValues[idx];

                     // maximum<>() has no shorthand operator, so max can only
                     // be updated via combine()
                     max.combine(inputValues[idx]);
                   });
});

// sumBuf and maxBuf contain the reduction results once the kernel completes
assert(maxBuf.get_host_access()[0] == 1023 &&
       sumBuf.get_host_access()[0] == 523776);
