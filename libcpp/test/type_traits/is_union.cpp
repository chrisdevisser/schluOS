#include <type_traits>

struct structure {};
class class_ {};
union union_ {};

static_assert(std::is_union_v<union_>);
static_assert(std::is_union_v<const union_>);
static_assert(std::is_union_v<volatile union_>);
static_assert(std::is_union_v<const volatile union_>);

static_assert(not std::is_union_v<class_>);
static_assert(not std::is_union_v<structure>);
static_assert(not std::is_union_v<union_*>);
static_assert(not std::is_union_v<union_&>);
