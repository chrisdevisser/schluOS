#pragma once

#include "is_trivially_constructible.hh"

namespace std {

///is_trivially_default_constructible - [meta.unary.prop]
///is_trivially_cosntructible_v<_Type>
template<typename _Type>
struct is_trivially_default_constructible : is_trivially_constructible<_Type> {};

template<typename _Type>
constexpr auto is_trivially_default_constructible_v{is_trivially_default_constructible<_Type>::value};

}
