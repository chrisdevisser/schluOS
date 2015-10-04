#pragma once

namespace std {

///remove_volatile - [meta.trans.cv]
///_T with any top-level volatile-qualifier removed.
template<typename _T>
struct remove_volatile {
    using type = _T;
};

template<typename _T>
struct remove_volatile<volatile _T> : remove_volatile<_T> {};

template<typename _T>
using remove_volatile_t = typename remove_volatile<_T>::type;

}
