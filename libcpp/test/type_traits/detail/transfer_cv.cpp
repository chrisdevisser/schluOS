#include <type_traits>
#include <detail/type_traits/detail/transfer_cv.hh>

using namespace std::__detail;

static_assert(std::is_same_v<__transfer_cv_t<int, int>, int>);
static_assert(std::is_same_v<__transfer_cv_t<int, char>, char>);
static_assert(std::is_same_v<__transfer_cv_t<const int, char>, const char>);
static_assert(std::is_same_v<__transfer_cv_t<volatile int, char>, volatile char>);
static_assert(std::is_same_v<__transfer_cv_t<const volatile int, char>, const volatile char>);
