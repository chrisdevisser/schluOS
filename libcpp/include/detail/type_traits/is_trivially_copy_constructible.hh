#pragma once

#include "add_const.hh"
#include "add_lvalue_reference.hh"
#include "is_trivially_constructible.hh"

namespace std {

///is_trivially_copy_constructible - [meta.unary.prop]
///For a referenceable type T, is_trivially_constructible_v<T, const T&>.
template<typename _Type>
struct is_trivially_copy_constructible : is_trivially_constructible<
    _Type,
    add_lvalue_reference_t<add_const_t<_Type>>
> {};

template<typename _Type>
constexpr auto is_trivially_copy_constructible_v{is_trivially_copy_constructible<_Type>::value};

}
