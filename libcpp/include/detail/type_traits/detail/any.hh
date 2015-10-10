#pragma once

#include "../bool_constant.hh"

namespace std {

namespace __detail {
    //This exists because GCC currently doesn't support the fold expression
    //being a direct template argument.
    template<bool... Bs>
    constexpr auto __any_helper() {
        return (Bs or ...);
    }

    ///True iff any of the given arguments are true.
    ///False if no arguments are given.
    template<bool... _Bs>
    struct __any : std::bool_constant<__any_helper<_Bs...>()> {};

    template<bool... _Bs>
    constexpr auto __any_v{__any<_Bs...>::value};
}

}
