#pragma once

#include "detail/not.hh"
#include "is_fundamental.hh"

namespace std {

///is_compound - [meta.unary.comp]
///True iff remove_cv_t<_T> is a compound type per [basic.compound].
template<typename _T>
struct is_compound : __detail::__not<is_fundamental_v<_T>> {};

template<typename _T>
constexpr auto is_compound_v{is_compound<_T>::value};

}
