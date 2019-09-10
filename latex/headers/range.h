namespace cl {
namespace sycl {
template <int dimensions = 1>
class range {
public:
  /* The following constructor is only available in the range class specialization where: dimensions==1 */
  range(size_t dim0);
  /* The following constructor is only available in the range class specialization where: dimensions==2 */
  range(size_t dim0, size_t dim1);
  /* The following constructor is only available in the range class specialization where: dimensions==3 */ 
  range(size_t dim0, size_t dim1, size_t dim2);

   /* -- common interface members -- */

  size_t get(int dimension) const;
  size_t &operator[](int dimension);
  size_t operator[](int dimension) const;

  size_t size() const;

  // OP is: +, -, *, /, %, <<, >>, &, |, ^, &&, ||, <, >, <=, >=
  friend range operatorOP(const range &lhs, const range &rhs) { /* ... */ }
  friend range operatorOP(const range &lhs, const size_t &rhs) { /* ... */ }

  // OP is: +=, -=, *=, /=, %=, <<=, >>=, &=, |=, ^=
  friend range & operatorOP(const range &lhs, const range &rhs) { /* ... */ }
  friend range & operatorOP(const range &lhs, const size_t &rhs) { /* ... */ }
    
  // OP is: +, -, *, /, %, <<, >>, &, |, ^
  friend range operatorOP(const size_t &lhs, const range &rhs) { /* ... */ }

};

}  // sycl
}  // cl
