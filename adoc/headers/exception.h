// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

using async_handler = std::function<void(sycl::exception_list)>;

class exception : public virtual std::exception {
 public:
  exception(std::error_code ec, const std::string& what_arg);
  exception(std::error_code ec, const char* what_arg);
  exception(std::error_code ec);
  exception(int ev, const std::error_category& ecat,
            const std::string& what_arg);
  exception(int ev, const std::error_category& ecat, const char* what_arg);
  exception(int ev, const std::error_category& ecat);

  exception(context ctx, std::error_code ec, const std::string& what_arg);
  exception(context ctx, std::error_code ec, const char* what_arg);
  exception(context ctx, std::error_code ec);
  exception(context ctx, int ev, const std::error_category& ecat,
            const std::string& what_arg);
  exception(context ctx, int ev, const std::error_category& ecat,
            const char* what_arg);
  exception(context ctx, int ev, const std::error_category& ecat);

  const std::error_code& code() const noexcept;
  const std::error_category& category() const noexcept;

  const char* what() const;

  bool has_context() const noexcept;
  context get_context() const;
};

class exception_list {
  // Used as a container for a list of asynchronous exceptions
 public:
  using value_type = std::exception_ptr;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = std::size_t;
  using iterator = /*unspecified*/;
  using const_iterator = /*unspecified*/;

  size_type size() const;
  iterator begin() const; // first asynchronous exception
  iterator end() const;   // refer to past-the-end last asynchronous exception
};

enum class errc : /* unspecified */ {
  success = 0,
  runtime,
  kernel,
  accessor,
  nd_range,
  event,
  kernel_argument,
  build,
  invalid,
  memory_allocation,
  platform,
  profiling,
  feature_not_supported,
  kernel_not_supported,
  backend_mismatch
};

std::error_code make_error_code(errc e) noexcept;

const std::error_category& sycl_category() noexcept;

} // namespace sycl

namespace std {

template <> struct is_error_code_enum</* see below */> : true_type {};

} // namespace std
