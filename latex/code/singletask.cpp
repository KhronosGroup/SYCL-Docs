myQueue.submit([&](handler & cgh) {
cgh.single_task<class kernel_name>(
    [=] () {
      // [kernel code]
    }));
});
