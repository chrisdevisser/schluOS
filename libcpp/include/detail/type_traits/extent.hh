#pragma once

#include <detail/size_t.hh>

#include "integral_constant.hh"
#include "is_array.hh"

namespace std {

///extent - [meta.unary.prop.query]
///If _T is not an array type, or if it has rank <= _I,
///or if _I is 0 and _T is an array of unknown bound of U, then 0.
///Otherwise, the bound of the _Ith dimension of _T, where
///indexing of _I is zero-based.

//Default to 0 when _I reaches 0 to handle all the special cases.
template<typename _T, unsigned _I = 0>
struct extent : integral_constant<size_t, 0> {};

//T[] => 0 when _I is 0, otherwise decrement _I and check _T.
template<typename _T, unsigned _I>
struct extent<_T[], _I> : integral_constant<
    size_t,
    _I == 0 ? 0 : extent<_T, _I - 1>::value
> {};

//_T[_N] => _N when _I is 0, otherwise decrement _I and check _T.
template<typename _T, size_t _N, unsigned _I>
struct extent<_T[_N], _I> : integral_constant<
    size_t,
    _I == 0 ? _N : extent<_T, _I - 1>::value
> {};

template<typename _T, unsigned _I = 0>
constexpr auto extent_v{extent<_T, _I>::value};

}
