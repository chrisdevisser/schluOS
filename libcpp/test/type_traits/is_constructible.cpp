#include <type_traits>

struct default_constructible {};

struct not_constructible {
    not_constructible() = delete;
};

struct implicitly_constructible_from_int {
    implicitly_constructible_from_int(int) {}
};

struct explicitly_constructible_from_int {
    explicit explicitly_constructible_from_int(int) {}
};

struct explicitly_convertible_to_int {
    explicit operator int() const {return 0;}
};

class private_default_constructible {
    private_default_constructible() {}
};

struct protected_default_constructible {
protected:
    protected_default_constructible() {}
};

//TODO: SFINAE

static_assert(std::is_constructible_v<int>);
static_assert(std::is_constructible_v<int, int>);
static_assert(std::is_constructible_v<default_constructible>);
static_assert(std::is_constructible_v<implicitly_constructible_from_int, int>);
static_assert(std::is_constructible_v<explicitly_constructible_from_int, int>);
static_assert(std::is_constructible_v<implicitly_constructible_from_int, double>);
static_assert(std::is_constructible_v<explicitly_constructible_from_int, double>);
static_assert(std::is_constructible_v<int[5]>);
static_assert(std::is_constructible_v<int&, int&>);
static_assert(std::is_constructible_v<const int&, int>);
static_assert(std::is_constructible_v<int&&, int>);

static_assert(std::is_constructible_v<const default_constructible>);
static_assert(std::is_constructible_v<volatile default_constructible>);
static_assert(std::is_constructible_v<const volatile default_constructible>);

static_assert(not std::is_constructible_v<not_constructible>);
static_assert(not std::is_constructible_v<void>);
static_assert(not std::is_constructible_v<void, int>);
static_assert(not std::is_constructible_v<void, void>);
static_assert(not std::is_constructible_v<default_constructible, void>);
static_assert(not std::is_constructible_v<int[]>);
static_assert(not std::is_constructible_v<explicitly_constructible_from_int, explicitly_convertible_to_int>);
static_assert(not std::is_constructible_v<private_default_constructible>);
static_assert(not std::is_constructible_v<not_constructible[5]>);
static_assert(not std::is_constructible_v<int[5], int>);
static_assert(not std::is_constructible_v<int[5], int[5]>);

struct protected_test : protected_default_constructible {
    static_assert(not std::is_constructible_v<protected_default_constructible>);
};
