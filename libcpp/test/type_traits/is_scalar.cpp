#include <cstddef>
#include <type_traits>

enum enumeration {};
struct structure {};

static_assert(std::is_scalar_v<int>);
static_assert(std::is_scalar_v<const int>);
static_assert(std::is_scalar_v<volatile int>);
static_assert(std::is_scalar_v<const volatile int>);
static_assert(std::is_scalar_v<double>);
static_assert(std::is_scalar_v<enumeration>);
static_assert(std::is_scalar_v<int*>);
static_assert(std::is_scalar_v<int structure::*>);
static_assert(std::is_scalar_v<void(structure::*)()>);
static_assert(std::is_scalar_v<void(*)()>);
static_assert(std::is_scalar_v<std::nullptr_t>);

static_assert(not std::is_scalar_v<void>);
static_assert(not std::is_scalar_v<int&>);
static_assert(not std::is_scalar_v<int[]>);
static_assert(not std::is_scalar_v<structure>);
static_assert(not std::is_scalar_v<void()>);

