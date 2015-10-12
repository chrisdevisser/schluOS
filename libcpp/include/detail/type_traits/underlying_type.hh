#pragma once

#include "bool_constant.hh"

namespace std {

///underlying_type - [meta.trans.other]
///For an enum type, the underlying type of that enum.
template<typename _T>
struct underlying_type {
    using type = __underlying_type(_T);
};

template<typename _T>
using underlying_type_t = typename underlying_type<_T>::type;

}
