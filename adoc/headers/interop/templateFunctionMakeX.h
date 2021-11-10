// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

template<backend Backend>
platform make_platform(const backend_input_t<Backend, platform> &backendObject);

template<backend Backend>
device make_device(const backend_input_t<Backend, device> &backendObject);

template<backend Backend>
context make_context(const backend_input_t<Backend, context> &backendObject,
                     const async_handler asyncHandler = {});

template<backend Backend>
queue make_queue(const backend_input_t<Backend, queue> &backendObject,
                 const context &targetContext,
                 const async_handler asyncHandler = {});

template<backend Backend>
event make_event(const backend_input_t<Backend, event> &backendObject,
                 const context &targetContext);

template <backend Backend, typename T, int Dimensions = 1,
          typename AllocatorT = buffer_allocator<std::remove_const_t<T>>>
buffer<T, Dimensions, AllocatorT>
make_buffer(const backend_input_t<Backend, buffer<T, Dimensions, AllocatorT>>
                &backendObject,
            const context &targetContext, event availableEvent);

template <backend Backend, typename T, int Dimensions = 1,
          typename AllocatorT = buffer_allocator<std::remove_const_t<T>>>
buffer<T, Dimensions, AllocatorT>
make_buffer(const backend_input_t<Backend, buffer<T, Dimensions, AllocatorT>>
                &backendObject,
            const context &targetContext);

template <backend Backend, int Dimensions = 1,
          typename AllocatorT = sycl::image_allocator>
sampled_image<Dimensions, AllocatorT> make_sampled_image(
    const backend_input_t<Backend, sampled_image<Dimensions, AllocatorT>>
        &backendObject,
    const context &targetContext, image_sampler imageSampler,
    event availableEvent);

template <backend Backend, int Dimensions = 1,
          typename AllocatorT = sycl::image_allocator>
sampled_image<Dimensions, AllocatorT> make_sampled_image(
    const backend_input_t<Backend, sampled_image<Dimensions, AllocatorT>>
        &backendObject,
    const context &targetContext, image_sampler imageSampler);

template <backend Backend, int Dimensions = 1,
          typename AllocatorT = sycl::image_allocator>
unsampled_image<Dimensions, AllocatorT> make_unsampled_image(
    const backend_input_t<Backend, unsampled_image<Dimensions, AllocatorT>>
        &backendObject,
    const context &targetContext, event availableEvent);

template <backend Backend, int Dimensions = 1,
          typename AllocatorT = sycl::image_allocator>
unsampled_image<Dimensions, AllocatorT> make_unsampled_image(
    const backend_input_t<Backend, unsampled_image<Dimensions, AllocatorT>>
        &backendObject,
    const context &targetContext);

template<backend Backend, bundle_state State>
kernel_bundle<State> make_kernel_bundle(
    const backend_input_t<Backend, kernel_bundle<State>> &backendObject,
    const context &targetContext);

template<backend Backend>
kernel make_kernel(const backend_input_t<Backend, kernel> &backendObject,
                   const context &targetContext);

}  // namespace sycl
