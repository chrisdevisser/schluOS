#pragma once

#include "bool_constant.hh"
#include "is_function.hh"
#include "is_reference.hh"
#include "is_void.hh"

namespace std {

///is_object - [meta.unary.comp]
///True if remove_cv_t<_T> is an object type per [basic.types].
template<typename _T>
struct is_object : bool_constant<
    not is_function_v<_T>
    and not is_reference_v<_T>
    and not is_void_v<_T>
> {};

template<typename _T>
constexpr auto is_object_v{is_object<_T>::value};

}
