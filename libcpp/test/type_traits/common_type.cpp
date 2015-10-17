#include <type_traits>

template<typename... Ts>
using try_common_type = std::common_type_t<Ts...>;

struct base {};
struct derived : base {};

struct constructible_from_int {
    constructible_from_int(int) {}
};

//no type if zero arguments
static_assert(not std::is_detected_v<try_common_type>);

//decay_t<T> if one argument
static_assert(std::is_same_v<std::common_type_t<int>, int>);
static_assert(std::is_same_v<std::common_type_t<int[]>, int*>);
static_assert(std::is_same_v<std::common_type_t<void()>, void(*)()>);
static_assert(std::is_same_v<std::common_type_t<void(&)()>, void(*)()>);
static_assert(std::is_same_v<std::common_type_t<void()>, void(*)()>);
static_assert(std::is_same_v<std::common_type_t<void>, void>);

//common_type_t<common type of first two, rest...> if more
static_assert(std::is_same_v<std::common_type_t<short, char, int>, int>);
static_assert(std::is_same_v<std::common_type_t<short, char>, int>);
static_assert(std::is_same_v<std::common_type_t<int, unsigned>, unsigned>);
static_assert(std::is_same_v<std::common_type_t<int, long long>, long long>);
static_assert(std::is_same_v<std::common_type_t<void, void>, void>);
static_assert(std::is_same_v<std::common_type_t<derived, base>, base>);
static_assert(std::is_same_v<std::common_type_t<constructible_from_int, double>, constructible_from_int>);

static_assert(not std::is_detected_v<try_common_type, int, const char*>);
static_assert(not std::is_detected_v<try_common_type, base, void>);
