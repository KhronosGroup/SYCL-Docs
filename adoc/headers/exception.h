// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

using async_handler = std::function<void(sycl::exception_list)>;

class exception : public virtual std::exception {
 public:
    exception(std::error_code ec, const std::string& what_arg);
    exception(std::error_code ec, const char * what_arg);
    exception(std::error_code ec);
    exception(int ev, const std::error_category& ecat, const std::string& what_arg);
    exception(int ev, const std::error_category& ecat, const char* what_arg);
    exception(int ev, const std::error_category& ecat);

    exception(context ctx, std::error_code ec, const std::string& what_arg);
    exception(context ctx, std::error_code ec, const char* what_arg);
    exception(context ctx, std::error_code ec);
    exception(context ctx, int ev, const std::error_category& ecat, const std::string& what_arg);
    exception(context ctx, int ev, const std::error_category& ecat, const char* what_arg);
    exception(context ctx, int ev, const std::error_category& ecat);

    const std::error_code& code() const noexcept;
    const std::error_category& category() const noexcept;

    const char *what() const;

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
  iterator begin() const;  // first asynchronous exception
  iterator end() const;    // refer to past-the-end last asynchronous exception
};

enum class errc {
  success = 0,
  runtime = /* implementation-defined */,
  kernel = /* implementation-defined */,
  accessor = /* implementation-defined */,
  nd_range = /* implementation-defined */,
  event = /* implementation-defined */,
  kernel_argument = /* implementation-defined */,
  build = /* implementation-defined */,
  invalid = /* implementation-defined */,
  memory_allocation = /* implementation-defined */,
  platform = /* implementation-defined */,
  profiling = /* implementation-defined */,
  feature_not_supported = /* implementation-defined */,
  kernel_not_supported = /* implementation-defined */,
  backend_mismatch = /* implementation-defined */
};

template<backend b>
using errc_for = typename backend_traits<b>::errc;

std::error_code make_error_code(errc e) noexcept;

const std::error_category& sycl_category() noexcept;

template<backend b>
const std::error_category& error_category_for() noexcept;

}  // namespace sycl

namespace std {

  template <>
  struct is_error_code_enum<see-below> : true_type {};

}  // namespace std
