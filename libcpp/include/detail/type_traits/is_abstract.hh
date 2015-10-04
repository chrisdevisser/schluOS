#pragma once

#include "bool_constant.hh"

namespace std {

///is_abstract - [meta.unary.prop]
///True iff _T is an abstract class per [class.abstract].
template<typename _T>
struct is_abstract : bool_constant<__is_abstract(_T)> {};

template<typename _T>
constexpr auto is_abstract_v{is_abstract<_T>::value};

}
