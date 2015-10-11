#pragma once

#include "add_const.hh"
#include "add_lvalue_reference.hh"
#include "is_nothrow_assignable.hh"

namespace std {

///is_nothrow_copy_assignable - [meta.unary.prop]
///For a referenceable type T, is_nothrow_assignable<T&, const T&>, otherwise false.
template<typename _T>
struct is_nothrow_copy_assignable : is_nothrow_assignable<
    add_lvalue_reference_t<_T>,
    add_lvalue_reference_t<add_const_t<_T>>
> {};

template<typename _T>
constexpr auto is_nothrow_copy_assignable_v{is_nothrow_copy_assignable<_T>::value};

}
