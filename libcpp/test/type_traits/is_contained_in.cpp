#include <detail/type_traits/detail/is_contained_in.hh>

using namespace std::__detail;

static_assert(not __is_contained_in_v<int>);

static_assert(__is_contained_in_v<int, int>);
static_assert(not __is_contained_in_v<int, char>);

static_assert(__is_contained_in_v<int, int, char>);
static_assert(__is_contained_in_v<int, char, int>);
static_assert(__is_contained_in_v<int, int, int>);
static_assert(not __is_contained_in_v<int, char, char>);
