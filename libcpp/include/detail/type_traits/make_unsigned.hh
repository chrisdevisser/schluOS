#pragma once

#include <cstdint>

#include "detail/first_of_same_size.hh"
#include "detail/transfer_cv.hh"
#include "conditional.hh"
#include "is_enum.hh"
#include "is_same.hh"
#include "remove_cv.hh"
#include "underlying_type.hh"

namespace std {

namespace __detail {
    //Note that only enums and integral types other than bool are allowed.

    //Handle unsigned types and enums.
    template<typename _T>
    struct __make_unsigned_helper {
        using __enum_test = __first_of_same_size<
            underlying_type_t<_T>,
            unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long
        >;

        using type = conditional_t<
            is_enum_v<_T>,
            typename __enum_test::type,
            _T
        >;

        static_assert(
            not is_same_v<type, __no_match>,
            "(make_unsigned): Could not find suitable replacement for underlying enum type."
        );
    };

    template<> struct __make_unsigned_helper<char> {using type = unsigned char;};
    template<> struct __make_unsigned_helper<signed char> {using type = unsigned char;};
    template<> struct __make_unsigned_helper<char16_t> {using type = uint16_t;};
    template<> struct __make_unsigned_helper<char32_t> {using type = uint32_t;};
    template<> struct __make_unsigned_helper<wchar_t> {using type = unsigned __WCHAR_TYPE__;};
    template<> struct __make_unsigned_helper<short> {using type = unsigned short;};
    template<> struct __make_unsigned_helper<int> {using type = unsigned int;};
    template<> struct __make_unsigned_helper<long> {using type = unsigned long;};
    template<> struct __make_unsigned_helper<long long> {using type = unsigned long long;};
}

///make_unsigned - [meta.trans.sign]
///If _T is a possibly cv-qualified unsigned integer type, _T.
///If _T is a possibly cv-qualified signed integer type, the corresponding unsigned integer type.
///Otherwise, the unsigned integer type with smallest rank for which
///sizeof(_T) == sizeof(type), with the same cv as _T.
template<typename _T>
struct make_unsigned : __detail::__transfer_cv<
    _T,
    typename __detail::__make_unsigned_helper<_T>::type
> {};

template<typename _T>
using make_unsigned_t = typename make_unsigned<_T>::type;

}
