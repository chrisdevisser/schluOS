#pragma once

#include "bool_constant.hh"

namespace std {

///is_trivially_copyable - [meta.unary.prop]
///True iff _T is a trivially-copyable type per [basic.types].
template<typename _T>
struct is_trivially_copyable : bool_constant<__is_trivially_copyable(_T)> {};

template<typename _T>
constexpr auto is_trivially_copyable_v{is_trivially_copyable<_T>::value};

}
