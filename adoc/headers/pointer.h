// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

template <typename ElementType, access::address_space Space,
          access::decorated IsDecorated>
class multi_ptr;

// Template specialization aliases for different pointer address spaces

template <typename ElementType,
          access::decorated IsDecorated = access::decorated::legacy>
using global_ptr =
    multi_ptr<ElementType, access::address_space::global_space, IsDecorated>;

template <typename ElementType,
          access::decorated IsDecorated = access::decorated::legacy>
using local_ptr =
    multi_ptr<ElementType, access::address_space::local_space, IsDecorated>;

// Deprecated in SYCL 2020
template <typename ElementType>
using constant_ptr =
    multi_ptr<ElementType, access::address_space::constant_space,
              access::decorated::legacy>;

template <typename ElementType,
          access::decorated IsDecorated = access::decorated::legacy>
using private_ptr =
    multi_ptr<ElementType, access::address_space::private_space, IsDecorated>;

template <typename ElementType,
          access::decorated IsDecorated = access::decorated::legacy>
using generic_ptr =
    multi_ptr<ElementType, access::address_space::generic_space, IsDecorated>;

// Template specialization aliases for different pointer address spaces.
// The interface exposes non-decorated pointer while keeping the
// address space information internally.

template <typename ElementType>
using raw_global_ptr =
    multi_ptr<ElementType, access::address_space::global_space,
              access::decorated::no>;

template <typename ElementType>
using raw_local_ptr = multi_ptr<ElementType, access::address_space::local_space,
                                access::decorated::no>;

template <typename ElementType>
using raw_private_ptr =
    multi_ptr<ElementType, access::address_space::private_space,
              access::decorated::no>;

template <typename ElementType>
using raw_generic_ptr =
    multi_ptr<ElementType, access::address_space::generic_space,
              access::decorated::no>;

// Template specialization aliases for different pointer address spaces.
// The interface exposes decorated pointer.

template <typename ElementType>
using decorated_global_ptr =
    multi_ptr<ElementType, access::address_space::global_space,
              access::decorated::yes>;

template <typename ElementType>
using decorated_local_ptr =
    multi_ptr<ElementType, access::address_space::local_space,
              access::decorated::yes>;

template <typename ElementType>
using decorated_private_ptr =
    multi_ptr<ElementType, access::address_space::private_space,
              access::decorated::yes>;

template <typename ElementType>
using decorated_generic_ptr =
    multi_ptr<ElementType, access::address_space::generic_space,
              access::decorated::yes>;

} // namespace sycl
