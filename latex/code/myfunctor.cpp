// Copyright (c) 2012-2020 The Khronos Group Inc.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

class RandomFiller {
 public:
  RandomFiller(accessor<int, 1, access::mode::read_write,
                       access::target::global_buffer> ptr)
      : ptr_ { ptr } {
    std::random_device hwRand;
    std::uniform_int_distribution<> r{1, 100};
    randomNum_ = r(hwRand);
  }
  void operator()(item<1> item) { ptr_[item.get_id()] = get_random(); }
  int get_random() { return randomNum_; }

 private:
  accessor<int, 1, access::mode::read_write, access::target::global_buffer>
      ptr_;
  int randomNum_;
};

void workFunction(buffer<int, 1>& b, queue& q, const range<1> r) {
    myQueue.submit([&](handler& cgh) {
      auto ptr = buf.get_access<access::mode::read_write>(cgh);
      RandomFiller filler { ptr };

      cgh.parallel_for(r, filler);
    });
}
