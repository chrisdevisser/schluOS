#include <type_traits>

using reference = int&;

static_assert(std::is_reference_v<int&>);
static_assert(std::is_reference_v<int&&>);
static_assert(std::is_reference_v<int*&>);

static_assert(std::is_reference_v<const reference>);
static_assert(std::is_reference_v<volatile reference>);
static_assert(std::is_reference_v<const volatile reference>);

static_assert(std::is_reference_v<const int&>);
static_assert(std::is_reference_v<volatile int&>);
static_assert(std::is_reference_v<const volatile int&>);


static_assert(not std::is_reference_v<int>);
static_assert(not std::is_reference_v<int*>);
