// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

const size_t nElems = 10u;

// Create a vector and fill it with values 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
std::vector<int> v{nElems};
std::iota(std::begin(v), std::end(v), 0);

// Create a buffer with no associated user storage
sycl::buffer<int, 1> b{range<1>(nElems)};

// Create a queue
queue myQueue;

myQueue.submit([&](handler& cgh) {
  // Retrieve a ranged write accessor to a global buffer with access to the
  // first half of the buffer
  accessor acc{b, cgh, range<1>(nElems / 2), id<1>(0), write_only};
  // Copy the first five elements of the vector into the buffer associated with
  // the accessor
  cgh.copy(v.data(), acc);
});
