namespace cl {
namespace sycl {
class device_selector {
 public:
  device_selector();

  device_selector(const device_selector &rhs);

  device_selector &operator=(const device_selector &rhs);

  virtual ~device_selector();

  device select_device() const;

  virtual int operator()(const device &device) const = 0;
};
}  // namespace sycl
}  // namespace cl
