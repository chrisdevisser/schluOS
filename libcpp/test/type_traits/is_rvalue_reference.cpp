#include <type_traits>

static_assert(std::is_rvalue_reference_v<int&&>);
static_assert(std::is_rvalue_reference_v<const int&&>);
static_assert(std::is_rvalue_reference_v<volatile int&&>);
static_assert(std::is_rvalue_reference_v<const volatile int&&>);

static_assert(std::is_rvalue_reference_v<void(&&)()>);
static_assert(std::is_rvalue_reference_v<int(&&)[]>);
static_assert(std::is_rvalue_reference_v<int(&&)[5]>);
static_assert(std::is_rvalue_reference_v<int*&&>);

static_assert(not std::is_rvalue_reference_v<int>);
static_assert(not std::is_rvalue_reference_v<int&>);
