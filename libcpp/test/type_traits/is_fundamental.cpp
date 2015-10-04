#include <cstddef>
#include <type_traits>

struct structure {};
enum enumeration {};

static_assert(std::is_fundamental_v<int>);
static_assert(std::is_fundamental_v<double>);
static_assert(std::is_fundamental_v<char>);
static_assert(std::is_fundamental_v<void>);
static_assert(std::is_fundamental_v<std::nullptr_t>);
static_assert(std::is_fundamental_v<std::size_t>);

static_assert(std::is_fundamental_v<const int>);
static_assert(std::is_fundamental_v<volatile int>);
static_assert(std::is_fundamental_v<const volatile int>);

static_assert(not std::is_fundamental_v<int*>);
static_assert(not std::is_fundamental_v<int&>);
static_assert(not std::is_fundamental_v<void()>);
static_assert(not std::is_fundamental_v<structure>);
static_assert(not std::is_fundamental_v<int structure::*>);
static_assert(not std::is_fundamental_v<void(structure::*)()>);
