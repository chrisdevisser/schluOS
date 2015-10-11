#pragma once

namespace std {

///add_const - [meta.trans.cv]
///If _T is a reference, function, or top-level const-qualified type,
///then _T, otherwise const _T.
//References, functions, and top-level const-qualified types just work.
template<typename _T>
struct add_const {
    using type = const _T;
};

template<typename _T>
using add_const_t = typename add_const<_T>::type;

}
