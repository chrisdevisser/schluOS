#pragma once

#include "add_const.hh"
#include "add_volatile.hh"

namespace std {

///add_cv - [meta.trans.cv]
///add_const_t<add_volatile_t<_T>>
template<typename _T>
struct add_cv : add_const<add_volatile_t<_T>> {};

template<typename _T>
using add_cv_t = typename add_cv<_T>::type;

}
