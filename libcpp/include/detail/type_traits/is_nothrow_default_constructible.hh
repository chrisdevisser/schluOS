#pragma once

#include "is_nothrow_constructible.hh"

namespace std {

///is_nothrow_default_constructible - [meta.unary.prop]
///True iff is_nothrow_constructible_v<_Type> is true.
template<typename _Type>
struct is_nothrow_default_constructible : is_nothrow_constructible<_Type> {};

template<typename _Type>
constexpr auto is_nothrow_default_constructible_v{is_nothrow_default_constructible<_Type>::value};

}
