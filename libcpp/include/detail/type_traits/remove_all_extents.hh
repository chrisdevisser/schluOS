#pragma once

#include <detail/size_t.hh>

namespace std {

///remove_all_extents - [meta.trans.arr]
///If _T is a multi-dimensional array of U, then U, else _T.
template<typename _T>
struct remove_all_extents {
    using type = _T;
};

template<typename _T>
struct remove_all_extents<_T[]> : remove_all_extents<_T> {};

template<typename _T, size_t _N>
struct remove_all_extents<_T[_N]> : remove_all_extents<_T> {};

template<typename _T>
using remove_all_extents_t = typename remove_all_extents<_T>::type;

}
