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
  range<dimensions> operatorOP(const range<dimensions> &rhs) const;
  range<dimensions> operatorOP(const size_t &rhs) const;

  // OP is: +=, -=, *=, /=, %=, <<=, >>=, &=, |=, ^=
  range<dimensions> &operatorOP(const range<dimensions> &rhs);
  range<dimensions> &operatorOP(const size_t &rhs);
};

// OP is: +, -, *, /, %, <<, >>, &, |, ^
template <int dimensions>
range<dimensions> operatorOP(const size_t &lhs, const range<dimensions> &rhs);
}  // sycl
}  // cl
