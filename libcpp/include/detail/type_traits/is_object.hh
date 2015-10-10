#pragma once

#include "detail/all.hh"
#include "is_function.hh"
#include "is_reference.hh"
#include "is_void.hh"

namespace std {

///is_object - [meta.unary.comp]
///True if remove_cv_t<_T> is an object type per [basic.types].
template<typename _T>
struct is_object : __detail::__all<
    not is_function_v<_T>,
    not is_reference_v<_T>,
    not is_void_v<_T>
> {};

template<typename _T>
constexpr auto is_object_v{is_object<_T>::value};

}
