#pragma once

#include "false_type.hh"
#include "true_type.hh"

namespace std {

///is_lvalue_reference - [meta.unary.cat]
///True iff _T is an lvalue reference per [dcl.ref].
template<typename _T>
struct is_lvalue_reference : false_type {};

template<typename _T>
struct is_lvalue_reference<_T&> : true_type {};

template<typename _T>
constexpr auto is_lvalue_reference_v{is_lvalue_reference<_T>::value};

}
