#pragma once

#include "add_const.hh"
#include "add_lvalue_reference.hh"
#include "is_constructible.hh"

namespace std {

///is_copy_constructible - [meta.unary.prop]
///True iff is_constructible_v<_Type, const _Type&> is true.
template<typename _Type>
struct is_copy_constructible : is_constructible<
    _Type,
    add_lvalue_reference_t<add_const_t<_Type>>
> {};

template<typename _Type>
constexpr auto is_copy_constructible_v{is_copy_constructible<_Type>::value};

}
