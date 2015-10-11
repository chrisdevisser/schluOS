#pragma once

#include "bool_constant.hh"
#include "is_destructible.hh"

namespace std {

///is_trivially_destructible - [meta.unary.prop]
///True iff is_destructible_v<_T> is true and is trivial.
template<typename _T>
struct is_trivially_destructible : bool_constant<
    is_destructible_v<_T>
    and __has_trivial_destructor(_T)
> {};

template<typename _T>
constexpr auto is_trivially_destructible_v{is_trivially_destructible<_T>::value};

}
