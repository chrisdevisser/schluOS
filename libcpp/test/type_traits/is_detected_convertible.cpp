#include <type_traits>

struct nested_type_not_convertible_to_int {};

struct nested_type_convertible_to_int {
    operator int() const {return 0;}
};

struct has_type_convertible_to_int {
    using type = nested_type_convertible_to_int;
};

struct has_type_not_convertible_to_int {
 using type = nested_type_not_convertible_to_int;
};

struct does_not_have_type {};

template<typename T>
using detect_type = typename T::type;

static_assert(std::is_detected_convertible_v<int, detect_type, has_type_convertible_to_int>);
static_assert(not std::is_detected_convertible_v<int, detect_type, has_type_not_convertible_to_int>);

static_assert(not std::is_detected_convertible_v<std::nonesuch, detect_type, does_not_have_type>);
