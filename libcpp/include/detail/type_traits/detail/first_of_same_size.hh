#pragma once

#include "../conditional.hh"

namespace std {

namespace __detail {
    struct __no_match {};

    //Finds the first type in _TypesToTry with the same size as _T.
    template<typename _T, typename... _TypesToTry>
    struct __first_of_same_size;

    template<typename _T, typename _TypeToTry>
    struct __first_of_same_size<_T, _TypeToTry> {

        using type = conditional_t<
            sizeof(_T) == sizeof(_TypeToTry),
            _TypeToTry,
            __no_match
        >;
    };

    template<typename _T, typename _FirstTypeToTry, typename... _OtherTypesToTry>
    struct __first_of_same_size<_T, _FirstTypeToTry, _OtherTypesToTry...> {
        using type = conditional_t<
            sizeof(_T) == sizeof(_FirstTypeToTry),
            _FirstTypeToTry,
            typename __first_of_same_size<_T, _OtherTypesToTry...>::type
        >;
    };

    template<typename _T, typename... _TypesToTry>
    using __first_of_same_size_t = __first_of_same_size<_T, _TypesToTry...>;
}

}
