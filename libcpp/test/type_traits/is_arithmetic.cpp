#include <type_traits>

static_assert(std::is_arithmetic_v<int>);
static_assert(std::is_arithmetic_v<const int>);
static_assert(std::is_arithmetic_v<volatile int>);
static_assert(std::is_arithmetic_v<const volatile int>);
static_assert(std::is_arithmetic_v<double>);

static_assert(not std::is_arithmetic_v<int*>);
static_assert(not std::is_arithmetic_v<int&>);
static_assert(not std::is_arithmetic_v<int[]>);
