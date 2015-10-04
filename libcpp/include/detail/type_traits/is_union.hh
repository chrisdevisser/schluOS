#pragma once

#include "bool_constant.hh"

namespace std {

///is_union - [meta.unary.cat]
///True iff T is a union type per [basic.compound].
//One of this and is_class is impossible to implement without compiler support.
template<typename _T>
struct is_union : bool_constant<__is_union(_T)> {};

template<typename _T>
constexpr auto is_union_v{is_union<_T>::value};

}
