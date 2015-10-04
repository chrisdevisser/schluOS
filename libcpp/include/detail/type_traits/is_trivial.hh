#pragma once

#include "bool_constant.hh"

namespace std {

///is_trivial - [meta.unary.prop]
///True iff _T is a trivial type per [basic.types].
template<typename _T>
struct is_trivial : bool_constant<__is_trivial(_T)> {};

template<typename _T>
constexpr auto is_trivial_v{is_trivial<_T>::value};

}
