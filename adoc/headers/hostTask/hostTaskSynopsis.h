// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

class interop_handle {
 private:

  interop_handle(__unspecified__);

 public:

  interop_handle() = delete;

  backend get_backend() const noexcept;

  template <backend Backend, typename dataT, int dims, access_mode accessMode,
            target accessTarget, access::placeholder isPlaceholder>
  backend_return_t<Backend, buffer<dataT, dims>>
  get_native_mem(const accessor<dataT, dims, accessMode, accessTarget,
                                isPlaceholder> &bufferAccessor) const;

  template <backend Backend, typename dataT, int dims, access_mode accMode>
  backend_return_t<Backend, unsampled_image<dims>>
  get_native_mem(
      const unsampled_image_accessor<dataT, dims, accMode, image_target::device>
          &imageAcc) const;

  template <backend Backend, typename dataT, int dims>
  backend_return_t<Backend, sampled_image<dims>>
  get_native_mem(
      const sampled_image_accessor<dataT, dims, image_target::device> &imageAcc)
      const;

  template <backend Backend>
  backend_return_t<Backend, queue> get_native_queue() const;

  template <backend Backend>
  backend_return_t<Backend, device> get_native_device() const;

  template <backend Backend>
  backend_return_t<Backend, context> get_native_context() const;

};

class handler {
  ...

 public:

  template <typename T>
  void host_task(T &&hostTaskCallable);

  ...
};

}  // namespace sycl
