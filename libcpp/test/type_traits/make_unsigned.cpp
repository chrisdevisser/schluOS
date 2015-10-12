#include <type_traits>

enum enumeration {};
enum class scoped_enum {};
enum int_enum : int {};
enum uchar_enum : unsigned char {};
enum long_long_enum : long long {};

template<typename _T>
using try_make_unsigned = std::make_unsigned_t<_T>;

static_assert(std::is_same_v<std::make_unsigned_t<char>, unsigned char>);
static_assert(std::is_same_v<std::make_unsigned_t<signed char>, unsigned char>);
static_assert(std::is_same_v<std::make_unsigned_t<unsigned char>, unsigned char>);
static_assert(std::is_same_v<std::make_unsigned_t<short>, unsigned short>);
static_assert(std::is_same_v<std::make_unsigned_t<unsigned short>, unsigned short>);
static_assert(std::is_same_v<std::make_unsigned_t<int>, unsigned int>);
static_assert(std::is_same_v<std::make_unsigned_t<unsigned>, unsigned int>);
static_assert(std::is_same_v<std::make_unsigned_t<long>, unsigned long>);
static_assert(std::is_same_v<std::make_unsigned_t<unsigned long>, unsigned long>);
static_assert(std::is_same_v<std::make_unsigned_t<long long>, unsigned long long>);
static_assert(std::is_same_v<std::make_unsigned_t<unsigned long long>, unsigned long long>);

//Can't be too sure what the exact type is.
static_assert(std::is_detected_v<try_make_unsigned, char16_t>);
static_assert(std::is_detected_v<try_make_unsigned, char32_t>);
static_assert(std::is_detected_v<try_make_unsigned, wchar_t>);
static_assert(std::is_detected_v<try_make_unsigned, enumeration>);
static_assert(std::is_detected_v<try_make_unsigned, scoped_enum>);
static_assert(std::is_detected_v<try_make_unsigned, int_enum>);
static_assert(std::is_detected_v<try_make_unsigned, uchar_enum>);
static_assert(std::is_detected_v<try_make_unsigned, long_long_enum>);

