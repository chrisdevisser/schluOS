#include <cstddef>
#include <type_traits>

static_assert(std::is_fundamental_v<int>);
static_assert(std::is_fundamental_v<double>);
static_assert(std::is_fundamental_v<char>);
static_assert(std::is_fundamental_v<void>);
static_assert(std::is_fundamental_v<std::nullptr_t>);
static_assert(std::is_fundamental_v<std::size_t>);

static_assert(std::is_fundamental_v<const int>);
static_assert(std::is_fundamental_v<volatile int>);
static_assert(std::is_fundamental_v<const volatile int>);
