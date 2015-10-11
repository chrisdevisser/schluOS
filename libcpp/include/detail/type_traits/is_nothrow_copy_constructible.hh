#pragma once

#include "add_const.hh"
#include "add_lvalue_reference.hh"
#include "is_nothrow_constructible.hh"

namespace std {

///is_nothrow_copy_constructible - [meta.unary.prop]
///For a referenceable type T, is_nothrow_constructible_v<T, const T&>, otherwise false.
template<typename _Type>
struct is_nothrow_copy_constructible : is_nothrow_constructible<
    _Type,
    add_lvalue_reference_t<add_const_t<_Type>>
> {};

template<typename _Type>
constexpr auto is_nothrow_copy_constructible_v{is_nothrow_copy_constructible<_Type>::value};

}
