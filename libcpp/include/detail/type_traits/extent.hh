#pragma once

#include <detail/size_t.hh>

#include "integral_constant.hh"
#include "is_array.hh"
#include "remove_extent.hh"

namespace std {

///extent - [meta.unary.prop.query]
///If _T is not an array type, or if it has rank <= _I,
///or if _I is 0 and _T is an array of unknown bound of U, then 0.
///Otherwise, the bound of the _Ith dimension of _T, where
///indexing of _I is zero-based.
template<typename _T, unsigned _I = 0>
struct extent;

//Default to 0 when _I reaches 0 to handle all the special cases.
template<typename _T>
struct extent<_T, 0> : integral_constant<size_t, 0> {};

//_I is 0 and _T is an array of known bound => that bound
template<typename _T, size_t _N>
struct extent<_T[_N], 0> : integral_constant<size_t, _N> {};

//General _T and _I => decrement _I and remove a layer of _T
//If not an array, quit early to avoid many instantiations.
template<typename _T, unsigned _I>
struct extent<_T, _I> : extent<
    remove_extent_t<_T>,
    is_array_v<_T> ? _I - 1 : 0
> {};

template<typename _T, unsigned _I = 0>
constexpr auto extent_v{extent<_T, _I>::value};

}
