#pragma once

#include <detail/utility/declval.hh>

#include "bool_constant.hh"
#include "is_assignable.hh"

namespace std {

///is_nothrow_assignable - [meta.unary.prop]
///True iff is_assignable_v<_Lhs, _Rhs> is true and this
///is known not to throw any exceptions.
template<typename _Lhs, typename _Rhs>
struct is_nothrow_assignable : bool_constant<
    is_assignable_v<_Lhs, _Rhs>
    and nothrow(declval<_Lhs>() = declval<_Rhs>())
> {};

template<typename _Lhs, typename _Rhs>
constexpr auto is_nothrow_assignable_v{is_nothrow_assignable<_Lhs, _Rhs>::value};

}
