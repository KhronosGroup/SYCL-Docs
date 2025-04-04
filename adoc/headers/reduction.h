// Copyright (c) 2011-2025 The Khronos Group, Inc.
// SPDX-License-Identifier: MIT

template <typename BufferT, typename BinaryOperation>
__unspecified__ reduction(BufferT vars, handler& cgh, BinaryOperation combiner,
                          const property_list& propList = {});

template <typename T, typename BinaryOperation>
__unspecified__ reduction(T* var, BinaryOperation combiner,
                          const property_list& propList = {});

template <typename T, typename Extent, typename BinaryOperation>
__unspecified__ reduction(span<T, Extent> vars, BinaryOperation combiner,
                          const property_list& propList = {});

template <typename BufferT, typename BinaryOperation>
__unspecified__
reduction(BufferT vars, handler& cgh, const BufferT::value_type& identity,
          BinaryOperation combiner, const property_list& propList = {});

template <typename T, typename BinaryOperation>
__unspecified__ reduction(T* var, const T& identity, BinaryOperation combiner,
                          const property_list& propList = {});

template <typename T, typename Extent, typename BinaryOperation>
__unspecified__ reduction(span<T, Extent> vars, const T& identity,
                          BinaryOperation combiner,
                          const property_list& propList = {});
