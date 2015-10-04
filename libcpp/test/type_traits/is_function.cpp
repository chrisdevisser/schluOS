#include <type_traits>

struct structure {};

static_assert(std::is_function_v<void()>);
static_assert(std::is_function_v<void(...)>);
static_assert(std::is_function_v<void() const>);
static_assert(std::is_function_v<void(...) const>);
static_assert(std::is_function_v<void() volatile>);
static_assert(std::is_function_v<void(...) volatile>);
static_assert(std::is_function_v<void() const volatile>);
static_assert(std::is_function_v<void(...) const volatile>);
static_assert(std::is_function_v<void() &>);
static_assert(std::is_function_v<void(...) &>);
static_assert(std::is_function_v<void() const &>);
static_assert(std::is_function_v<void(...) const &>);
static_assert(std::is_function_v<void() volatile &>);
static_assert(std::is_function_v<void(...) volatile &>);
static_assert(std::is_function_v<void() const volatile &>);
static_assert(std::is_function_v<void(...) const volatile &>);
static_assert(std::is_function_v<void() &&>);
static_assert(std::is_function_v<void(...) &&>);
static_assert(std::is_function_v<void() const &&>);
static_assert(std::is_function_v<void(...) const &&>);
static_assert(std::is_function_v<void() volatile &&>);
static_assert(std::is_function_v<void(...) volatile &&>);
static_assert(std::is_function_v<void() const volatile &&>);
static_assert(std::is_function_v<void(...) const volatile &&>);

static_assert(not std::is_function_v<void>);
static_assert(not std::is_function_v<void(*)()>);
static_assert(not std::is_function_v<void(&)()>);
static_assert(not std::is_function_v<void(structure::*)()>);
