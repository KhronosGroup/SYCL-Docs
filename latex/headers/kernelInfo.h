namespace cl {
namespace sycl {
namespace info {
enum class kernel: int {
  function_name,
  num_args,
  context,
  program,
  reference_count,
  attributes
};

enum class kernel_work_group: int {
 global_work_size,
 work_group_size,
 compile_work_group_size,
 preferred_work_group_size_multiple,
 private_mem_size
};

}  // namespace info
}  // namespace sycl
}  // namespace cl
