#pragma once

namespace std {

///remove_const - [meta.trans.cv]
///_T with any top-level const-qualifier removed.
template<typename _T>
struct remove_const {
    using type = _T;
};

template<typename _T>
struct remove_const<const _T> : remove_const<_T> {};

template<typename _T>
using remove_const_t = typename remove_const<_T>::type;

}
