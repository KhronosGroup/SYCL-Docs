namespace cl {
namespace sycl {
class default_selector : public device_selector {
 public:
  default_selector();

  virtual ~default_selector();

  virtual int operator()(const device &device) const;
};

class opencl_selector : public device_selector {
 public:
  opencl_selector();

  virtual ~opencl_selector();

  virtual int operator()(const device &device) const;
};

class cpu_selector : public device_selector {
 public:
  cpu_selector();

  virtual ~cpu_selector();

  virtual int operator()(const device &device) const;
};

class gpu_selector : public device_selector {
 public:
  gpu_selector();

  virtual ~gpu_selector();

  virtual int operator()(const device &device) const;
};

class host_selector : public device_selector {
 public:
  host_selector();

  virtual ~host_selector();

  virtual int operator()(const device &device) const;
};

}  // namespace sycl
}  // namespace cl
