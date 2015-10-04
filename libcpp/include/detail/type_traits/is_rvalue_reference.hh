#pragma once

#include "false_type.hh"
#include "true_type.hh"

namespace std {

///is_rvalue_reference - [meta.unary.cat]
///True iff _T is an rvalue reference per [dcl.ref].
template<typename _T>
struct is_rvalue_reference : false_type {};

template<typename _T>
struct is_rvalue_reference<_T&&> : true_type {};

template<typename _T>
constexpr auto is_rvalue_reference_v{is_rvalue_reference<_T>::value};

}
