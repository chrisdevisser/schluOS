#include <cstddef>
#include <type_traits>

static_assert(std::is_null_pointer_v<std::nullptr_t>);
static_assert(std::is_null_pointer_v<const std::nullptr_t>);
static_assert(std::is_null_pointer_v<volatile std::nullptr_t>);
static_assert(std::is_null_pointer_v<const volatile std::nullptr_t>);
static_assert(not std::is_null_pointer_v<int>);
static_assert(not std::is_null_pointer_v<void*>);
