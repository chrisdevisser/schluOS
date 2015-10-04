#pragma once

#include "bool_constant.hh"

namespace std {

///is_empty - [meta.unary.prop]
///True iff _T is a class type, but not a union type, with no
///non-static data members other than bit-fields of length 0,
///no virtual member functions, no virtual base classes,
///and no base class B for which is_empty_v<B> is false.
template<typename _T>
struct is_empty : bool_constant<__is_empty(_T)> {};

template<typename _T>
constexpr auto is_empty_v{is_empty<_T>::value};

}
