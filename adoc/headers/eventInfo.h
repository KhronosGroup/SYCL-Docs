// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
namespace info {
namespace event {

struct command_execution_status;

}  // namespace event

enum class event_command_status : int {
  submitted,
  running,
  complete
};

namespace event_profiling {

struct command_submit;
struct command_start;
struct command_end;

}  // namespace event_profiling
}  // namespace info
}  // namespace sycl
