#pragma once

#include "bool_constant.hh"
#include "is_constructible.hh"

namespace std {

///is_trivially_constructible - [meta.unary.prop]
///True iff is_constructible_v<_Type, _Args...> and this calls no
///non-trivial operation.
template<typename _Type, typename... _Args>
struct is_trivially_constructible : bool_constant<
    is_constructible_v<_Type, _Args...>
    and __is_trivially_constructible(_Type, _Args...)
> {};

template<typename _Type, typename... _Args>
constexpr auto is_trivially_constructible_v{is_trivially_constructible<_Type, _Args...>::value};

}
