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

  // OP is: +, -, *, /, %, <<, >>, &, |, ^, &&, ||, <, >, <=, >=
    friend id operatorOP(const size_t &lhs, const id &rhs) { /* ... */ }

};

}  // namespace sycl
}  // namespace cl
