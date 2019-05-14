class MyKernel;

myQueue.submit([&](handler& cmdGroup) {
  cmdgroup.single_task<class MyKernel>([=]() {
    // [kernel code]
  });
});
