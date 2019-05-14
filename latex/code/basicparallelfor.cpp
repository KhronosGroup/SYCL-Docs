myQueue.submit([&](handler & cgh) {
    auto acc = myBuffer.get_access<access::mode::write>(cgh);

    cgh.parallel_for<class myKernel>(range<1>(numWorkItems),
                                     [=] (id<1> index) {
        acc[index] = 42.0f;
    });
});
