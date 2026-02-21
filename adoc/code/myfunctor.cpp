// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

class RandomFiller {
 public:
  RandomFiller(accessor<int> ptr) : ptr_{ptr} {
    std::random_device hwRand;
    std::uniform_int_distribution<> r{1, 100};
    randomNum_ = r(hwRand);
  }
  void operator()(item<1> item) const { ptr_[item.get_id()] = randomNum_; }

 private:
  accessor<int> ptr_;
  int randomNum_;
};

void workFunction(buffer<int, 1>& b, queue& q, const range<1> r) {
  q.submit([&](handler& cgh) {
    accessor ptr{b, cgh};
    RandomFiller filler{ptr};

    cgh.parallel_for(r, filler);
  });
}
