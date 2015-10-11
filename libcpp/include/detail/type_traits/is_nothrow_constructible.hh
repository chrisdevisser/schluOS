#pragma once

#include <detail/utility/declval.hh>

#include "bool_constant.hh"
#include "false_type.hh"
#include "is_constructible.hh"

namespace std {

namespace __detail {
    template<typename _Type, typename... _Args>
    struct __is_nothrow_constructible_helper {
        //Since we can't have both a defaulted bool and variadic _Args,
        //we move the bool trick to an inner struct.
        //The dummy parameter prevents an explicit specialization.
        template<bool _Dummy = true, bool = is_constructible_v<_Type, _Args...>>
        struct __is_nothrow_constructible_helper2 : false_type {};

        template<bool _Dummy>
        struct __is_nothrow_constructible_helper2<_Dummy, true> : bool_constant<
            noexcept(_Type(declval<_Args>()...))
        > {};

        static constexpr auto value{__is_nothrow_constructible_helper2<>::value};
    };
}

///is_nothrow_constructible - [meta.unary.prop]
///True iff is_constructible_v<_Type, _Args...> and this doesn't
///throw any exceptions.
template<typename _Type, typename... _Args>
struct is_nothrow_constructible : __detail::__is_nothrow_constructible_helper<_Type, _Args...> {};

template<typename _Type, typename... _Args>
constexpr auto is_nothrow_constructible_v{is_nothrow_constructible<_Type, _Args...>::value};

}
