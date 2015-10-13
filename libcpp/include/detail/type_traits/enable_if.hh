#pragma once

namespace std {

///enable_if - [meta.trans.other]
///If _Cond is true, then _T, else no member type.
template<bool _Cond, typename _T = void>
struct enable_if {};

template<typename _T>
struct enable_if<true, _T> {
    using type = _T;
};

template<bool _Cond, typename _T = void>
using enable_if_t = typename enable_if<_Cond, _T>::type;

}
