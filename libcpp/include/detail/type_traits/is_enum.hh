#pragma once

#include "bool_constant.hh"

namespace std {

///is_enum - [meta.unary.cat]
///True iff remove_cv_t<_T> is an enumeration type per [basic.compound].
//This is impossible to implement without compiler support or ugly hacks.
template<typename _T>
struct is_enum : bool_constant<__is_enum(_T)> {};

template<typename _T>
constexpr auto is_enum_v{is_enum<_T>::value};

}
