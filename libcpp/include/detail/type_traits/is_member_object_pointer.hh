#pragma once

#include "bool_constant.hh"
#include "is_member_pointer.hh"
#include "is_member_function_pointer.hh"
#include "remove_cv.hh"

namespace std {

///is_member_object_pointer - [meta.unary.cat]
///True iff remove_cv_t<_T> is a pointer to non-static data member.
template<typename _T>
struct is_member_object_pointer : bool_constant<is_member_pointer_v<remove_cv_t<_T>> and not is_member_function_pointer_v<_T>> {};

template<typename _T>
constexpr auto is_member_object_pointer_v{is_member_object_pointer<_T>::value};

}
