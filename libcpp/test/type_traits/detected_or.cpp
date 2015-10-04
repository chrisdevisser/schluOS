#include <type_traits>

struct nested_type {};

struct does_have_type {
    using type = nested_type;
};

struct does_not_have_type {};

struct default_type {};

template<typename T>
using detect_type = typename T::type;

static_assert(
    std::is_same_v<
        std::detected_or_t<default_type, detect_type, does_have_type>,
        nested_type
    >
);

static_assert(
    std::is_same_v<
        std::detected_or_t<default_type, detect_type, does_not_have_type>,
        default_type
    >
);
