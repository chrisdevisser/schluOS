#pragma once

#include <detail/concepts/movable.hh>
#include <detail/odr_value.hh>
#include <detail/type_traits/is_nothrow_destructible.hh>
#include <detail/type_traits/is_nothrow_move_assignable.hh>
#include <detail/type_traits/is_nothrow_move_constructible.hh>

#include "forward.hh"
#include "move.hh"

namespace std {

//Eric Niebler's customization point design.
namespace __detail {
    template<typename _T>
    constexpr bool __swap_noexcept{
        is_nothrow_destructible_v<_T>
        and is_nothrow_move_assignable_v<_T>
        and is_nothrow_move_constructible_v<_T>
    };

    ///swap - [utility.swap]
    ///Exchanges values stored in two locations.
    Movable{_T}
    auto swap(_T& __lhs, _T& __rhs) noexcept(__swap_noexcept<_T>) {
        auto&& __temp = move(__lhs);
        __lhs = move(__rhs);
        __rhs = move(__temp);
    }

    struct __swap_functor {
        Movable{_T}
        constexpr auto operator()(_T&& __lhs, _T&& __rhs) const noexcept(__swap_noexcept<_T>) {
            return swap(forward<_T>(__lhs), forward<_T>(__rhs));
        }
    };
}

namespace {
    constexpr const auto&swap{__detail::__odr_value<__detail::__swap_functor>};
}

}
