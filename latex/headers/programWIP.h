namespace cl {
namespace sycl {
enum class program_state {
  none,
  compiled,
  linked
};

class program {
 public:
  program() = delete;

  explicit program(const context &context);

  program(const context &context, vector_class<device> deviceList);

  program(vector_class<program> programList, string_class linkOptions = "");

  program(const context &context, cl_program clProgram);

  /* -- common interface members -- */

  cl_program get() const;

  bool is_host() const;

  template <typename kernelT>
  void compile_with_kernel_type(string_class compileOptions = "");

  void compile_with_source(string_class kernelSource, string_class compileOptions = "");

  template <typename kernelT>
  void build_with_kernel_type(string_class buildOptions = "");

  void build_with_source(string_class kernelSource, string_class buildOptions = "");

  void link(string_class linkOptions = "");

  template <typename kernelT>
  bool has_kernel<kernelT>() const;

  bool has_kernel(string_class kernelName) const;

  template <typename kernelT>
  kernel get_kernel<kernelT>() const;

  kernel get_kernel(string_class kernelName) const;

  template <info::program param>
  typename info::param_traits<info::program, param>::return_type
    get_info() const;

  vector_class<vector_class<char>> get_binaries() const;

  context get_context() const;

  vector_class<device> get_devices() const;

  string_class get_compile_options() const;

  string_class get_link_options() const;

  string_class get_build_options() const;

  program_state get_state() const;
};
}  // namespace sycl
}  // namespace cl
