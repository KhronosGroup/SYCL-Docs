namespace cl {
namespace sycl {
class queue {
 public:
  explicit queue(const property_list &propList = {});

  queue(const async_handler &asyncHandler,
    const property_list &propList = {});

  queue(const device_selector &deviceSelector,
    const property_list &propList = {});

  queue(const device_selector &deviceSelector,
      const async_handler &asyncHandler, const property_list &propList = {});

  queue(const device &syclDevice, const property_list &propList = {});

  queue(const device &syclDevice, const async_handler &asyncHandler,
    const property_list &propList = {});

  queue(const context &syclContext, const device_selector &deviceSelector,
    const property_list &propList = {});

  queue(const context &syclContext, const device_selector &deviceSelector,
    const async_handler &asyncHandler, const property_list &propList = {});

  queue(cl_command_queue clQueue, const context& syclContext,
    const async_handler &asyncHandler = {});

  /* -- common interface members -- */

  /* -- property interface members -- */

  cl_command_queue get() const;

  context get_context() const;

  device get_device() const;

  bool is_host() const;

  template <info::queue param>
  typename info::param_traits<info::queue, param>::return_type get_info() const;

  template <typename T>
  event submit(T cgf);

  template <typename T>
  event submit(T cgf, const queue &secondaryQueue);

  void wait();

  void wait_and_throw();

  void throw_asynchronous();
};
}  // namespace sycl
}  // namespace cl
