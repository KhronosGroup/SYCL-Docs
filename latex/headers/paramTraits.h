namespace cl {
namespace sycl {
namespace info {
template <typename T, T param>
class param_traits {
 public:

   using return_type = __return_type__<T, param>;

};
}  // namespace info
}  // namespace sycl
}  // namespace cl
