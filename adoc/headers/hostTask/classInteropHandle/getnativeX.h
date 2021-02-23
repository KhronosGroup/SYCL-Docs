headers/hostTask/classInteropHandle/getnativeX.h
// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

template <backend Backend, typename dataT, int dims, access_mode accMode,
          target accTarget, access::placeholder isPlaceholder>
backend_return_t<Backend, buffer<dataT, dims>>
get_native_mem(const accessor<dataT, dims, accMode, accTarget,                // (1)
                              isPlaceholder> &bufferAcc) const;

template <backend Backend, typename dataT, int dims, access_mode accMode>
backend_return_t<Backend, unsampled_image<dims>>
get_native_mem(                                                               // (2)
  const unsampled_image_accessor<dataT, dims, accMode, image_target::device> &imageAcc) const;

template <backend Backend, typename dataT, int dims>
backend_return_t<Backend, sampled_image<dims>>
get_native_mem(                                                               // (3)
  const sampled_image_accessor<dataT, dims, image_target::device> &imageAcc) const;

template <backend Backend>
backend_return_t<Backend, queue> get_native_queue() const;         // (4)

template <backend Backend>
backend_return_t<Backend, device> get_native_device() const;       // (5)

template <backend Backend>
backend_return_t<Backend, context> get_native_context() const;     // (6)
