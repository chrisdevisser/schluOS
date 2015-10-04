#pragma once

#include "bool_constant.hh"

namespace std {

///is_polymorphic - [meta.unary.prop]
///True iff _T is a polymorphic class per [class.virtual].
template<typename _T>
struct is_polymorphic : bool_constant<__is_polymorphic(_T)> {};

template<typename _T>
constexpr auto is_polymorphic_v{is_polymorphic<_T>::value};

}
