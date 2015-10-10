#include <detail/type_traits/detail/any.hh>

using namespace std::__detail;

static_assert(not __any_v<>);

static_assert(__any_v<true>);
static_assert(not __any_v<false>);

static_assert(__any_v<true, true>);
static_assert(__any_v<true, false>);
static_assert(__any_v<false, true>);
static_assert(not __any_v<false, false>);
