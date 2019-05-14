namespace cl {
namespace sycl {
class context {
 public:
  explicit context(async_handler asyncHandler = {});

  context(const device &dev, async_handler asyncHandler = {});

  context(const platform &plt, async_handler asyncHandler = {});

  context(const vector_class<device> &deviceList,
    async_handler asyncHandler = {});

  context(cl_context clContext, async_handler asyncHandler = {});

  /* -- common interface members -- */

  cl_context get() const;

  bool is_host() const;

  platform get_platform() const;

  vector_class<device> get_devices() const;

  template <info::context param>
  typename info::param_traits<info::context, param>::return_type get_info() const;
};
}  // namespace sycl
}  // namespace cl
