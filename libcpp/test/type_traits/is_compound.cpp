#include <cstddef>
#include <type_traits>

struct structure {};
enum enumeration {};

static_assert(std::is_compound_v<int*>);
static_assert(std::is_compound_v<int&>);
static_assert(std::is_compound_v<void()>);
static_assert(std::is_compound_v<structure>);
static_assert(std::is_compound_v<int structure::*>);
static_assert(std::is_compound_v<void(structure::*)()>);

static_assert(std::is_compound_v<int* const>);
static_assert(std::is_compound_v<int* volatile>);
static_assert(std::is_compound_v<int* const volatile>);

static_assert(not std::is_compound_v<int>);
static_assert(not std::is_compound_v<double>);
static_assert(not std::is_compound_v<char>);
static_assert(not std::is_compound_v<void>);
static_assert(not std::is_compound_v<std::nullptr_t>);
static_assert(not std::is_compound_v<std::size_t>);
