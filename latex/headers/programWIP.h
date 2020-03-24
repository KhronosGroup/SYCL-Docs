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
enum class program_state {
  none,
  compiled,
  linked
};

class program {
 public:
  program() = delete;

  explicit program(const context &context,
                   const property_list &propList = {});

  program(const context &context, vector_class<device> deviceList,
          const property_list &propList = {});

  program(vector_class<program> &programList,
          const property_list &propList = {});

  program(vector_class<program> &programList, string_class linkOptions,
          const property_list &propList = {});

  program(const context &context, cl_program clProgram);

  /* -- common interface members -- */

  /* -- property interface members -- */

  cl_program get() const;

  bool is_host() const;

  template <typename kernelT>
  void compile_with_kernel_type(string_class compileOptions = "");

  void compile_with_source(string_class kernelSource,
                           string_class compileOptions = "");

  template <typename kernelT>
  void build_with_kernel_type(string_class buildOptions = "");

  void build_with_source(string_class kernelSource,
                         string_class buildOptions = "");

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
