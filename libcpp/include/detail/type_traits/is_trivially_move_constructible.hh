#pragma once

#include "add_rvalue_reference.hh"
#include "is_trivially_constructible.hh"

namespace std {

///is_trivially_move_constructible - [meta.unary.prop]
///For a referenceable type T, is_trivially_constructible_v<T, T&&>.
template<typename _Type>
struct is_trivially_move_constructible : is_trivially_constructible<
    _Type,
    add_rvalue_reference_t<_Type>
> {};

template<typename _Type>
constexpr auto is_trivially_move_constructible_v{is_trivially_move_constructible<_Type>::value};

}
