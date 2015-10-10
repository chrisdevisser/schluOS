#pragma once

#include "detail/any.hh"
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
struct is_scalar : __detail::__any<
    is_arithmetic_v<_T>,
    is_enum_v<_T>,
    is_pointer_v<_T>,
    is_member_object_pointer_v<_T>,
    is_member_function_pointer_v<_T>,
    is_null_pointer_v<_T>
> {};

template<typename _T>
constexpr auto is_scalar_v{is_scalar<_T>::value};

}
