#include <type_traits>

static_assert(std::is_same_v<std::remove_all_extents_t<int>, int>);
static_assert(std::is_same_v<std::remove_all_extents_t<void>, void>);
static_assert(std::is_same_v<std::remove_all_extents_t<int[]>, int>);
static_assert(std::is_same_v<std::remove_all_extents_t<int[5]>, int>);
static_assert(std::is_same_v<std::remove_all_extents_t<int[][5]>, int>);
static_assert(std::is_same_v<std::remove_all_extents_t<int[2][5]>, int>);
static_assert(std::is_same_v<std::remove_all_extents_t<int*>, int*>);
static_assert(std::is_same_v<std::remove_all_extents_t<int(*)[]>, int(*)[]>);
static_assert(std::is_same_v<std::remove_all_extents_t<int(*)[5]>, int(*)[5]>);
static_assert(std::is_same_v<std::remove_all_extents_t<int(&)[]>, int(&)[]>);
static_assert(std::is_same_v<std::remove_all_extents_t<int(&)[5]>, int(&)[5]>);

static_assert(std::is_same_v<std::remove_all_extents_t<const int>, const int>);
static_assert(std::is_same_v<std::remove_all_extents_t<const int[]>, const int>);
static_assert(std::is_same_v<std::remove_all_extents_t<const int[5]>, const int>);
