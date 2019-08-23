namespace cl {
namespace sycl {

class T {
  ...

 public:
  // Rule of Zero: the following five special member functions should not be explicitly declared

  // T(const T &rhs) = default;

  // T(T &&rhs) = default;

  // T &operator=(const T &rhs) = default;

  // T &operator=(T &&rhs) = default;

  // ~T() = default;

  bool operator==(const T &rhs) const;

  bool operator!=(const T &rhs) const;

  ...
};
}  // namespace sycl
}  // namespace cl
