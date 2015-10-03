#include <type_traits>

static_assert(std::is_same_v<std::remove_volatile_t<int>, int>);
static_assert(std::is_same_v<std::remove_volatile_t<volatile int>, int>);
static_assert(std::is_same_v<std::remove_volatile_t<const volatile int>, const int>);
static_assert(std::is_same_v<std::remove_volatile_t<const int>, const int>);
static_assert(std::is_same_v<std::remove_volatile_t<volatile int* volatile>, volatile int*>);
static_assert(std::is_same_v<std::remove_volatile_t<volatile int&>, volatile int&>);
static_assert(std::is_same_v<std::remove_volatile_t<volatile int[3]>, int[3]>);
