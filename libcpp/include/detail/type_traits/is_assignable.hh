#pragma once

#include <detail/declval.hh>

#include "bool_constant.hh"
#include "is_detected.hh"

namespace std {

namespace __detail {
    template<typename _From, typename _To>
    using __assign_test = decltype(declval<_From>() = declval<_To>());
}

///is_assignable - [meta.unary.prop]
///True iff declval<_From>() = declval<_To>() is well-formed
///when treated as an unevaluated operand.
template<typename _From, typename _To>
using is_assignable = is_detected<__detail::__assign_test, _From, _To>;

template<typename _From, typename _To>
constexpr auto is_assignable_v{is_assignable<_From, _To>::value};

}