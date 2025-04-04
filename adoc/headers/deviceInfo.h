// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {
namespace info {
namespace device {

struct device_type;
struct vendor_id;
struct max_compute_units;
struct max_work_item_dimensions;
template <int Dimensions = 3> struct max_work_item_sizes;
struct max_work_group_size;
struct max_num_sub_groups;
struct sub_group_sizes;
struct preferred_vector_width_char;
struct preferred_vector_width_short;
struct preferred_vector_width_int;
struct preferred_vector_width_long;
struct preferred_vector_width_float;
struct preferred_vector_width_double;
struct preferred_vector_width_half;
struct native_vector_width_char;
struct native_vector_width_short;
struct native_vector_width_int;
struct native_vector_width_long;
struct native_vector_width_float;
struct native_vector_width_double;
struct native_vector_width_half;
struct max_clock_frequency;
struct address_bits;
struct max_mem_alloc_size;
struct image_support; // Deprecated
struct max_read_image_args;
struct max_write_image_args;
struct image2d_max_height;
struct image2d_max_width;
struct image3d_max_height;
struct image3d_max_width;
struct image3d_max_depth;
struct image_max_buffer_size;
struct max_samplers;
struct max_parameter_size;
struct mem_base_addr_align;
struct half_fp_config;
struct single_fp_config;
struct double_fp_config;
struct global_mem_cache_type;
struct global_mem_cache_line_size;
struct global_mem_cache_size;
struct global_mem_size;
struct max_constant_buffer_size; // Deprecated
struct max_constant_args;        // Deprecated
struct local_mem_type;
struct local_mem_size;
struct error_correction_support;
struct host_unified_memory;
struct atomic_memory_order_capabilities;
struct atomic_fence_order_capabilities;
struct atomic_memory_scope_capabilities;
struct atomic_fence_scope_capabilities;
struct profiling_timer_resolution;
struct is_endian_little;
struct is_available;
struct is_compiler_available; // Deprecated
struct is_linker_available;   // Deprecated
struct execution_capabilities;
struct queue_profiling;  // Deprecated
struct built_in_kernels; // Deprecated
struct built_in_kernel_ids;
struct platform;
struct name;
struct vendor;
struct driver_version;
struct profile;
struct version;
struct backend_version;
struct aspects;
struct extensions; // Deprecated
struct printf_buffer_size;
struct preferred_interop_user_sync;
struct parent_device;
struct partition_max_sub_devices;
struct partition_properties;
struct partition_affinity_domains;
struct partition_type_property;
struct partition_type_affinity_domain;

} // namespace device

enum class device_type : /* unspecified */ {
  cpu,         // Maps to OpenCL CL_DEVICE_TYPE_CPU
  gpu,         // Maps to OpenCL CL_DEVICE_TYPE_GPU
  accelerator, // Maps to OpenCL CL_DEVICE_TYPE_ACCELERATOR
  custom,      // Maps to OpenCL CL_DEVICE_TYPE_CUSTOM
  automatic,   // Maps to OpenCL CL_DEVICE_TYPE_DEFAULT
  host,
  all // Maps to OpenCL CL_DEVICE_TYPE_ALL
};

enum class partition_property : /* unspecified */ {
  no_partition,
  partition_equally,
  partition_by_counts,
  partition_by_affinity_domain
};

enum class partition_affinity_domain : /* unspecified */ {
  not_applicable,
  numa,
  L4_cache,
  L3_cache,
  L2_cache,
  L1_cache,
  next_partitionable
};

enum class local_mem_type : /* unspecified */ { none, local, global };

enum class fp_config : /* unspecified */ {
  denorm,
  inf_nan,
  round_to_nearest,
  round_to_zero,
  round_to_inf,
  fma,
  correctly_rounded_divide_sqrt,
  soft_float
};

enum class global_mem_cache_type : /* unspecified */ {
  none,
  read_only,
  read_write
};

enum class execution_capability : /* unspecified */ {
  exec_kernel,
  exec_native_kernel
};

} // namespace info
} // namespace sycl
