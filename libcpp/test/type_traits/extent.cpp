#include <type_traits>

static_assert(std::extent_v<void> == 0);
static_assert(std::extent_v<int> == 0);
static_assert(std::extent_v<int(*)[5]> == 0);
static_assert(std::extent_v<int(&)[5]> == 0);
static_assert(std::extent_v<int, -1> == 0);
static_assert(std::extent_v<int, 1000000> == 0);
static_assert(std::extent_v<int[5], 1000000> == 0);
static_assert(std::extent_v<int[5], -1> == 0);

static_assert(std::extent_v<int[]> == 0);
static_assert(std::extent_v<int[], 0> == 0);
static_assert(std::extent_v<int[5], 0> == 5);
static_assert(std::extent_v<int[][2], 0> == 0);
static_assert(std::extent_v<int[][2], 1> == 2);
static_assert(std::extent_v<int[1][2], 0> == 1);
static_assert(std::extent_v<int[1][2], 1> == 2);
static_assert(std::extent_v<int[1][2][3][4][5], 3> == 4);
