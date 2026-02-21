// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

template <typename T> class specialization_id {
 public:
  using value_type = T;

  template <class... Args> explicit constexpr specialization_id(Args&&... args);

  specialization_id(const specialization_id& rhs) = delete;
  specialization_id(specialization_id&& rhs) = delete;
  specialization_id& operator=(const specialization_id& rhs) = delete;
  specialization_id& operator=(specialization_id&& rhs) = delete;
};

} // namespace sycl
