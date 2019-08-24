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

  ...

  friend bool operator==(const T &lhs, const T &rhs) { /* ... */ }

  friend bool operator!=(const T &lhs, const T &rhs) { /* ... */ }

  ...
};
}  // namespace sycl
}  // namespace cl
