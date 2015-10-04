#pragma once

#include "bool_constant.hh"

namespace std {

///is_literal_type - [meta.unary.prop]
///True iff _T is a literal type per [basic.types].
template<typename _T>
struct is_literal_type : bool_constant<__is_literal_type(_T)> {};

template<typename _T>
constexpr auto is_literal_type_v{is_literal_type<_T>::value};

}
