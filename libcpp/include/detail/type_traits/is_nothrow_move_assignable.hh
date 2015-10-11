#pragma once

#include "add_rvalue_reference.hh"
#include "is_nothrow_assignable.hh"

namespace std {

///is_nothrow_move_assignable - [meta.unary.prop]
///For a referenceable type T, is_nothrow_assignable<T&, T&&>, otherwise false.
template<typename _T>
struct is_nothrow_move_assignable : is_nothrow_assignable<
    _T,
    add_rvalue_reference_t<_T>
> {};

template<typename _T>
constexpr auto is_nothrow_move_assignable_v{is_nothrow_move_assignable<_T>::value};

}
