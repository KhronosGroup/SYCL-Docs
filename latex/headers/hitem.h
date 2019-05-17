namespace cl {
namespace sycl {
template <int dimensions>
class h_item {
public:
  h_item() = delete;

  /* -- common interface members -- */

  item<dimensions, false> get_global() const;

  item<dimensions, false> get_local() const;

  item<dimensions, false> get_logical_local() const;

  item<dimensions, false> get_physical_local() const;

  range<dimensions> get_global_range() const;

  size_t get_global_range(int dimension) const;

  id<dimensions> get_global_id() const;

  size_t get_global_id(int dimension) const;

  range<dimensions> get_local_range() const;

  size_t get_local_range(int dimension) const;

  id<dimensions> get_local_id() const;

  size_t get_local_id(int dimension) const;

  range<dimensions> get_logical_local_range() const;

  size_t get_logical_local_range(int dimension) const;

  id<dimensions> get_logical_local_id() const;

  size_t get_logical_local_id(int dimension) const;

  range<dimensions> get_physical_local_range() const;

  size_t get_physical_local_range(int dimension) const;

  id<dimensions> get_physical_local_id() const;

  size_t get_physical_local_id(int dimension) const;

};
}  // namespace sycl
}  // namespace cl
