// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
namespace property {
namespace image {
class use_host_ptr {
 public:
  use_host_ptr() = default;
};

class use_mutex {
 public:
  use_mutex(std::mutex& mutexRef);

  std::mutex* get_mutex_ptr() const;
};

class context_bound {
 public:
  context_bound(context boundContext);

  context get_context() const;
};
} // namespace image
} // namespace property
} // namespace sycl
