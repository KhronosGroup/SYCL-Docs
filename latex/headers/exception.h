namespace cl {
namespace sycl {

using async_handler = function_class<void(cl::sycl::exception_list)>;

class exception {
 public:
  const char *what() const;

  bool has_context() const;

  context get_context() const;

  cl_int get_cl_code() const;
};

class exception_list {
  // Used as a container for a list of asynchronous exceptions
 public:
  using value_type = exception_ptr_class;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = std::size_t;
  using iterator = /*unspecified*/;
  using const_iterator = /*unspecified*/;

  size_type size() const;
  iterator begin() const;  // first asynchronous exception
  iterator end() const;    // refer to past-the-end last asynchronous exception
};

class runtime_error : public exception;

class kernel_error : public runtime_error;

class accessor_error : public runtime_error;

class nd_range_error : public runtime_error;

class event_error : public runtime_error;

class invalid_parameter_error : public runtime_error;

class device_error : public exception;

class compile_program_error : public device_error;

class link_program_error : public device_error;

class invalid_object_error : public device_error;

class memory_allocation_error : public device_error;

class platform_error : public device_error;

class profiling_error : public device_error;

class feature_not_supported : public device_error;

}  // namespace sycl
}  // namespace cl
