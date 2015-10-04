#pragma once

#include "false_type.hh"
#include "remove_cv.hh"
#include "true_type.hh"

namespace std {

namespace __detail {
    template<typename _T>
    struct __is_member_pointer_helper : false_type {};

    template<typename _Class, typename _Type>
    struct __is_member_pointer_helper<_Type _Class::*> : true_type {};
}

///is_member_pointer - [meta.unary.comp]
///True iff remove_cv_t<_T> is a pointer to non-static data member or non-static member function.
template<typename _T>
struct is_member_pointer : __detail::__is_member_pointer_helper<remove_cv_t<_T>> {};

template<typename _T>
constexpr auto is_member_pointer_v{is_member_pointer<_T>::value};

}
