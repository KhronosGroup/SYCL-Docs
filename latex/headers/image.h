namespace cl {
namespace sycl {
namespace property {
namespace image {
class use_host_ptr {
  public:
    use_host_ptr() = default;
};

class use_mutex {
  public:
    use_mutex(mutex_class &mutexRef);

    mutex_class *get_mutex_ptr() const;
};

class context_bound {
  public:
    context_bound(context boundContext);

    context get_context() const;
};
}  // namespace image
}  // namespace property

enum class image_channel_order : unsigned int {
  a,
  r,
  rx,
  rg,
  rgx,
  ra,
  rgb,
  rgbx,
  rgba,
  argb,
  bgra,
  intensity,
  luminance,
  abgr
}

enum class image_channel_type : unsigned int {
  snorm_int8,
  snorm_int16,
  unorm_int8,
  unorm_int16,
  unorm_short_565,
  unorm_short_555,
  unorm_int_101010,
  signed_int8,
  signed_int16,
  signed_int32,
  unsigned_int8,
  unsigned_int16,
  unsigned_int32,
  fp16,
  fp32
}

using byte = unsigned char;

template <int dimensions = 1, typename AllocatorT = cl::sycl::image_allocator>
class image {
 public:
  image(image_channel_order order, image_channel_type type,
        const range<dimensions> &range, const property_list &propList = {});

  image(image_channel_order order, image_channel_type type,
        const range<dimensions> &range, AllocatorT allocator,
        const property_list &propList = {});

  /* Available only when: dimensions > 1 */
  image(image_channel_order order, image_channel_type type,
        const range<dimensions> &range, const range<dimensions - 1> &pitch,
        const property_list &propList = {});

  /* Available only when: dimensions > 1 */
  image(image_channel_order order, image_channel_type type,
        const range<dimensions> &range, const range<dimensions - 1> &pitch,
        AllocatorT allocator, const property_list &propList = {});

  image(void *hostPointer, image_channel_order order,
        image_channel_type type, const range<dimensions> &range,
        const property_list &propList = {});

  image(void *hostPointer, image_channel_order order,
        image_channel_type type, const range<dimensions> &range,
        AllocatorT allocator, const property_list &propList = {});

  image(const void *hostPointer, image_channel_order order,
        image_channel_type type, const range<dimensions> &range,
        const property_list &propList = {});

  image(const void *hostPointer, image_channel_order order,
        image_channel_type type, const range<dimensions> &range,
        AllocatorT allocator, const property_list &propList = {});

  /* Available only when: dimensions > 1 */
  image(void *hostPointer, image_channel_order order,
        image_channel_type type, const range<dimensions> &range,
        range<dimensions - 1> &pitch, const property_list &propList = {});

  /* Available only when: dimensions > 1 */
  image(void *hostPointer, image_channel_order order,
        image_channel_type type, const range<dimensions> &range,
        range<dimensions - 1> &pitch, AllocatorT allocator,
        const property_list &propList = {});

  image(shared_ptr_class<void> &hostPointer, image_channel_order order,
        image_channel_type type, const range<dimensions> &range,
        const property_list &propList = {});

  image(shared_ptr_class<void> &hostPointer, image_channel_order order,
        image_channel_type type, const range<dimensions> &range,
        AllocatorT allocator, const property_list &propList = {});

  /* Available only when: dimensions > 1 */
  image(shared_ptr_class<void> &hostPointer, image_channel_order order,
        image_channel_type type, const range<dimensions> &range,
        const range<dimensions - 1> &pitch, const property_list &propList = {});

  /* Available only when: dimensions > 1 */
  image(shared_ptr_class<void> &hostPointer, image_channel_order order,
        image_channel_type type, const range<dimensions> &range,
        const range<dimensions - 1> &pitch, AllocatorT allocator,
        const property_list &propList = {});

  image(cl_mem clMemObject, const context &syclContext,
        event availableEvent = {});

  /* -- common interface members -- */

  /* -- property interface members -- */

  range<dimensions> get_range() const;

  /* Available only when: dimensions > 1 */
  range<dimensions - 1> get_pitch() const;

  size_t get_size() const;

  size_t get_count() const;

  AllocatorT get_allocator() const;

  template <typename dataT, access::mode accessMode>
  accessor<dataT, dimensions, accessMode, access::target::image>
  get_access(handler & commandGroupHandler);

  template <typename dataT, access::mode accessMode>
  accessor<dataT, dimensions, accessMode, access::target::host_image>
  get_access();

  template <typename Destination = std::nullptr_t>
  void set_final_data(Destination finalData = std::nullptr);

  void set_write_back(bool flag = true);

};
}  // namespace sycl
}  // namespace cl
