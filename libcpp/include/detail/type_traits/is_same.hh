#pragma once

#include "false_type.hh"
#include "true_type.hh"

namespace std {

///is_same - [meta.rel]
///_Lhs and _Rhs name the same type with the same cv-qualifications.
template<typename _Lhs, typename _Rhs>
struct is_same : false_type {};

template<typename _T>
struct is_same<_T, _T> : true_type {};

template<typename _Lhs, typename _Rhs>
constexpr auto is_same_v{is_same<_Lhs, _Rhs>::value};

}
