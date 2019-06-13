namespace cl {
namespace sycl {
template <int dimensions = 1>
class nd_range {
public:

   /* -- common interface members -- */

  nd_range(range<dimensions> globalSize, range<dimensions> localSize,
           id<dimensions> offset = id<dimensions>());

  range<dimensions> get_global_range() const;
  range<dimensions> get_local_range() const;
  range<dimensions> get_group_range() const;
  id<dimensions> get_offset() const;
};
}  // namespace sycl
}  // namespace cl
