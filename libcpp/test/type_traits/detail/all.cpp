#include <detail/type_traits/detail/all.hh>

using namespace std::__detail;

static_assert(__all_v<>);

static_assert(__all_v<true>);
static_assert(not __all_v<false>);

static_assert(__all_v<true, true>);
static_assert(not __all_v<true, false>);
static_assert(not __all_v<false, true>);
static_assert(not __all_v<false, false>);
