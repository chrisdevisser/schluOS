#include <type_traits>

struct structure {};
class class_ {};
union union_ {};

static_assert(std::is_class_v<class_>);
static_assert(std::is_class_v<structure>);
static_assert(std::is_class_v<const class_>);
static_assert(std::is_class_v<volatile class_>);
static_assert(std::is_class_v<const volatile class_>);

static_assert(not std::is_class_v<union_>);
static_assert(not std::is_class_v<class_*>);
static_assert(not std::is_class_v<class_&>);
static_assert(not std::is_class_v<structure*>);
static_assert(not std::is_class_v<structure&>);
