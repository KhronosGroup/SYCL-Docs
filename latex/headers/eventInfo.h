namespace cl {
namespace sycl {
namespace info {
enum class event: int {
  command_execution_status,
  reference_count
};

enum class event_command_status : int {
  submitted,
  running,
  complete
};

enum class event_profiling : int {
  command_submit,
  command_start,
  command_end
};
}  // namespace info
}  // namespace sycl
}  // namespace cl
