#include <type_traits>

static_assert(std::is_array_v<int[]>);
static_assert(std::is_array_v<int[2]>);
static_assert(std::is_array_v<char[]>);

static_assert(std::is_array_v<const int[]>);
static_assert(std::is_array_v<const int[2]>);
static_assert(std::is_array_v<volatile int[]>);
static_assert(std::is_array_v<const volatile int[]>);

static_assert(not std::is_array_v<int*>);
static_assert(not std::is_array_v<void>);
//TODO: static_assert(not std::is_array_v<std::array<int, 2>>);
