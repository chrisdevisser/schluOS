#include <type_traits>

struct nested_type {};

struct does_have_type {
    using type = nested_type;
};

struct does_not_have_type {};

template<typename T>
using detect_type = typename T::type;

static_assert(std::is_detected_exact_v<nested_type, detect_type, does_have_type>);
static_assert(not std::is_detected_exact_v<nested_type, detect_type, does_not_have_type>);

static_assert(std::is_detected_exact_v<std::nonesuch, detect_type, does_not_have_type>);
