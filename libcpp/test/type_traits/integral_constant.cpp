#include <type_traits>

static_assert(std::integral_constant<int, 5>::value == 5);
static_assert(std::integral_constant<int, 5>{} == 5);
static_assert(std::integral_constant<int, 5>{}() == 5);
