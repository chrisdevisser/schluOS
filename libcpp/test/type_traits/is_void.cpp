#include <type_traits>

static_assert(std::is_void_v<void>);
static_assert(std::is_void_v<const void>);
static_assert(std::is_void_v<volatile void>);
static_assert(std::is_void_v<const volatile void>);
static_assert(not std::is_void_v<int>);
