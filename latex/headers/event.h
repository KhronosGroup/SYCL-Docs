namespace cl {
namespace sycl {

class event {
 public:
  event();

  event(cl_event clEvent, const context& syclContext);

  /* -- common interface members -- */

  cl_event get();

  bool is_host() const;

  vector_class<event> get_wait_list();

  void wait();

  static void wait(const vector_class<event> &eventList);

  void wait_and_throw();

  static void wait_and_throw(const vector_class<event> &eventList);

  template <info::event param>
  typename info::param_traits<info::event, param>::return_type get_info() const;

  template <info::event_profiling param>
  typename info::param_traits<info::event_profiling, param>::return_type get_profiling_info() const;
};

}  // namespace sycl
}  // namespace cl
