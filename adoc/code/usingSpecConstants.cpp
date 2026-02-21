// Copyright (c) 2011-2026 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

#include <sycl/sycl.hpp>
using namespace sycl;  // (optional) avoids need for "sycl::" before SYCL names

using coeff_t = std::array<std::array<float, 3>, 3>;

// Read coefficients from somewhere.
coeff_t get_coefficients();

// Identify the specialization constant.
constexpr specialization_id<coeff_t> coeff_id;

void do_conv(buffer<float, 2> in, buffer<float, 2> out) {
  queue myQueue;

  myQueue.submit([&](handler& cgh) {
    accessor in_acc{in, cgh, read_only};
    accessor out_acc{out, cgh, write_only};

    // Set the coefficient of the convolution as constant.
    // This will build a specific kernel the coefficient available as literals.
    cgh.set_specialization_constant<coeff_id>(get_coefficients());

    cgh.parallel_for<class Convolution>(in.get_range(), [=](item<2> item_id,
                                                            kernel_handler h) {
      float acc = 0;
      coeff_t coeff = h.get_specialization_constant<coeff_id>();
      for (int i = -1; i <= 1; i++) {
        if (item_id[0] + i < 0 || item_id[0] + i >= in_acc.get_range()[0])
          continue;
        for (int j = -1; j <= 1; j++) {
          if (item_id[1] + j < 0 || item_id[1] + j >= in_acc.get_range()[1])
            continue;
          // The underlying JIT can see all the values of the array returned
          // by coeff.get().
          acc += coeff[i + 1][j + 1] * in_acc[item_id[0] + i][item_id[1] + j];
        }
      }
      out_acc[item_id] = acc;
    });
  });

  myQueue.wait();
}
