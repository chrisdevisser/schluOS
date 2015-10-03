#include <type_traits>

static_assert(std::is_same_v<std::remove_const_t<int>, int>);
static_assert(std::is_same_v<std::remove_const_t<const int>, int>);
static_assert(std::is_same_v<std::remove_const_t<const volatile int>, volatile int>);
static_assert(std::is_same_v<std::remove_const_t<volatile int>, volatile int>);
static_assert(std::is_same_v<std::remove_const_t<const int* const>, const int*>);
static_assert(std::is_same_v<std::remove_const_t<const int&>, const int&>);
static_assert(std::is_same_v<std::remove_const_t<const int[3]>, int[3]>);
