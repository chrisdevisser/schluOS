#pragma once

#include "detail/any.hh"
#include "is_floating_point.hh"
#include "is_integral.hh"

namespace std {

///is_arithmetic - [meta.unary.comp]
///True iff remove_cv_t<_T> is an arithmetic type per [basic.fundamental].
template<typename _T>
struct is_arithmetic : __detail::__any<is_integral_v<_T>, is_floating_point_v<_T>> {};

template<typename _T>
constexpr auto is_arithmetic_v{is_arithmetic<_T>::value};

}
