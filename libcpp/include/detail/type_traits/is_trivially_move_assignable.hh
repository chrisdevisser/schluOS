#pragma once

#include "add_lvalue_reference.hh"
#include "add_rvalue_reference.hh"
#include "is_trivially_assignable.hh"

namespace std {

///is_trivially_move_assignable - [meta.unary.prop]
///For a referenceable type T, is_trivially_assignable_v<T&, T&&>.
template<typename _T>
struct is_trivially_move_assignable : is_trivially_assignable<
    add_lvalue_reference_t<_T>,
    add_rvalue_reference_t<_T>
> {};

template<typename _T>
constexpr auto is_trivially_move_assignable_v{is_trivially_move_assignable<_T>::value};

}
