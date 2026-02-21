// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

enum class addressing_mode : /* unspecified */ {
  mirrored_repeat,
  repeat,
  clamp_to_edge,
  clamp,
  none
};

enum class filtering_mode : /* unspecified */ { nearest, linear };

enum class coordinate_normalization_mode : /* unspecified */ {
  normalized,
  unnormalized
};

struct image_sampler {
  addressing_mode addressing;
  coordinate_normalization_mode coordinate;
  filtering_mode filtering;
};

} // namespace sycl
