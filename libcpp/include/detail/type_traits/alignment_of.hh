#pragma once

#include <detail/size_t.hh>

#include "integral_constant.hh"

namespace std {

///alignment_of - [meta.unary.prop.query]
///alignof(T)
template<typename _T>
struct alignment_of : integral_constant<size_t, alignof(_T)> {};

template<typename _T>
constexpr auto alignment_of_v{alignment_of<_T>::value};

}
