kernel sycl_kernel(target_context, target_device, kernel_string, kernel_name);

myQueue.submit([&](handler& cmdgroup) {
  accessor<float, 2, read_write, global_buffer> ptr(buf);

  kernel.set_arg(0, ptr);

  cmdgroup.parallel_for(nd_range<3>(range<3>(4, 4, 4), range<3>(2, 2, 2)),
                            sycl_kernel);
});
