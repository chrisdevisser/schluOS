#include <type_traits>

struct structure {};

static_assert(std::is_member_pointer_v<int structure::*>);
static_assert(std::is_member_pointer_v<int structure::* const>);
static_assert(std::is_member_pointer_v<int structure::* volatile>);
static_assert(std::is_member_pointer_v<int structure::* const volatile>);

static_assert(std::is_member_pointer_v<void(structure::*)()>);
static_assert(std::is_member_pointer_v<void(structure::* const)()>);
static_assert(std::is_member_pointer_v<void(structure::*)() const>);
static_assert(std::is_member_pointer_v<void(structure::*)() &>);
static_assert(std::is_member_pointer_v<void(structure::*)() &&>);

static_assert(not std::is_member_pointer_v<void()>);
static_assert(not std::is_member_pointer_v<void(*)()>);
