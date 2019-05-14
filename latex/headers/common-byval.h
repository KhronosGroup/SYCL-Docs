namespace cl {
namespace sycl {

class T {
  ...

 public:
  T(const T &rhs) = default;

  T(T &&rhs) = default;

  T &operator=(const T &rhs) = default;

  T &operator=(T &&rhs) = default;

  ~T() = default;

  bool operator==(const T &rhs) const;

  bool operator!=(const T &rhs) const;

  ...
};
}  // namespace sycl
}  // namespace cl
