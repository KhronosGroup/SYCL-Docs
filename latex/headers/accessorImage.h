namespace cl {
namespace sycl {
template <typename dataT, int dimensions, access::mode accessmode,
          access::target accessTarget = access::target::global_buffer,
          access::placeholder isPlaceholder = access::placeholder::false_t>
class accessor {
 public:
  using value_type = dataT;
  using reference = dataT &;
  using const_reference = const dataT &;

  /* Available only when: accessTarget == access::target::host_image */
  template <typename AllocatorT>
  accessor(image<dimensions, AllocatorT> &imageRef);

  /* Available only when: accessTarget == access::target::image */
  template <typename AllocatorT>
  accessor(image<dimensions, AllocatorT> &imageRef,
    handler &commandGroupHandlerRef);

  /* Available only when: accessTarget == access::target::image_array &&
  dimensions < 3 */
  template <typename AllocatorT>
  accessor(image<dimensions + 1, AllocatorT> &imageRef,
    handler &commandGroupHandlerRef);

  /* -- common interface members -- */

  size_t get_size() const;

  size_t get_count() const;

  /* Available only when: (accessTarget == access::target::image || accessTarget
  == access::target::host_image) && (accessMode == access::mode::read ||
  accessMode == access::mode::read_write) */
  template <typename coordT>
  dataT read(const coordT &coords) const;

  /* Available only when: (accessTarget == access::target::image || accessTarget
  == access::target::host_image) && (accessMode == access::mode::read ||
  accessMode == access::mode::read_write) */
  template <typename coordT>
  dataT read(const coordT &coords, const sampler &smpl) const;

  /* Available only when: (accessTarget == access::target::image || accessTarget
  == access::target::host_image) && (accessMode == access::mode::write ||
  accessMode == access::mode::discard_write || accessMode == access::mode::read_write) */
  template <typename coordT>
  void write(const coordT &coords, const dataT &color) const;

  /* Available only when: accessTarget == access::target::image_array &&
  dimensions < 3 */
  __image_array_slice__ operator[](size_t index) const
};
}  // namespace sycl
}  // namespace cl
