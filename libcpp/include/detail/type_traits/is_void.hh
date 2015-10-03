#pragma once

#include "is_same.hh"
#include "remove_cv.hh"

namespace std {

///is_void - [meta.unary.cat]
///True iff remove_cv<_T> is void.
template<typename _T>
struct is_void : is_same<remove_cv_t<_T>, void> {};

template<typename _T>
constexpr auto is_void_v{is_void<_T>{}};

}
