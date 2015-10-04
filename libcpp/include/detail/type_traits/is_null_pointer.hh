#pragma once

#include <cstddef>

#include "is_same.hh"
#include "remove_cv.hh"

namespace std {

///is_null_pointer - [meta.unary.cat]
///True iff remove_cv_t<_T> is nullptr_t.
template<typename _T>
struct is_null_pointer : is_same<remove_cv_t<_T>, nullptr_t> {};

template<typename _T>
constexpr auto is_null_pointer_v{is_null_pointer<_T>::value};

}
