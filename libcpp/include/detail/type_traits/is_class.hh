#pragma once

#include "bool_constant.hh"

namespace std {

///is_class - [meta.unary.cat]
///True iff T is a class type, but not a union type, per [basic.compound].
//One of this and is_union is impossible to implement without compiler support.
template<typename _T>
struct is_class : bool_constant<__is_class(_T)> {};

template<typename _T>
constexpr auto is_class_v{is_class<_T>::value};

}
