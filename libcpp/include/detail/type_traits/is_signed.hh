#pragma once

#include "bool_constant.hh"
#include "false_type.hh"
#include "is_arithmetic.hh"

namespace std {

namespace __detail {
    //This is so the casts aren't applied to non-arithmetic types.
    template<typename _T, bool _IsArithmetic>
    struct __is_signed_helper : false_type {};

    template<typename _T>
    struct __is_signed_helper<_T, true> : bool_constant<_T(-1) < _T(0)> {};
}

///is_signed - [meta.unary.prop]
///True iff is_arithmetic_v<_T> is true and _T(-1) < _T(0).
template<typename _T>
struct is_signed : __detail::__is_signed_helper<_T, is_arithmetic_v<_T>> {};

template<typename _T>
constexpr auto is_signed_v{is_signed<_T>::value};

}
