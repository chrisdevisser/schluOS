#pragma once

#include <detail/utility/declval.hh>

#include "bool_constant.hh"
#include "is_constructible.hh"

namespace std {

///is_nothrow_constructible - [meta.unary.prop]
///True iff is_constructible_v<_Type, _Args...> and this doesn't
///throw any exceptions.
template<typename _Type, typename... _Args>
struct is_nothrow_constructible : bool_constant<
    is_constructible_v<_Type, _Args...>
    and noexcept(_Type(declval<_Args>()...))
> {};

template<typename _Type, typename... _Args>
constexpr auto is_nothrow_constructible_v{is_nothrow_constructible<_Type, _Args...>::value};

}
