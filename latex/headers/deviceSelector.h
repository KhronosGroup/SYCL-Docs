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
class default_selector : public device_selector {
 public:
  default_selector();

  virtual ~default_selector();

  virtual int operator()(const device &device) const;
};

class opencl_selector : public device_selector {
 public:
  opencl_selector();

  virtual ~opencl_selector();

  virtual int operator()(const device &device) const;
};

class cpu_selector : public device_selector {
 public:
  cpu_selector();

  virtual ~cpu_selector();

  virtual int operator()(const device &device) const;
};

class gpu_selector : public device_selector {
 public:
  gpu_selector();

  virtual ~gpu_selector();

  virtual int operator()(const device &device) const;
};

class host_selector : public device_selector {
 public:
  host_selector();

  virtual ~host_selector();

  virtual int operator()(const device &device) const;
};

}  // namespace sycl
}  // namespace cl
