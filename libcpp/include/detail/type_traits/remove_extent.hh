#pragma once

#include <detail/size_t.hh>

namespace std {

///remove_extent - [meta.trans.arr]
///If _T is an array of U, then U, otherwise _T.
template<typename _T>
struct remove_extent {
    using type = _T;
};

template<typename _T>
struct remove_extent<_T[]> {
    using type = _T;
};

template<typename _T, size_t _N>
struct remove_extent<_T[_N]> : remove_extent<_T[]> {};

template<typename _T>
using remove_extent_t = typename remove_extent<_T>::type;

}
