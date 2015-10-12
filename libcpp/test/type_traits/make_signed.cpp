#include <type_traits>

enum enumeration {};
enum class scoped_enum {};
enum int_enum : int {};
enum uchar_enum : unsigned char {};
enum long_long_enum : long long {};

template<typename _T>
using try_make_signed = std::make_signed_t<_T>;

static_assert(std::is_same_v<std::make_signed_t<char>, signed char>);
static_assert(std::is_same_v<std::make_signed_t<signed char>, signed char>);
static_assert(std::is_same_v<std::make_signed_t<unsigned char>, signed char>);
static_assert(std::is_same_v<std::make_signed_t<short>, short>);
static_assert(std::is_same_v<std::make_signed_t<unsigned short>, short>);
static_assert(std::is_same_v<std::make_signed_t<int>, int>);
static_assert(std::is_same_v<std::make_signed_t<unsigned>, int>);
static_assert(std::is_same_v<std::make_signed_t<long>, long>);
static_assert(std::is_same_v<std::make_signed_t<unsigned long>, long>);
static_assert(std::is_same_v<std::make_signed_t<long long>, long long>);
static_assert(std::is_same_v<std::make_signed_t<unsigned long long>, long long>);

//Can't be too sure what the exact type is.
static_assert(std::is_detected_v<try_make_signed, char16_t>);
static_assert(std::is_detected_v<try_make_signed, char32_t>);
static_assert(std::is_detected_v<try_make_signed, wchar_t>);
static_assert(std::is_detected_v<try_make_signed, enumeration>);
static_assert(std::is_detected_v<try_make_signed, scoped_enum>);
static_assert(std::is_detected_v<try_make_signed, int_enum>);
static_assert(std::is_detected_v<try_make_signed, uchar_enum>);
static_assert(std::is_detected_v<try_make_signed, long_long_enum>);

