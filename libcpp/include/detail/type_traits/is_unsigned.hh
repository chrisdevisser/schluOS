#pragma once

#include "bool_constant.hh"
#include "is_arithmetic.hh"
#include "is_signed.hh"

namespace std {

///is_unsigned - [meta.unary.prop]
///True iff is_arithmetic_v<_T> is true and _T(0) < _T(-1).
template<typename _T>
struct is_unsigned : bool_constant<
    is_arithmetic_v<_T>
    and not is_signed_v<_T>
> {};

template<typename _T>
constexpr auto is_unsigned_v{is_unsigned<_T>::value};

}
