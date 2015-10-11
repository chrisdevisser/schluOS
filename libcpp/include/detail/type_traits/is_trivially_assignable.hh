#pragma once

#include "detail/all.hh"
#include "is_assignable.hh"

namespace std {

///is_trivially_assignable - [meta.unary.prop]
///True iff is_assignable_v<_From, _To> is true and no operation is non-trivial.
template<typename _From, typename _To>
struct is_trivially_assignable : __detail::__all<
    is_assignable_v<_From, _To>,
    __is_trivially_assignable(_From, _To)
> {};

template<typename _From, typename _To>
constexpr auto is_trivially_assignable_v{is_trivially_assignable<_From, _To>::value};

}
