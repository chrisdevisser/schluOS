#include <type_traits>

static_assert(std::is_same_v<std::integral_constant<int, 5>::value_type, int>);
static_assert(std::is_same_v<std::integral_constant<unsigned, 5>::value_type, unsigned>);
static_assert(std::is_same_v<std::integral_constant<int, 0u>::value_type, int>);

static_assert(std::is_same_v<std::integral_constant<int, 5>::type, std::integral_constant<int, 5>>);
static_assert(std::is_same_v<std::integral_constant<unsigned, 5>::type, std::integral_constant<unsigned, 5>>);
static_assert(std::is_same_v<std::integral_constant<int, 5u>::type, std::integral_constant<int, 5u>>);

static_assert(std::integral_constant<int, 5>::value == 5);
static_assert(std::integral_constant<int, 5>{} == 5);
static_assert(std::integral_constant<int, 5>{}() == 5);
