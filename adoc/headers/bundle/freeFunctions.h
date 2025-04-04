// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

namespace sycl {

enum class bundle_state : /* unspecified */ { input, object, executable };

class kernel_id { /* ... */
};

template <bundle_state State> class kernel_bundle { /* ... */
};

template <typename KernelName> kernel_id get_kernel_id();

std::vector<kernel_id> get_kernel_ids();

template <bundle_state State>
kernel_bundle<State> get_kernel_bundle(const context& ctxt);

template <bundle_state State>
kernel_bundle<State> get_kernel_bundle(const context& ctxt,
                                       const std::vector<kernel_id>& kernelIds);

template <typename KernelName, bundle_state State>
kernel_bundle<State> get_kernel_bundle(const context& ctxt);

template <bundle_state State>
kernel_bundle<State> get_kernel_bundle(const context& ctxt,
                                       const std::vector<device>& devs);

template <bundle_state State>
kernel_bundle<State> get_kernel_bundle(const context& ctxt,
                                       const std::vector<device>& devs,
                                       const std::vector<kernel_id>& kernelIds);

template <typename KernelName, bundle_state State>
kernel_bundle<State> get_kernel_bundle(const context& ctxt,
                                       const std::vector<device>& devs);

template <bundle_state State, typename Selector>
kernel_bundle<State> get_kernel_bundle(const context& ctxt, Selector selector);

template <bundle_state State, typename Selector>
kernel_bundle<State> get_kernel_bundle(const context& ctxt,
                                       const std::vector<device>& devs,
                                       Selector selector);

template <bundle_state State> bool has_kernel_bundle(const context& ctxt);

template <bundle_state State>
bool has_kernel_bundle(const context& ctxt,
                       const std::vector<kernel_id>& kernelIds);

template <typename KernelName, bundle_state State>
bool has_kernel_bundle(const context& ctxt);

template <bundle_state State>
bool has_kernel_bundle(const context& ctxt, const std::vector<device>& devs);

template <bundle_state State>
bool has_kernel_bundle(const context& ctxt, const std::vector<device>& devs,
                       const std::vector<kernel_id>& kernelIds);

template <typename KernelName, bundle_state State>
bool has_kernel_bundle(const context& ctxt, const std::vector<device>& devs);

bool is_compatible(const std::vector<kernel_id>& kernelIds, const device& dev);

template <typename KernelName> bool is_compatible(const device& dev);

template <bundle_state State>
kernel_bundle<State> join(const std::vector<kernel_bundle<State>>& bundles);

kernel_bundle<bundle_state::object>
compile(const kernel_bundle<bundle_state::input>& inputBundle,
        const property_list& propList = {});

kernel_bundle<bundle_state::object>
compile(const kernel_bundle<bundle_state::input>& inputBundle,
        const std::vector<device>& devs, const property_list& propList = {});

kernel_bundle<bundle_state::executable>
link(const kernel_bundle<bundle_state::object>& objectBundle,
     const property_list& propList = {});

kernel_bundle<bundle_state::executable>
link(const std::vector<kernel_bundle<bundle_state::object>>& objectBundles,
     const property_list& propList = {});

kernel_bundle<bundle_state::executable>
link(const kernel_bundle<bundle_state::object>& objectBundle,
     const std::vector<device>& devs, const property_list& propList = {});

kernel_bundle<bundle_state::executable>
link(const std::vector<kernel_bundle<bundle_state::object>>& objectBundles,
     const std::vector<device>& devs, const property_list& propList = {});

kernel_bundle<bundle_state::executable>
build(const kernel_bundle<bundle_state::input>& inputBundle,
      const property_list& propList = {});

kernel_bundle<bundle_state::executable>
build(const kernel_bundle<bundle_state::input>& inputBundle,
      const std::vector<device>& devs, const property_list& propList = {});

} // namespace sycl
