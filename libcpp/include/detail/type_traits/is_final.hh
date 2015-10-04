#pragma once

#include "bool_constant.hh"

namespace std {

///is_final - [meta.unary.prop]
///True iff _T is a class marked final, including unions.
template<typename _T>
struct is_final : bool_constant<__is_final(_T)> {};

template<typename _T>
constexpr auto is_final_v{is_final<_T>::value};

}
