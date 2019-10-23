namespace cl {
namespace sycl {

enum class stream_manipulator {
  flush,
  dec,
  hex,
  oct,
  noshowbase,
  showbase,
  noshowpos,
  showpos,
  endl,
  fixed,
  scientific,
  hexfloat,
  defaultfloat
};


const stream_manipulator flush = stream_manipulator::flush;

const stream_manipulator dec = stream_manipulator::dec;

const stream_manipulator hex = stream_manipulator::hex;

const stream_manipulator oct = stream_manipulator::oct;

const stream_manipulator noshowbase = stream_manipulator::noshowbase;

const stream_manipulator showbase = stream_manipulator::showbase;

const stream_manipulator noshowpos = stream_manipulator::noshowpos;

const stream_manipulator showpos = stream_manipulator::showpos;

const stream_manipulator endl = stream_manipulator::endl;

const stream_manipulator fixed = stream_manipulator::fixed;

const stream_manipulator scientific = stream_manipulator::scientific;

const stream_manipulator hexfloat = stream_manipulator::hexfloat;

const stream_manipulator defaultfloat = stream_manipulator::defaultfloat;

__precision_manipulator__ setprecision(int precision);

__width_manipulator__ setw(int width);

class stream {
 public:

  stream(size_t totalBufferSize, size_t workItemBufferSize, handler& cgh);

  /* -- common interface members -- */

  size_t get_size() const;

  size_t get_work_item_buffer_size() const;

  /* get_max_statement_size() is an alias for get_work_item_buffer_size(), and
     is provided for backward compatibility */
  size_t get_max_statement_size() const;
};

template <typename T>
const stream& operator<<(const stream& os, const T &rhs);

}  // namespace sycl
}  // namespace cl
