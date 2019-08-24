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
    
  ...

  friend bool operator==(const T &lhs, const T &rhs) { /* ... */ }

  friend bool operator!=(const T &lhs, const T &rhs) { /* ... */ }

  ...
};
}  // namespace sycl
}  // namespace cl
