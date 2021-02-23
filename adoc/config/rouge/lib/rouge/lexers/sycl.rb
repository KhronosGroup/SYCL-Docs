# -*- coding: utf-8 -*- #
# frozen_string_literal: true

module Rouge
  module Lexers
    load_lexer 'cpp.rb'

    class Sycl < Cpp
      title "SYCL"
      desc "The standard SYCL C++ for heterogeneous computing from Khronos Group"

      tag 'sycl'

      sycl_data_types = %w(
        char2 char3 char4 char8 char16
        double2 double3 double4 double8 double16
        float2 float3 float4 float8 float16
        half half2 half3 half4 half8 half16
        int2 int3 int4 int8 int16
        long2 long3 long4 long8 long16
        longlong2 longlong3 longlong4 longlong8 longlong16
        schar2 schar3 schar4 schar8 schar16
        short2 short3 short4 short8 short16
        uchar2 uchar3 uchar4 uchar8 uchar16
        uint2 uint3 uint4 uint8 uint16
        ulong2 ulong3 ulong4 ulong8 ulong16
        ulonglong2 ulonglong3 ulonglong4 ulonglong8 ulonglong16
        ushort2 ushort3 ushort4 ushort8 ushort16
      )

      # Split member functions from free functions?
      sycl_functions = %w(
        aligned_alloc
        aligned_alloc_device
        aligned_alloc_host
        aligned_alloc_shared
        all_of
        any_of
        aspect_selector
        barrier
        byte_size
        copy
        create_sub_devices
        depends_on
        exclusive_scan
        fill
        free
        get
        get_access
        get_allocator
        get_backend
        get_backend_info
        get_context
        get_count
        get_device
        get_devices
        get_host_access
        get_info
        get_native
        get_native_context
        get_native_device
        get_native_mem
        get_native_queue
        get_platform
        get_platforms
        get_pointer_device
        get_pointer_type
        get_profiling_info
        get_property
        get_size
        get_wait_list
        group_all_of
        group_any_of
        group_barrier
        group_broadcast
        group_exclusive_scan
        group_inclusive_scan
        group_none_of
        group_reduce
        has
        has_extension
        has_property
        host_task
        inclusive_scan
        is_cpu
        is_gpu
        is_accelerator
        is_in_order
        is_sub_buffer
        make_buffer
        make_context
        make_device
        make_event
        make_image_sampler
        make_kernel
        make_kernel_bundle
        make_platform
        make_queue
        make_sampled_image
        make_sampler
        make_stream
        make_unsampled_image
        malloc
        malloc_device
        malloc_host
        malloc_shared
        mem_advise
        memcpy
        memset
        none_of
        parallel_for
        parallel_for_work_group
        parallel_for_work_item
        param_traits
        prefetch
        reduce
        reinterpret
        set_final_data
        set_write_back
        single_task
        submit
        throw_asynchronous
        update_host
        wait
        wait_and_throw
      )

      # Generic types used in SYCL pseudo code descriptions like Gen,
      # SGen, GenVec...
      sycl_generic_types = %w(
        charn
        doublen
        floatn
        genchar
        genfloat
        genfloatd
        genfloatf
        genfloath
        genfloatptr
        gengeodouble
        gengeofloat
        genhalf
        genint
        geninteger
        geninteger16bit
        geninteger32bit
        geninteger64bit
        geninteger8bit
        genintegerNbit
        genintptr
        genlong
        genlonglong
        genshort
        gentype
        genvector
        halfn
        igenchar
        igeninteger
        igeninteger16bit
        igeninteger32bit
        igeninteger64bit
        igeninteger8bit
        igenintegerNbit
        igenlonginteger
        intn
        longlongn
        longn
        scharn
        sgenfloat
        sgeninteger
        shortn
        ucharn
        ugenchar
        ugenint
        ugeninteger
        ugeninteger16bit
        ugeninteger32bit
        ugeninteger64bit
        ugeninteger8bit
        ugenintegerNbit
        ugenlong
        ugenlonginteger
        ugenlonglong
        ugenshort
        uintn
        ulonglongn
        ulongn
        ushortn
      )

      sycl_macros = %w(
        SYCL_EXTERNAL
      )

      sycl_namespaces = %w(
        info
        event_profiling
        kernel_device_specific
        property
        sycl
      )

      # Types, namespace and attributes used by the SYCL OpenCL backend
      sycl_opencl_keywords = %w(
        __kernel
        __read_only
        __read_write
        __write_only
        cl
        cl_bool
        cl_char
        cl_char16
        cl_char2
        cl_char3
        cl_char4
        cl_char8
        cl_command_queue
        cl_context
        cl_device_id
        cl_double
        cl_double16
        cl_double2
        cl_double3
        cl_double4
        cl_double8
        cl_event
        cl_exception
        cl_float
        cl_float16
        cl_float2
        cl_float3
        cl_float4
        cl_float8
        cl_half
        cl_half16
        cl_half2
        cl_half3
        cl_half4
        cl_half8
        cl_int
        cl_int16
        cl_int2
        cl_int3
        cl_int4
        cl_int8
        cl_kernel
        cl_long
        cl_long16
        cl_long2
        cl_long3
        cl_long4
        cl_long8
        cl_mem
        cl_pipe
        cl_platform_id
        cl_program
        cl_sampler
        cl_short
        cl_short16
        cl_short2
        cl_short3
        cl_short4
        cl_short8
        cl_uchar
        cl_uchar16
        cl_uchar2
        cl_uchar3
        cl_uchar4
        cl_uchar8
        cl_uint
        cl_uint16
        cl_uint2
        cl_uint3
        cl_uint4
        cl_uint8
        cl_ulong
        cl_ulong16
        cl_ulong2
        cl_ulong4
        cl_ulong8
        cl_ushort
        cl_ushort16
        cl_ushort2
        cl_ushort3
        cl_ushort4
        cl_ushort8
        event_t
      )

      sycl_types = %w(
        accelerator_selector
        access
        access_mode
        accessor
        all_devices_have
        any_device_has
        aspect
        async_exception
        async_handler
        atomic_ref
        backend
        backend_input_t
        backend_return_t
        backend_traits
        bit_and
        bit_or
        bit_xor
        buffer
        buffer_allocator
        constant_ptr
        context
        context_bound
        cpu_selector
        decorated_constant_ptr
        decorated_global_ptr
        decorated_local_ptr
        decorated_private_ptr
        default_selector
        device
        device_event
        device_type
        event
        event_command_status
        exception
        exception_list
        executable
        generic_ptr
        global_ptr
        gpu_selector
        group
        h_item
        handler
        host_accessor
        host_selector
        id
        image_allocator
        image_sampler
        input
        interop_handle
        is_property
        is_property_of
        item
        kernel
        kernel_bundle
        local_mem_type
        local_ptr
        logical_and
        logical_or
        marray
        maximum
        memory_order
        memory_scope
        minimum
        mode
        multi_ptr
        multiplies
        nd_item
        nd_range
        object
        partition_affinity_domain
        partition_property
        platform
        plus
        private_memory
        private_ptr
        property_list
        queue
        range
        raw_constant_ptr
        raw_generic_ptr
        raw_global_ptr
        raw_local_ptr
        raw_private_ptr
        reducer
        reduction
        sampled_image
        specialization_id
        stream
        sub_group
        target
        unsampled_image
        use_host_ptr
        use_mutex
        usm_allocator
        vec
      )

      # SYCL pre-defined variables and tags
      sycl_variables = %w(
        accelerator_selector_v
        all_devices_have_v
        any_device_has_v
        cpu_selector_v
        default_selector_v
        gpu_selector_v
        host_selector_v
        is_property_of_v
        is_property_v
        memory_order_acq_rel
        memory_order_acquire
        memory_order_relaxed
        memory_order_release
        memory_order_seq_cst
        memory_scope_device
        memory_scope_sub_group
        memory_scope_system
        memory_scope_work_group
        memory_scope_work_item
        no_init
        read_only
        write_only
      )

      # Here are some interesting tokens
      # https://pygments.org/docs/tokens/ unused in C++ we can reuse
      # in SYCL mode:
      # Comment::Preproc
      # Keyword.Pseudo
      # Keyword.Reserved
      # Literal::String::Regex
      # Literal::String::Symbol
      # Name::Attribute
      # Name.Builtin.Pseudo
      # Name.Function.Magic
      # Name.Other
      # Name.Variable.Magic
      # Operator.Word
      # Generic
      # Generic.Deleted
      # Generic.Emph
      # Generic.Error
      # Generic.Heading
      # Generic.Inserted
      # Generic.Output
      # Generic.Prompt
      # Generic.Strong
      # Generic.Subheading
      # Generic.Traceback


      # Insert some specific rules at the beginning of the statement
      # rule of the C++ lexer
      prepend :statements do
        rule %r/(?:#{sycl_data_types.join('|')})\b/,
             Keyword::Pseudo
        rule %r/(?:#{sycl_functions.join('|')})\b/,
             Name::Function::Magic
        rule %r/(?:#{sycl_generic_types.join('|')})\b/,
             Name::Builtin::Pseudo
        rule %r/(?:#{sycl_macros.join('|')})\b/,
             Generic::Output
        rule %r/(?:#{sycl_namespaces.join('|')})\b/,
             Generic::Heading
        rule %r/(?:#{sycl_opencl_keywords.join('|')})\b/,
             Name::Other
        rule %r/(?:#{sycl_types.join('|')})\b/,
             Keyword::Reserved
        rule %r/(?:#{sycl_variables.join('|')})\b/,
             Name::Variable::Magic
      end

    end
  end
end
