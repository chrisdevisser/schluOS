#include <type_traits>

#include <detail/functional/invoke.hh>

using namespace std::__detail;

constexpr void returns_void() noexcept {}
constexpr int returns_2() noexcept {return 2;}

constexpr void takes_int_and_pointer(int, const void*) noexcept {}
constexpr void takes_int_ref(int&) noexcept {}

struct structure {
    int two_pmd{2};

    constexpr void returns_void() noexcept {}
    constexpr void returns_void_const() const noexcept {}
    constexpr void returns_void_ref() & noexcept {}
};

structure object;
structure& reference{object};
structure* pointer{&object};
constexpr const structure const_object;
constexpr const structure& const_reference{const_object};
constexpr const structure* const_pointer{&const_object};

struct derived_structure : structure {};

derived_structure derived_object;
derived_structure& derived_reference{derived_object};
derived_structure* derived_pointer{&derived_object};
constexpr const derived_structure const_derived_object;
constexpr const derived_structure& const_derived_reference{const_derived_object};
constexpr const derived_structure* const_derived_pointer{&const_derived_object};

struct ptr_wrapper {
    const structure* obj{pointer};

    decltype(auto) operator*() const noexcept {return *obj;}
};

constexpr const ptr_wrapper const_special_pointer{const_pointer};
constexpr const ptr_wrapper& const_special_pointer_reference{const_pointer};


#define SAME_TYPE(expected, callable) std::is_same_v<decltype(_INVOKE(callable)), expected>
#define SAME_TYPE_ARGS(expected, callable, ...) std::is_same_v<decltype(_INVOKE(callable, __VA_ARGS__)), expected>

#define SAME_VALUE(expected, callable) _INVOKE(callable) == expected
#define SAME_VALUE_ARGS(expected, callable, ...) _INVOKE(callable, __VA_ARGS__) == expected

//BASIC FREE FUNCTIONS
static_assert(SAME_TYPE(void, returns_void));
static_assert(SAME_TYPE(int, returns_2));
static_assert(SAME_TYPE(int, &returns_2));
static_assert(SAME_VALUE(2, returns_2));

//FREE FUNCTIONS WITH PARAMETERS
int int_;
static_assert(SAME_TYPE_ARGS(void, takes_int_and_pointer, 2, "abc"));
static_assert(SAME_TYPE_ARGS(void, takes_int_ref, int_));

//PMD
static_assert(SAME_TYPE_ARGS(int&&, &structure::two_pmd, structure{}));
static_assert(SAME_VALUE_ARGS(2, &structure::two_pmd, structure{}));
static_assert(SAME_TYPE_ARGS(int&, &structure::two_pmd, object));
static_assert(SAME_TYPE_ARGS(int&, &structure::two_pmd, reference));
static_assert(SAME_TYPE_ARGS(int&, &structure::two_pmd, pointer));

//PMD THROUGH CONST
static_assert(SAME_TYPE_ARGS(const int&, &structure::two_pmd, const_object));
static_assert(SAME_TYPE_ARGS(const int&, &structure::two_pmd, const_reference));
static_assert(SAME_TYPE_ARGS(const int&, &structure::two_pmd, const_pointer));
static_assert(SAME_VALUE_ARGS(2, &structure::two_pmd, const_object));
static_assert(SAME_VALUE_ARGS(2, &structure::two_pmd, const_reference));
static_assert(SAME_VALUE_ARGS(2, &structure::two_pmd, const_pointer));

//PMD THROUGH DERIVED
static_assert(SAME_TYPE_ARGS(int&, &structure::two_pmd, derived_reference));
static_assert(SAME_TYPE_ARGS(int&, &structure::two_pmd, derived_pointer));

//PMD THROUGH CONST DERIVED
static_assert(SAME_TYPE_ARGS(const int&, &structure::two_pmd, const_derived_reference));
static_assert(SAME_TYPE_ARGS(const int&, &structure::two_pmd, const_derived_pointer));
static_assert(SAME_VALUE_ARGS(2, &structure::two_pmd, const_derived_reference));
static_assert(SAME_VALUE_ARGS(2, &structure::two_pmd, const_derived_pointer));

//PMD THROUGH SPECIAL POINTER
static_assert(SAME_TYPE_ARGS(const int&, &structure::two_pmd, const_special_pointer));
static_assert(SAME_TYPE_ARGS(const int&, &structure::two_pmd, const_special_pointer_reference));

//PMF
static_assert(SAME_TYPE_ARGS(void, &structure::returns_void, object));
static_assert(SAME_TYPE_ARGS(void, &structure::returns_void, reference));
static_assert(SAME_TYPE_ARGS(void, &structure::returns_void, pointer));

//PMF with cv
static_assert(SAME_TYPE_ARGS(void, &structure::returns_void_const, object));
static_assert(SAME_TYPE_ARGS(void, &structure::returns_void_const, reference));
static_assert(SAME_TYPE_ARGS(void, &structure::returns_void_const, pointer));

//PMF with ref
static_assert(SAME_TYPE_ARGS(void, &structure::returns_void_ref, object));
static_assert(SAME_TYPE_ARGS(void, &structure::returns_void_ref, reference));
static_assert(SAME_TYPE_ARGS(void, &structure::returns_void_ref, pointer));

//PMF THROUGH CONST
static_assert(SAME_TYPE_ARGS(void, &structure::returns_void_const, const_object));
static_assert(SAME_TYPE_ARGS(void, &structure::returns_void_const, const_reference));
static_assert(SAME_TYPE_ARGS(void, &structure::returns_void_const, const_pointer));

//PMF THROUGH DERIVED
static_assert(SAME_TYPE_ARGS(void, &structure::returns_void, derived_reference));
static_assert(SAME_TYPE_ARGS(void, &structure::returns_void, derived_pointer));

//PMF THROUGH SPECIAL POINTER
static_assert(SAME_TYPE_ARGS(void, &structure::returns_void_const, const_special_pointer));
static_assert(SAME_TYPE_ARGS(void, &structure::returns_void_const, const_special_pointer_reference));
