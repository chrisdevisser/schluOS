#include <type_traits>

struct structure {};

static_assert(std::is_object_v<int>);
static_assert(std::is_object_v<double>);
static_assert(std::is_object_v<int*>);
static_assert(std::is_object_v<int structure::*>);
static_assert(std::is_object_v<void(structure::*)()>);
static_assert(std::is_object_v<void(*)()>);
static_assert(std::is_object_v<int[]>);

static_assert(not std::is_object_v<void>);
static_assert(not std::is_object_v<int&>);
static_assert(not std::is_object_v<int&&>);
static_assert(not std::is_object_v<void()>);
