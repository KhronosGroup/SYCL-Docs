// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

enum class stream_manipulator : /* unspecified */ {
  flush,
  dec,
  hex,
  oct,
  noshowbase,
  showbase,
  noshowpos,
  showpos,
  endl,
  fixed,
  scientific,
  hexfloat,
  defaultfloat
};

const stream_manipulator flush = stream_manipulator::flush;

const stream_manipulator dec = stream_manipulator::dec;

const stream_manipulator hex = stream_manipulator::hex;

const stream_manipulator oct = stream_manipulator::oct;

const stream_manipulator noshowbase = stream_manipulator::noshowbase;

const stream_manipulator showbase = stream_manipulator::showbase;

const stream_manipulator noshowpos = stream_manipulator::noshowpos;

const stream_manipulator showpos = stream_manipulator::showpos;

const stream_manipulator endl = stream_manipulator::endl;

const stream_manipulator fixed = stream_manipulator::fixed;

const stream_manipulator scientific = stream_manipulator::scientific;

const stream_manipulator hexfloat = stream_manipulator::hexfloat;

const stream_manipulator defaultfloat = stream_manipulator::defaultfloat;

__precision_manipulator__ setprecision(int precision);

__width_manipulator__ setw(int width);

class stream {
 public:
  stream(size_t totalBufferSize, size_t workItemBufferSize,
         handler& cgh, const property_list& propList = {});

  /* -- common interface members -- */

  /* -- property interface members -- */

  size_t size() const noexcept;

  // Deprecated
  size_t get_size() const;

  size_t get_work_item_buffer_size() const;

  /* get_max_statement_size() has the same functionality as
     get_work_item_buffer_size(), and is provided for backward compatibility.
     get_max_statement_size() is a deprecated query. */
  size_t get_max_statement_size() const;
};

template <typename T> const stream& operator<<(const stream& os, const T& rhs);

} // namespace sycl
