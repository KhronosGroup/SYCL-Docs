// Copyright (c) 2011-2020 The Khronos Group, Inc.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

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
