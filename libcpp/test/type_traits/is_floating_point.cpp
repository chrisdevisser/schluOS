#include <type_traits>

static_assert(std::is_floating_point_v<float>);
static_assert(std::is_floating_point_v<const float>);
static_assert(std::is_floating_point_v<volatile float>);
static_assert(std::is_floating_point_v<const volatile float>);

static_assert(std::is_floating_point_v<double>);
static_assert(std::is_floating_point_v<long double>);

static_assert(not std::is_floating_point_v<void>);
static_assert(not std::is_floating_point_v<int>);
static_assert(not std::is_floating_point_v<const char*>);
