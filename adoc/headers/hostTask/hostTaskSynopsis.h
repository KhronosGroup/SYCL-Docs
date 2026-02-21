// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

class interop_handle {
 private:
  interop_handle(__unspecified__);

 public:
  interop_handle() = delete;

  backend get_backend() const noexcept;

  template <backend Backend, typename DataT, int Dims, access_mode AccessMode,
            target AccessTarget, access::placeholder isPlaceholder>
  backend_return_t<Backend, buffer<DataT, Dims>>
  get_native_mem(const accessor<DataT, Dims, AccessMode, AccessTarget,
                                isPlaceholder>& bufferAccessor) const;

  template <backend Backend, typename DataT, int Dims, access_mode AccMode>
  backend_return_t<Backend, unsampled_image<Dims>> get_native_mem(
      const unsampled_image_accessor<DataT, Dims, AccMode,
                                     image_target::device>& imageAcc) const;

  template <backend Backend, typename DataT, int Dims>
  backend_return_t<Backend, sampled_image<Dims>> get_native_mem(
      const sampled_image_accessor<DataT, Dims, image_target::device>& imageAcc)
      const;

  template <backend Backend>
  backend_return_t<Backend, queue> get_native_queue() const;

  template <backend Backend>
  backend_return_t<Backend, device> get_native_device() const;

  template <backend Backend>
  backend_return_t<Backend, context> get_native_context() const;
};

class handler {
 public:
  // ...

  template <typename T>
  void host_task(T&& hostTaskCallable);

  // ...
};

} // namespace sycl
