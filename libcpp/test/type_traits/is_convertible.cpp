#include <type_traits>

struct base {};
struct derived : base {};

struct structure {};
enum enumeration {};
enum class scoped_enumeration {};

struct convertible_from_int {
    convertible_from_int(int);
};

struct convertible_to_int {
    operator int() const;
};

struct explicitly_convertible_from_int {
    explicit explicitly_convertible_from_int(int);
};

struct explicitly_convertible_to_int {
    explicit operator int() const;
};

struct nonconst_convertible_to_int {
    operator int();
};

class private_convertible_to_int {
    operator int() const;
};

struct protected_convertible_to_int {
protected:
    operator int() const;
};

static_assert(std::is_convertible_v<int, int>);
static_assert(std::is_convertible_v<int, double>);
static_assert(std::is_convertible_v<int, char>);
static_assert(std::is_convertible_v<void, void>);

static_assert(std::is_convertible_v<int*, const int*>);
static_assert(std::is_convertible_v<int*, volatile int*>);
static_assert(std::is_convertible_v<int*, const volatile int*>);
static_assert(std::is_convertible_v<int*, int* const>);
static_assert(std::is_convertible_v<int*, int* volatile>);
static_assert(std::is_convertible_v<int*, int* const volatile>);
static_assert(std::is_convertible_v<int* const, int*>);

static_assert(std::is_convertible_v<int, const int&>);
static_assert(std::is_convertible_v<int, int&&>);

static_assert(std::is_convertible_v<int*, void*>);
static_assert(std::is_convertible_v<void(), void(*)()>);
static_assert(std::is_convertible_v<void(), void(&)()>);
static_assert(std::is_convertible_v<void(&)(), void(*)()>);
static_assert(std::is_convertible_v<int[], int*>);
static_assert(std::is_convertible_v<int[], int*>);

static_assert(std::is_convertible_v<derived, base>);
static_assert(std::is_convertible_v<derived*, base*>);
static_assert(std::is_convertible_v<derived&, base&>);

static_assert(std::is_convertible_v<int, convertible_from_int>);
static_assert(std::is_convertible_v<convertible_to_int, int>);
static_assert(std::is_convertible_v<enumeration, int>);

static_assert(not std::is_convertible_v<int, void>);
static_assert(not std::is_convertible_v<void, int>);
static_assert(not std::is_convertible_v<void, void()>);
static_assert(not std::is_convertible_v<int*, int[]>);
static_assert(not std::is_convertible_v<int**, const int**>);
static_assert(not std::is_convertible_v<void(structure::*)(), void(structure::*)() const>);
static_assert(not std::is_convertible_v<scoped_enumeration, int>);
static_assert(not std::is_convertible_v<int, explicitly_convertible_from_int>);
static_assert(not std::is_convertible_v<explicitly_convertible_to_int, int>);
static_assert(not std::is_convertible_v<const nonconst_convertible_to_int, int>);
static_assert(not std::is_convertible_v<private_convertible_to_int, int>);

struct protected_test : protected_convertible_to_int {
    static_assert(not std::is_convertible_v<protected_convertible_to_int, int>);
};
