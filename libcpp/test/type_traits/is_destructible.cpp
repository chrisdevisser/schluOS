#include <type_traits>

struct destructible {};

struct not_destructible {
    ~not_destructible() = delete;
};

class private_destructible {
    ~private_destructible() {}
};

struct protected_destructible {
protected:
    ~protected_destructible() {}
};

//TODO: SFINAE

static_assert(std::is_destructible_v<int>);
static_assert(std::is_destructible_v<const int>);
static_assert(std::is_destructible_v<volatile int>);
static_assert(std::is_destructible_v<const volatile int>);
static_assert(std::is_destructible_v<int[]>);
static_assert(std::is_destructible_v<int[5]>);
static_assert(std::is_destructible_v<int&>);
static_assert(std::is_destructible_v<int&&>);
static_assert(std::is_destructible_v<int*>);
static_assert(std::is_destructible_v<destructible>);

static_assert(not std::is_destructible_v<void>);
static_assert(not std::is_destructible_v<void()>);
static_assert(not std::is_destructible_v<not_destructible>);
static_assert(not std::is_destructible_v<private_destructible>);

struct protected_test : protected_destructible {
    static_assert(not std::is_destructible_v<protected_destructible>);
};
