#pragma once

#include <detail/size_t.hh>

#include "integral_constant.hh"

namespace std {

///rank - [meta.unary.prop.query]
///If _T names an array type, the number of dimensions of _T, otherwise 0.
template<typename _T>
struct rank : integral_constant<size_t, 0> {};

template<typename _T>
struct rank<_T[]> : integral_constant<
    size_t,
    1 + rank<_T>::value
> {};

template<typename _T, size_t _N>
struct rank<_T[_N]> : rank<_T[]> {};

template<typename _T>
constexpr auto rank_v{rank<_T>::value};

}
