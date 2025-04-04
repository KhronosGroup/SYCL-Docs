// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

{
  context myContext;

  std::vector<buffer<int, 1>> bufferList{
      buffer<int, 1>{ptr, rng},
      buffer<int, 1>{ptr, rng, property::use_host_ptr{}},
      buffer<int, 1>{ptr, rng, property::context_bound{myContext}}};

  for (auto& buf : bufferList) {
    if (buf.has_property<property::context_bound>()) {
      auto prop = buf.get_property<property::context_bound>();
      assert(myContext == prop.get_context());
    }
  }
}
