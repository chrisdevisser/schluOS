#pragma once

#include <detail/size_t.hh>

#include "is_array_of_unknown_bound.hh"
#include "true_type.hh"

namespace std {

///is_array - [meta.unary.cat]
///True iff _T is an array type per [basic.compound]/1, of known or unknown extent.
template<typename _T>
struct is_array : __detail::__is_array_of_unknown_bound<_T> {};

template<typename _T, size_t _N>
struct is_array<_T[_N]> : true_type {};

template<typename _T>
constexpr auto is_array_v{is_array<_T>::value};

}
