#pragma once

#include "bool_constant.hh"

namespace std {

///is_standard_layout - [meta.unary.prop]
///True iff _T is a standard-layout type per [basic.types].
template<typename _T>
struct is_standard_layout : bool_constant<__is_standard_layout(_T)> {};

template<typename _T>
constexpr auto is_standard_layout_v{is_standard_layout<_T>::value};

}
