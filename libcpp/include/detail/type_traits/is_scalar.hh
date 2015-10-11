#pragma once

#include "bool_constant.hh"
#include "is_arithmetic.hh"
#include "is_enum.hh"
#include "is_member_function_pointer.hh"
#include "is_member_object_pointer.hh"
#include "is_null_pointer.hh"
#include "is_pointer.hh"

namespace std {

///is_scalar - [meta.unary.comp]
///True iff remove_cv_t<_T> is a scalar type per [basic.types].
template<typename _T>
struct is_scalar : bool_constant<
    is_arithmetic_v<_T>
    or is_enum_v<_T>
    or is_pointer_v<_T>
    or is_member_object_pointer_v<_T>
    or is_member_function_pointer_v<_T>
    or is_null_pointer_v<_T>
> {};

template<typename _T>
constexpr auto is_scalar_v{is_scalar<_T>::value};

}
