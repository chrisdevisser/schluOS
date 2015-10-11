#pragma once

namespace std {

///remove_reference - [meta.trans.ref]
///If _T is a reference to T1, then T1, otherwise _T.
template<typename _T>
struct remove_reference {
    using type = _T;
};

template<typename _T>
struct remove_reference<_T&> : remove_reference<_T> {};

template<typename _T>
struct remove_reference<_T&&> : remove_reference<_T> {};

template<typename _T>
using remove_reference_t = typename remove_reference<_T>::type;

}
