namespace cl {
namespace sycl {
namespace access {
enum class target {
  global_buffer = 2014,
  constant_buffer,
  local,
  image,
  host_buffer,
  host_image,
  image_array
};

}  // namespace access
}  // namespace sycl
}  // namespace cl
