#pragma once

#include "false_type.hh"
#include "remove_cv.hh"
#include "true_type.hh"

namespace std {

namespace __detail {
    template<typename _T>
    struct __is_pointer_helper : false_type {};

    template<typename _T>
    struct __is_pointer_helper<_T*> : true_type {};
}

///is_pointer - [meta.unary.cat]
///True iff remove_cv_t<_T> is a pointer type per [basic.compound].
template<typename _T>
struct is_pointer : __detail::__is_pointer_helper<remove_cv_t<_T>> {};

template<typename _T>
constexpr auto is_pointer_v{is_pointer<_T>::value};

}
