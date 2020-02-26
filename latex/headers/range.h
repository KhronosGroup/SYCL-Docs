// Copyright (c) 2011-2020 The Khronos Group, Inc.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

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

  // OP is: +, -, *, /, %, <<, >>, &, |, ^, &&, ||, <, >, <=, >=
  friend range operatorOP(const size_t &lhs, const range &rhs) { /* ... */ }

};

}  // sycl
}  // cl
