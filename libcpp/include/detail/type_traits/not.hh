#pragma once

#include "bool_constant.hh"

namespace std {

namespace __detail {
    template<bool _B>
    struct __not : bool_constant<not _B> {};

    template<bool _B>
    constexpr auto __not_v{__not<_B>::value};
}

}
