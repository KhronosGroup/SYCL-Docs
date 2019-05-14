namespace cl {
namespace sycl {
template <typename T, int Dimensions = 1>
class private_memory {
 public:
  // Construct based directly off the number of work-items
  private_memory(const group<Dimensions> &);

  // Access the instance for the current work-item
  T &operator()(const h_item<Dimensions> &id);
};
}
}
