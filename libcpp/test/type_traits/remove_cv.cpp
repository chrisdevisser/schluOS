#include <type_traits>

static_assert(std::is_same_v<std::remove_cv_t<int>, int>);
static_assert(std::is_same_v<std::remove_cv_t<const int>, int>);
static_assert(std::is_same_v<std::remove_cv_t<volatile int>, int>);
static_assert(std::is_same_v<std::remove_cv_t<const volatile int>, int>);
static_assert(std::is_same_v<std::remove_cv_t<const volatile int* const volatile>, const volatile int*>);
static_assert(std::is_same_v<std::remove_cv_t<const volatile int&>, const volatile int&>);
static_assert(std::is_same_v<std::remove_cv_t<const volatile int[3]>, int[3]>);
