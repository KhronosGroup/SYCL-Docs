headers / hostTask / classInteropHandle /
    getnativeX.h
    // Copyright (c) 2011-2025 The Khronos Group, Inc.
    // SPDX-License-Identifier: MIT

    template <backend Backend, typename DataT, int Dims, access_mode AccMode,
              target AccTarget, access::placeholder IsPlaceholder>
    backend_return_t<Backend, buffer<DataT, Dims>>
    get_native_mem(const accessor<DataT, Dims, AccMode, AccTarget, // (1)
                                  IsPlaceholder>& bufferAcc) const;

template <backend Backend, typename DataT, int Dims, access_mode AccMode>
backend_return_t<Backend, unsampled_image<Dims>> get_native_mem( // (2)
    const unsampled_image_accessor<DataT, Dims, AccMode, image_target::device>&
        imageAcc) const;

template <backend Backend, typename DataT, int Dims>
backend_return_t<Backend, sampled_image<Dims>> get_native_mem( // (3)
    const sampled_image_accessor<DataT, Dims, image_target::device>& imageAcc)
    const;

template <backend Backend>
backend_return_t<Backend, queue> get_native_queue() const; // (4)

template <backend Backend>
backend_return_t<Backend, device> get_native_device() const; // (5)

template <backend Backend>
backend_return_t<Backend, context> get_native_context() const; // (6)
