#pragma once

#include "bool_constant.hh"
#include "is_assignable.hh"

namespace std {

///is_trivially_assignable - [meta.unary.prop]
///True iff is_assignable_v<_Lhs, _Rhs> is true and no operation is non-trivial.
template<typename _Lhs, typename _Rhs>
struct is_trivially_assignable : bool_constant<
    is_assignable_v<_Lhs, _Rhs>
    and __is_trivially_assignable(_Lhs, _Rhs)
> {};

template<typename _Lhs, typename _Rhs>
constexpr auto is_trivially_assignable_v{is_trivially_assignable<_Lhs, _Rhs>::value};

}
