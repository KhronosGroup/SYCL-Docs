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
