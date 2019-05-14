myQueue.submit([&](handler & cgh) {
    auto acc = myBuffer.get_access<access::mode::write>(cgh);

    cgh.parallel_for<class myKernel>(range<1>(numWorkItems),
                                     [=] (item<1> item) {
        size_t index = item.get_linear_id();
        acc[index] = 42.0f;
    });
});
