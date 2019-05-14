namespace cl {
namespace sycl {
class kernel {
 private:
  friend class program;

  // The default object is not valid because there is no
  // program or cl_kernel associated with it
  kernel();

 public:

  kernel(cl_kernel clKernel, const context& syclContext);

  /* -- common interface members -- */

  cl_kernel get() const;

  bool is_host() const;

  context get_context() const;

  program get_program() const;

  template <info::kernel param>
  typename info::param_traits<info::kernel, param>::return_type
  get_info() const;

  template <info::kernel_work_group param>
  typename info::param_traits<info::kernel_work_group, param>::return_type
  get_work_group_info(const device &dev) const;
};
}  // namespace sycl
}  // namespace cl
