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

{
  context myContext;

  std::vector<buffer<int, 1>> bufferList {
    buffer<int, 1>{},
    buffer<int, 1>{property::use_host_ptr{}},
    buffer<int, 1>{property::context_bound{myContext}}
  };

  for(auto& buf : bufferList) {
    if (buf.has_property<property::context_bound>()) {
      auto prop = buf.get_property<property::context_bound>();
      assert(myContext == prop.get_context());
    }
  }
}
