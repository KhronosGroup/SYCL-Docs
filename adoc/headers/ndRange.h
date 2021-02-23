// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
template <int dimensions = 1>
class nd_range {
public:

   /* -- common interface members -- */

  // The offset is deprecated in SYCL 2020.
  nd_range(range<dimensions> globalSize, range<dimensions> localSize,
           id<dimensions> offset = id<dimensions>());

  range<dimensions> get_global_range() const;
  range<dimensions> get_local_range() const;
  range<dimensions> get_group_range() const;
  id<dimensions> get_offset() const; // Deprecated in SYCL 2020.
};
}  // namespace sycl
