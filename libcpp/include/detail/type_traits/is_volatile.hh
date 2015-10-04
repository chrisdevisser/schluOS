#pragma once

#include "false_type.hh"
#include "true_type.hh"

namespace std {

///is_volatile - [meta.unary.prop]
///True iff _T is volatile-qualified per [basic.type.qualifier].
template<typename _T>
struct is_volatile : false_type {};

template<typename _T>
struct is_volatile<volatile _T> : true_type {};

template<typename _T>
constexpr auto is_volatile_v{is_volatile<_T>::value};

}
