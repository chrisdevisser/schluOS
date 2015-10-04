#pragma once

#include "false_type.hh"
#include "true_type.hh"

namespace std {

///is_const - [meta.unary.prop]
///True iff _T is const-qualified per [basic.type.qualifier].
template<typename _T>
struct is_const : false_type {};

template<typename _T>
struct is_const<const _T> : true_type {};

template<typename _T>
constexpr auto is_const_v{is_const<_T>::value};

}
