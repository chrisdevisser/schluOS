#pragma once

#include "is_constructible.hh"

namespace std {

///is_move_constructible - [meta.unary.prop]
///True iff is_constructible_v<_Type, _Type&&> is true.
template<typename _Type>
struct is_move_constructible : is_constructible<_Type, _Type&&> {};

template<typename _Type>
constexpr auto is_move_constructible_v{is_move_constructible<_Type>::value};

}
