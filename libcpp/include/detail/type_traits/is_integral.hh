#pragma once

#include "is_contained_in.hh"
#include "remove_cv.hh"

namespace std {

///is_integral - [meta.unary.cat]
///True iff remove_cv_t<_T> is an integral type per [basic.fundamental]/2-7.
template<typename _T>
struct is_integral : __detail::__is_contained_in<
    remove_cv_t<_T>,

    bool, char, char16_t, char32_t, wchar_t,
    signed char, unsigned char,
    short, unsigned short,
    int, unsigned,
    long, unsigned long,
    long long, unsigned long long
> {};

template<typename _T>
constexpr auto is_integral_v{is_integral<_T>::value};

}
