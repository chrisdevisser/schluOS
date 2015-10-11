#pragma once

#include <detail/declval.hh>

#include "false_type.hh"
#include "is_detected.hh"
#include "is_reference.hh"
#include "remove_all_extents.hh"

namespace std {

namespace __detail {
    template<typename _T>
    using __destruct_test =
        decltype(declval<remove_all_extents_t<_T>&>().~remove_all_extents_t<_T>());

    template<typename _T, bool = is_reference_v<_T>>
    struct __is_destructible_helper : true_type {};

    template<typename _T>
    struct __is_destructible_helper<_T, false>
        : is_detected<__detail::__destruct_test, _T> {};
}

///is_destructible - [meta.unary.prop]
///For reference types, true.
///For incomplete types and function types, false.
///For object types where U = remove_all_extents_t<_T>,
///true iff declval<U&>().~U() is well-formed when treated as an unevaluated operand.
template<typename _T>
struct is_destructible : __detail::__is_destructible_helper<_T> {};

template<typename _T>
constexpr auto is_destructible_v{is_destructible<_T>::value};

}
