namespace cl {
namespace sycl {
namespace access {
enum class mode {
  read = 1024,
  write,
  read_write,
  discard_write,
  discard_read_write,
  atomic
};
}  // namespace access
}  // namespace sycl
}  // namespace cl
