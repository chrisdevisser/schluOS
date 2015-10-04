#pragma once

#include "is_referenceable.hh"

namespace std {

namespace __detail {
    template<typename _T, bool = __detail::__is_referenceable_v<_T>>
    struct __add_rvalue_reference_helper {
        using type = _T;
    };

    template<typename _T>
    struct __add_rvalue_reference {
        using type = _T&&;
    };
}

///add_rvalue_reference - [meta.trans.ref]
///If _T is an object or function type, then _T&&, otherwise _T.
template<typename _T>
struct add_rvalue_reference : __detail::__add_rvalue_reference_helper<_T> {};

}
