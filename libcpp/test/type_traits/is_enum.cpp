#include <type_traits>

enum enumeration {};
enum class scoped_enumeration {};
enum fixed_enumeration : int {};
enum class scoped_fixed_enumeration : int {};

static_assert(std::is_enum_v<enumeration>);
static_assert(std::is_enum_v<scoped_enumeration>);
static_assert(std::is_enum_v<fixed_enumeration>);
static_assert(std::is_enum_v<scoped_fixed_enumeration>);

static_assert(std::is_enum_v<const enumeration>);
static_assert(std::is_enum_v<volatile enumeration>);
static_assert(std::is_enum_v<const volatile enumeration>);

static_assert(not std::is_enum_v<int>);
static_assert(not std::is_enum_v<enumeration*>);
static_assert(not std::is_enum_v<enumeration&>);
