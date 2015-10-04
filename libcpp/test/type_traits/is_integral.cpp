#include <type_traits>

static_assert(std::is_integral_v<int>);
static_assert(std::is_integral_v<const int>);
static_assert(std::is_integral_v<volatile int>);
static_assert(std::is_integral_v<const volatile int>);
static_assert(std::is_integral_v<unsigned>);
static_assert(std::is_integral_v<unsigned>);

static_assert(std::is_integral_v<bool>);
static_assert(std::is_integral_v<char>);
static_assert(std::is_integral_v<signed char>);
static_assert(std::is_integral_v<unsigned char>);
static_assert(std::is_integral_v<char16_t>);
static_assert(std::is_integral_v<char32_t>);
static_assert(std::is_integral_v<wchar_t>);

static_assert(not std::is_integral_v<void>);
static_assert(not std::is_integral_v<float>);
static_assert(not std::is_integral_v<const char*>);
static_assert(not std::is_integral_v<std::integral_constant<int, 5>>);
