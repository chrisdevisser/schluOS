#pragma once

#include <detail/size_t.hh>
#include <cstdint>

#include "detail/transfer_cv.hh"
#include "detail/first_of_same_size.hh"
#include "conditional.hh"
#include "is_enum.hh"
#include "is_same.hh"
#include "remove_cv.hh"
#include "underlying_type.hh"

namespace std {

namespace __detail {
    //Note that only enums and integral types other than bool are allowed.

    //Handle signed types and enums.
    template<typename _T>
    struct __make_signed_helper {
        using __enum_test = __first_of_same_size<
            underlying_type_t<_T>,
            signed char, short, int, long, long long
        >;

        using type = conditional_t<
            is_enum_v<_T>,
            typename __enum_test::type,
            _T
        >;

        static_assert(
            not is_same_v<type, __no_match>,
            "(make_signed): Could not find suitable replacement for underlying enum type."
        );
    };

    template<> struct __make_signed_helper<char> {using type = signed char;};
    template<> struct __make_signed_helper<unsigned char> {using type = signed char;};
    template<> struct __make_signed_helper<char16_t> {using type = int16_t;};
    template<> struct __make_signed_helper<char32_t> {using type = int32_t;};
    template<> struct __make_signed_helper<wchar_t> {using type = signed __WCHAR_TYPE__;};
    template<> struct __make_signed_helper<unsigned short> {using type = short;};
    template<> struct __make_signed_helper<unsigned> {using type = int;};
    template<> struct __make_signed_helper<unsigned long> {using type = long;};
    template<> struct __make_signed_helper<unsigned long long> {using type = long long;};
}

///make_signed - [meta.trans.sign]
///If _T is a possibly cv-qualified signed integer type, _T.
///If _T is a possibly cv-qualified unsigned integer type, the corresponding signed integer type.
///Otherwise, the signed integer type with smallest rank for which
///sizeof(_T) == sizeof(type), with the same cv as _T.
template<typename _T>
struct make_signed : __detail::__transfer_cv<
    _T,
    typename __detail::__make_signed_helper<_T>::type
> {};

template<typename _T>
using make_signed_t = typename make_signed<_T>::type;

}
