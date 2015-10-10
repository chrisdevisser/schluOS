#pragma once

#include "detail/is_contained_in.hh"
#include "remove_cv.hh"

namespace std {

///is_floating_point - [meta.unary.cat]
///True iff remove_cv_t<_T> is a floating-point type per [basic.fundamental]/8.
template<typename _T>
struct is_floating_point : __detail::__is_contained_in<
    remove_cv_t<_T>,
    float, double, long double
> {};

template<typename _T>
constexpr auto is_floating_point_v{is_floating_point<_T>::value};

}
