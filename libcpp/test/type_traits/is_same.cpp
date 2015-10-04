#include <type_traits>

struct base {};
struct derived : base {};

static_assert(std::is_same_v<int, int>);
static_assert(std::is_same_v<const int, const int>);
static_assert(std::is_same_v<volatile int, volatile int>);
static_assert(std::is_same_v<const volatile int, const volatile int>);

static_assert(not std::is_same_v<int, const int>);
static_assert(not std::is_same_v<const int, int>);
static_assert(not std::is_same_v<int, volatile int>);
static_assert(not std::is_same_v<int, const volatile int>);

static_assert(not std::is_same_v<int, double>);
static_assert(not std::is_same_v<base, derived>);
