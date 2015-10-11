#pragma once

#include <detail/utility/declval.hh>

#include "bool_constant.hh"
#include "false_type.hh"
#include "is_destructible.hh"
#include "remove_reference.hh"

namespace std {

namespace __detail {
    template<typename _T, bool = is_destructible_v<_T>>
    struct __is_nothrow_destructible_helper : false_type {};

    template<typename _T>
    struct __is_nothrow_destructible_helper<_T, true>  : bool_constant<
        noexcept(declval<remove_all_extents_t<_T>>().~remove_all_extents_t<_T>())
    > {};
}

///is_nothrow_destructible - [meta.unary.prop]
///True iff is_destructible_v<_T> is true and this is known not to
///throw any exceptions.
template<typename _T>
struct is_nothrow_destructible : __detail::__is_nothrow_destructible_helper<_T> {};

template<typename _T>
constexpr auto is_nothrow_destructible_v{is_nothrow_destructible<_T>::value};

}
