#pragma once

#include "detail/any.hh"
#include "is_arithmetic.hh"
#include "is_void.hh"
#include "is_null_pointer.hh"

namespace std {

///is_fundamental - [meta.unary.comp]
///True iff remove_cv_t<_T> is a fundamental type per [basic.fundamental].
template<typename _T>
struct is_fundamental : __detail::__any<
    is_arithmetic_v<_T>,
    is_null_pointer_v<_T>,
    is_void_v<_T>
> {};

template<typename _T>
constexpr auto is_fundamental_v{is_fundamental<_T>::value};

}
