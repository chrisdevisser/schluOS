#pragma once

#include "bool_constant.hh"

namespace std {

///has_virtual_destructor - [meta.unary.prop]
///True iff _T has a virtual destructor.
template<typename _T>
struct has_virtual_destructor : bool_constant<
    __has_virtual_destructor(_T)
> {};

template<typename _T>
constexpr auto has_virtual_destructor_v{has_virtual_destructor<_T>::value};

}
