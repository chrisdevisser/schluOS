#pragma once

namespace std {

///add_volatile - [meta.trans.cv]
///If _T is a reference, function, or top-level volatile-qualified type,
///then _T, otherwise volatile _T.
//References, functions, and top-level volatile-qualified types just work.
template<typename _T>
struct add_volatile {
    using type = volatile _T;
};

template<typename _T>
using add_volatile_t = typename add_volatile<_T>::type;

}
