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
