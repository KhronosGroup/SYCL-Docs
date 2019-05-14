namespace cl {
namespace sycl {
template <typename T, access::address_space addressSpace>
void atomic_store(atomic<T, addressSpace> object, T operand, memory_order memoryOrder =
  memory_order::relaxed);

template <typename T, access::address_space addressSpace>
T atomic_load(atomic<T, addressSpace> object, memory_order memoryOrder =
  memory_order::relaxed);

template <typename T, access::address_space addressSpace>
T atomic_exchange(atomic<T, addressSpace> object, T operand, memory_order memoryOrder =
  memory_order::relaxed);

template <typename T, access::address_space addressSpace>
bool atomic_compare_exchange_strong(atomic<T, addressSpace> object, T &expected, T desired,
    memory_order successMemoryOrder = memory_order::relaxed,
    memory_order failMemoryOrder = memory_order::relaxed);

template <typename T, access::address_space addressSpace>
T atomic_fetch_add(atomic<T, addressSpace> object, T operand, memory_order memoryOrder =
    memory_order::relaxed);

template <typename T, access::address_space addressSpace>
T atomic_fetch_sub(atomic<T, addressSpace> object, T operand, memory_order memoryOrder =
  memory_order::relaxed);

template <typename T, access::address_space addressSpace>
T atomic_fetch_and(atomic<T, addressSpace> object, T operand, memory_order memoryOrder =
  memory_order::relaxed);

template <typename T, access::address_space addressSpace>
T atomic_fetch_or(atomic<T, addressSpace> object, T operand, memory_order memoryOrder =
  memory_order::relaxed);

template <typename T, access::address_space addressSpace>
T atomic_fetch_xor(atomic<T, addressSpace> object, T operand, memory_order memoryOrder =
  memory_order::relaxed);

template <typename T, access::address_space addressSpace>
T atomic_fetch_min(atomic<T, addressSpace> object, T operand, memory_order memoryOrder =
  memory_order::relaxed);

template <typename T, access::address_space addressSpace>
T atomic_fetch_max(atomic<T, addressSpace> object, T operand, memory_order memoryOrder =
  memory_order::relaxed);
}  // namespace sycl
}  // namespace cl
