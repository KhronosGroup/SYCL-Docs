namespace cl {
namespace sycl {
template <int dimensions = 1, bool with_offset = true>
struct item {
  item() = delete;

   /* -- common interface members -- */

  id<dimensions> get_id() const;

  size_t get_id(int dimension) const;

  size_t operator[](int dimension) const;

  range<dimensions> get_range() const;

  size_t get_range(int dimension) const;

  // only available if with_offset is true
  id<dimensions> get_offset() const;

  // only available if with_offset is false
  operator item<dimensions, true>() const;

  size_t get_linear_id() const;
};
}  // namespace sycl
}  // namespace cl
