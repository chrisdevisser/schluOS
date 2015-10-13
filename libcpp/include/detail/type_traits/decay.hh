#pragma once

#include "add_pointer.hh"
#include "is_array.hh"
#include "is_function.hh"
#include "remove_cv.hh"
#include "remove_extent.hh"
#include "remove_reference.hh"

namespace std {

namespace __detail {
    template<typename _T, bool = is_array_v<_T> or is_function_v<_T>>
    struct __decay_helper : remove_cv<_T> {};

    template<typename _T>
    struct __decay_helper<_T, true> : add_pointer<remove_extent_t<_T>> {};
}

///decay - [meta.trans.other]
///Let U be remove_reference_t<_T>.
///If is_array_v<U>, then remove_extent_t<U>*.
///If is_function_v<U>, then add_pointer_t<U>.
///Otherwise, remove_cv_t<U>.
template<typename _T>
struct decay : __detail::__decay_helper<remove_reference_t<_T>> {};

template<typename _T>
using decay_t = typename decay<_T>::type;

}
