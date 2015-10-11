#include <type_traits>

static_assert(std::rank_v<int> == 0);
static_assert(std::rank_v<void> == 0);
static_assert(std::rank_v<void()> == 0);
static_assert(std::rank_v<int[]> == 1);
static_assert(std::rank_v<int[1]> == 1);
static_assert(std::rank_v<int[][1]> == 2);
static_assert(std::rank_v<int[1][2]> == 2);
static_assert(std::rank_v<int[1][2][3][4][5]> == 5);
static_assert(std::rank_v<int(*)[]> == 0);
static_assert(std::rank_v<int(&)[]> == 0);
