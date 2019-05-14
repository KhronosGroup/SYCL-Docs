namespace cl {
namespace sycl {

class T {
  ...

 public:
  T(const T &rhs);

  T(T &&rhs);

  T &operator=(const T &rhs);

  T &operator=(T &&rhs);

  ~T();

  bool operator==(const T &rhs) const;

  bool operator!=(const T &rhs) const;

  ...
};
}  // namespace sycl
}  // namespace cl
