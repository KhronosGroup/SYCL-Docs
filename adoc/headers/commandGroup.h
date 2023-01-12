// Copyright (c) 2011-2023 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
class command_group {
 public:
  template <typename FunctorT>
  command_group(queue& primaryQueue, const FunctorT& lambda);

  template <typename FunctorT>
  command_group(queue& primaryQueue, queue& secondaryQueue,
                const FunctorT& lambda);

  ~command_group();

  event start_event();

  event kernel_event();

  event complete_event();
};
} // namespace sycl
