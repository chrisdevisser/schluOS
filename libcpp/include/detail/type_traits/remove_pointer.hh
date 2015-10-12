#pragma once

#include "remove_cv.hh"

namespace std {

namespace __detail {
    template<typename _T>
    struct __remove_pointer {
        using type = _T;
    };

    template<typename _T>
    struct __remove_pointer<_T*> {
        using type = _T;
    };
}

///remove_pointer - [meta.trans.ptr]
///If _T is a possibly cv-qualified pointer to T1, then T1, otherwise _T.
template<typename _T>
struct remove_pointer : __detail::__remove_pointer<remove_cv_t<_T>> {};

template<typename _T>
using remove_pointer_t = typename remove_pointer<_T>::type;

}
