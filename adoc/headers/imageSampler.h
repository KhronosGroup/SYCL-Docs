// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
enum class addressing_mode: unsigned int {
  mirrored_repeat,
  repeat,
  clamp_to_edge,
  clamp,
  none
};

enum class filtering_mode: unsigned int {
  nearest,
  linear
};

enum class coordinate_normalization_mode : unsigned int {
  normalized,
  unnormalized
};

struct image_sampler {
  addressing_mode addressing;
  coordinate_mode coordinate;
  filtering_mode filtering;
};
}  // namespace sycl
