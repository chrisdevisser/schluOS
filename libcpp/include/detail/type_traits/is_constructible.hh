#pragma once

#include <detail/utility/declval.hh>

#include "detail/is_array_of_known_bound.hh"
#include "detail/is_array_of_unknown_bound.hh"
#include "bool_constant.hh"
#include "is_detected.hh"
#include "remove_all_extents.hh"

namespace std {

namespace __detail {
    template<typename _Type, typename... _Args>
    using __construct_test = decltype(_Type(declval<_Args>()...));

    //If T[N], test T.
    //This works around T() not being valid for T being an array of known bound.
    template< typename _Type, typename... _Args>
    constexpr auto __is_default_constructing_valid_array{
        sizeof...(_Args) == 0
        and __is_array_of_known_bound_v<_Type>
        and is_detected_v<__construct_test, remove_all_extents_t<_Type>>
    };

    //Checks for void since void() is a valid expression, but not constructible.
    //In addition, performs the test on _Type and combines that with a workaround for _Type=T[N].
    template<typename _Type, typename... _Args>
    struct __is_constructible_helper : bool_constant<
        not is_void_v<_Type>
        and (
            is_detected_v<__construct_test, _Type, _Args...> //main check
            or __is_default_constructing_valid_array<_Type, _Args...> //T[N] check
        )
    > {};
}

///is_constructible - [meta.unary.prop]
///True iff _Type t(declval<_Args>()...) would be well-formed.
template<typename _Type, typename... _Args>
struct is_constructible : __detail::__is_constructible_helper<_Type, _Args...> {};

template<typename _Type, typename... _Args>
constexpr auto is_constructible_v{is_constructible<_Type, _Args...>::value};

}
