namespace cl {
namespace sycl {
class T {
  ...

  template <typename propertyT>
  bool has_property() const;

  template <typename propertyT>
  propertyT get_property() const;

  ...
};

class property_list {
 public:
   template <typename... propertyTN>
   property_list(propertyTN... props);
};
}  // namespace sycl
}  // namespace cl
