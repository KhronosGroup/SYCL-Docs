// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

buffer<int> inputBuf{1024};
buffer<int> outputBuf{2};
{
  // Initialize buffer on the host with 0, 1, 2, 3, ..., 1023
  host_accessor a{inputBuf};
  std::iota(a.begin(), a.end(), 0);
}

myQueue.submit([&](handler& cgh) {
  accessor inputValues{inputBuf, cgh, read_only};
  accessor outputValues{outputBuf, cgh, write_only, no_init};

  cgh.parallel_for(nd_range<1>(range<1>(16), range<1>(16)), [=](nd_item<1> it) {
    // Apply a group algorithm to any number of values, described by an iterator
    // range. The work-group reduces all inputValues and each work-item works on
    // part of the range.
    int* first = inputValues.get_pointer();
    int* last = first + 1024;
    int sum = joint_reduce(it.get_group(), first, last, plus<>());
    outputValues[0] = sum;

    // Apply a group algorithm to a set of values held directly by work-items.
    // The work-group reduces a number of values equal to the size of the group
    // and each work-item provides one value.
    int partial_sum = reduce_over_group(
        it.get_group(), inputValues[it.get_global_linear_id()], plus<>());
    outputValues[1] = partial_sum;
  });
});

host_accessor a{outputBuf};
assert(a[0] == 523776 && a[1] == 120);
