namespace cl {
namespace sycl {

enum class addressing_mode: unsigned int {
  mirrored_repeat,
  repeat,
  clamp_to_edge,
  clamp,
  none
};

enum class filtering_mode: unsigned int {
  nearest,
  linear
};

enum class coordinate_normalization_mode : unsigned int {
  normalized,
  unnormalized
};

class sampler {
 public:
  sampler(coordinate_normalization_mode normalizationMode, addressing_mode addressingMode,
          filtering_mode filteringMode);

  sampler(cl_sampler clSampler, const context &syclContext);

  /* -- common interface members -- */

  addressing_mode get_addressing_mode() const;

  filtering_mode get_filtering_mode() const;

  coordinate_normalization_mode get_coordinate_normalization_mode() const;
};
}  // namespace sycl
}  // namespace cl
