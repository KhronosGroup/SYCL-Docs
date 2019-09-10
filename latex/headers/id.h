namespace cl {
namespace sycl {
template <int dimensions = 1>
class id {
public:
  id();

  /* The following constructor is only available in the id class
   * specialization where: dimensions==1 */
  id(size_t dim0);
  /* The following constructor is only available in the id class
   * specialization where: dimensions==2 */
  id(size_t dim0, size_t dim1);
  /* The following constructor is only available in the id class
   * specialization where: dimensions==3 */
  id(size_t dim0, size_t dim1, size_t dim2);

   /* -- common interface members -- */

  id(const range<dimensions> &range);
  id(const item<dimensions> &item);

  size_t get(int dimension) const;
  size_t &operator[](int dimension);
  size_t operator[](int dimension) const;

  // OP is: +, -, *, /, %, <<, >>, &, |, ^, &&, ||, <, >, <=, >=
    friend id operatorOP(const id &lhs, const id &rhs) { /* ... */ }
    friend id operatorOP(const id &lhs, const size_t &rhs) { /* ... */ }

  // OP is: +=, -=, *=, /=, %=, <<=, >>=, &=, |=, ^=
    friend id &operatorOP(id &lhs, const id &rhs) { /* ... */ }
    friend id &operatorOP(id &lhs, const size_t &rhs) { /* ... */ }

  // OP is: +, -, *, /, %, <<, >>, &, |, ^
    friend id operatorOP(const size_t &lhs, const id &rhs) { /* ... */ }

};

}  // namespace sycl
}  // namespace cl
