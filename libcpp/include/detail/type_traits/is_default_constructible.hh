#pragma once

#include "is_constructible.hh"

namespace std {

///is_default_constructible - [meta.unary.prop]
///True iff is_constructible_v<_Type> is true.
template<typename _Type>
struct is_default_constructible : is_constructible<_Type> {};

template<typename _Type>
constexpr auto is_default_constructible_v{is_default_constructible<_Type>::value};

}
