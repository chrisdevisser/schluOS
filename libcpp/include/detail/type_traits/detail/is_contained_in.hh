#pragma once

#include "../is_same.hh"
#include "any.hh"

namespace std {

namespace __detail {
    //True iff at least one type in _List is _T.
    //TODO: replace __any with fold expression when supported.
    template<typename _T, typename... _List>
    struct __is_contained_in : __any<is_same_v<_T, _List>...> {};

    template<typename _T, typename... _List>
    constexpr auto __is_contained_in_v{__is_contained_in<_T, _List...>::value};
}

}
