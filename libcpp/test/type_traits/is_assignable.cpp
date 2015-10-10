#include <type_traits>

struct assignable_from_int {
    assignable_from_int& operator=(int) {return *this;}
};

struct not_assignable_from_int {};

struct explicitly_convertible_to_int {
    explicit operator int() const {return 0;}
};

struct assignment_from_int_returns_void {
    void operator=(int) {}
};

class private_assignable_from_int {
    private_assignable_from_int& operator=(int) {return *this;}
};

struct protected_assignable_from_int {
protected:
    protected_assignable_from_int& operator=(int) {return *this;}
};

//TODO: SFINAE

static_assert(std::is_assignable_v<assignable_from_int, int>);
static_assert(std::is_assignable_v<assignable_from_int&, int>);
static_assert(std::is_assignable_v<assignable_from_int&&, int>);
static_assert(std::is_assignable_v<int&, int>);
static_assert(std::is_assignable_v<int&, int&>);
static_assert(std::is_assignable_v<int&, int&&>);
static_assert(std::is_assignable_v<int*&, int*>);
static_assert(std::is_assignable_v<assignment_from_int_returns_void&, int>);
static_assert(std::is_assignable_v<void(*&)(), void()>);

static_assert(std::is_assignable_v<assignable_from_int, const int>);
static_assert(std::is_assignable_v<assignable_from_int, volatile int>);
static_assert(std::is_assignable_v<assignable_from_int, const volatile int>);

static_assert(not std::is_assignable_v<int, int>);
static_assert(not std::is_assignable_v<int*, int*>);
static_assert(not std::is_assignable_v<not_assignable_from_int&, int>);
static_assert(not std::is_assignable_v<void, int>);
static_assert(not std::is_assignable_v<int&, void>);
static_assert(not std::is_assignable_v<void, void>);
static_assert(not std::is_assignable_v<int[], int[]>);
static_assert(not std::is_assignable_v<int(&)[], int[]>);
static_assert(not std::is_assignable_v<private_assignable_from_int&, int>);
static_assert(not std::is_assignable_v<int[5], int>);
static_assert(not std::is_assignable_v<int(&)[5], int>);
static_assert(not std::is_assignable_v<int(&)[5], int[5]>);
static_assert(not std::is_assignable_v<void(), void()>);
static_assert(not std::is_assignable_v<void(&)(), void()>);
static_assert(not std::is_assignable_v<void*&, void(*)()>);

struct protected_test : protected_assignable_from_int {
    static_assert(not std::is_assignable_v<protected_assignable_from_int&, int>);
};
