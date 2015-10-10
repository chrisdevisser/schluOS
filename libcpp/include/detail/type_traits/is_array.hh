#pragma once

#include "any.hh"
#include "is_array_of_known_bound.hh"
#include "is_array_of_unknown_bound.hh"

namespace std {

///is_array - [meta.unary.cat]
///True iff _T is an array type per [basic.compound]/1, of known or unknown extent.
template<typename _T>
struct is_array : __detail::__any<
    __detail::__is_array_of_known_bound_v<_T>,
    __detail::__is_array_of_unknown_bound_v<_T>
> {};

template<typename _T, size_t _N>
struct is_array<_T[_N]> : true_type {};

template<typename _T>
constexpr auto is_array_v{is_array<_T>::value};

}
