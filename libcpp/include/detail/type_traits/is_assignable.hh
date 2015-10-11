#pragma once

#include <detail/declval.hh>

#include "bool_constant.hh"
#include "is_detected.hh"

namespace std {

namespace __detail {
    template<typename _Lhs, typename _Rhs>
    using __assign_test = decltype(declval<_Lhs>() = declval<_Rhs>());
}

///is_assignable - [meta.unary.prop]
///True iff declval<_Lhs>() = declval<_Rhs>() is well-formed
///when treated as an unevaluated operand.
template<typename _Lhs, typename _Rhs>
using is_assignable = is_detected<__detail::__assign_test, _Lhs, _Rhs>;

template<typename _Lhs, typename _Rhs>
constexpr auto is_assignable_v{is_assignable<_Lhs, _Rhs>::value};

}
