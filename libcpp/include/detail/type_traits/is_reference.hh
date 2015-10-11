#pragma once

#include "bool_constant.hh"
#include "is_lvalue_reference.hh"
#include "is_rvalue_reference.hh"

namespace std {

///is_reference - [meta.unary.comp]
///True iff remove_cv_t<_T> is an lvalue reference or an rvalue reference.
template<typename _T>
struct is_reference : bool_constant<
    is_lvalue_reference_v<_T>
    or is_rvalue_reference_v<_T>
> {};

template<typename _T>
constexpr auto is_reference_v{is_reference<_T>::value};

}
