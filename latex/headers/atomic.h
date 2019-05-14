namespace cl {
namespace sycl {
enum class memory_order : int {
  relaxed
};

template <typename T, access::address_space addressSpace =
  access::address_space::global_space>
class atomic {
 public:
  template <typename pointerT>
  atomic(multi_ptr<pointerT, addressSpace> ptr);

  void store(T operand, memory_order memoryOrder =
    memory_order::relaxed);

  T load(memory_order memoryOrder = memory_order::relaxed) const;

  T exchange(T operand, memory_order memoryOrder =
   memory_order::relaxed);

  /* Available only when: T != float */
  bool compare_exchange_strong(T &expected, T desired,
    memory_order successMemoryOrder = memory_order::relaxed,
    memory_order failMemoryOrder = memory_order::relaxed);

  /* Available only when: T != float */
  T fetch_add(T operand, memory_order memoryOrder =
    memory_order::relaxed);

  /* Available only when: T != float */
  T fetch_sub(T operand, memory_order memoryOrder =
    memory_order::relaxed);

  /* Available only when: T != float */
  T fetch_and(T operand, memory_order memoryOrder =
    memory_order::relaxed);

  /* Available only when: T != float */
  T fetch_or(T operand, memory_order memoryOrder =
    memory_order::relaxed);

  /* Available only when: T != float */
  T fetch_xor(T operand, memory_order memoryOrder =
    memory_order::relaxed);

  /* Available only when: T != float */
  T fetch_min(T operand, memory_order memoryOrder =
    memory_order::relaxed);

  /* Available only when: T != float */
  T fetch_max(T operand, memory_order memoryOrder =
    memory_order::relaxed);
};
}  // namespace sycl
}  // namespace cl
