namespace cl {
namespace sycl {
template <typename dataT, int dimensions, access::mode accessmode,
          access::placeholder isPlaceholder = access::placeholder::false_t>
class accessor <dataT, dimensions, accessmode,
          access::target accessTarget = access::target::local,
          isPlaceholder> {
public:
  using value_type = dataT;
  using reference = dataT &;
  using const_reference = const dataT &;

  /* Available only when: dimensions == 0 */
  accessor(handler &commandGroupHandlerRef);

  /* Available only when: dimensions > 0 */
  accessor(range<dimensions> allocationSize, handler &commandGroupHandlerRef);

  /* -- common interface members -- */

  size_t get_size() const;

  size_t get_count() const;

  /* Available only when: accessMode == access::mode::read_write && dimensions == 0) */
  operator dataT &() const;

  /* Available only when: accessMode == access::mode::read_write && dimensions > 0) */
  dataT &operator[](id<dimensions> index) const;

  /* Available only when: accessMode == access::mode::read_write && dimensions == 1) */
  dataT &operator[](size_t index) const;

  /* Available only when: accessMode == access::mode::atomic && dimensions ==
  0 */
  operator atomic<dataT,access::address_space::local_space> () const;

  /* Available only when: accessMode == access::mode::atomic && dimensions >
  0 */
  atomic<dataT, access::address_space::local_space> operator[](
    id<dimensions> index) const;

  /* Available only when: accessMode == access::mode::atomic && dimensions ==
  1 */
  atomic<dataT, access::address_space::local_space> operator[](
    size_t index) const;

  /* Available only when: dimensions > 1 */
  __unspecified__ &operator[](size_t index) const;

  /* Available only when: accessTarget == access::target::local */
  local_ptr<dataT> get_pointer() const;
};
}  // namespace sycl
}  // namespace cl
