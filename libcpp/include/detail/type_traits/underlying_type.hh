#pragma once

#include "is_enum.hh"

namespace std {

namespace __detail {
    template<typename _T, bool = is_enum_v<_T>>
    struct __underlying_type_helper {
        using type = _T;
    };

    template<typename _T>
    struct __underlying_type_helper<_T, true> {
        using type = __underlying_type(_T);
    };
}

///underlying_type - [meta.trans.other]
///For an enum type, the underlying type of that enum.
template<typename _T>
struct underlying_type : __detail::__underlying_type_helper<_T> {};

template<typename _T>
using underlying_type_t = typename underlying_type<_T>::type;

}
