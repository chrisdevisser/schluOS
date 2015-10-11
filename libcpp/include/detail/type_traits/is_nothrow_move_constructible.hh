#pragma once

#include "add_rvalue_reference.hh"
#include "is_nothrow_constructible.hh"

namespace std {

///is_nothrow_move_constructible - [meta.unary.prop]
///For a referenceable type T, is_nothrow_constructible_v<T, T&&>, otherwise false.
template<typename _Type>
struct is_nothrow_move_constructible : is_nothrow_constructible<
    _Type,
    add_rvalue_reference_t<_Type>
> {};

template<typename _Type>
constexpr auto is_nothrow_move_constructible_v{is_nothrow_move_constructible<_Type>::value};

}
