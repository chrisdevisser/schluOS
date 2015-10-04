#pragma once

#include "bool_constant.hh"

namespace std {

///is_pod - [meta.unary.prop]
///True iff _T is a POD type per [basic.types].
template<typename _T>
struct is_pod : bool_constant<__is_pod(_T)> {};

template<typename _T>
constexpr auto is_pod_v{is_pod<_T>::value};

}
