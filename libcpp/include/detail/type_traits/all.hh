#pragma once

#include "bool_constant.hh"

namespace std {

namespace __detail {
    //This exists because GCC currently doesn't support the fold expression
    //being a direct template argument.
    template<bool... Bs>
    constexpr auto __all_helper() {
        return (Bs and ...);
    }

    ///True iff any of the given arguments are true.
    ///True if no arguments are given.
    template<bool... _Bs>
    struct __all : std::bool_constant<__all_helper<_Bs...>()> {};

    template<bool... _Bs>
    constexpr auto __all_v{__all<_Bs...>::value};
}

}
