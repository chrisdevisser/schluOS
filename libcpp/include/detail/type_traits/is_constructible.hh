#pragma once

#include <detail/utility/declval.hh>

#include "detail/all.hh"
#include "detail/is_array_of_known_bound.hh"
#include "detail/is_array_of_unknown_bound.hh"
#include "bool_constant.hh"
#include "is_base_of.hh"
#include "is_detected.hh"
#include "is_function.hh"
#include "is_lvalue_reference.hh"
#include "is_rvalue_reference.hh"
#include "remove_all_extents.hh"
#include "remove_cv.hh"
#include "remove_reference.hh"

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

    //Detect T&& from U& so we can disallow it.
    template<typename _Type, typename... _Args>
    constexpr auto __is_constructing_invalid_rref_from_lref{
        sizeof...(_Args) == 1
        and is_rvalue_reference_v<_Type>
        and __detail::__all_v<is_lvalue_reference_v<_Args>...>
        and not is_function_v<remove_reference_t<_Type>>
    };

    //Detect forms of Derived from Base so we can disallow them.
    template<typename _Type, typename... _Args>
    constexpr auto __is_constructing_derived_from_base{
        sizeof...(_Args) == 1
        and __detail::__all_v<
            is_base_of_v<
                remove_cv_t<remove_reference_t<_Args>>,
                remove_cv_t<remove_reference_t<_Type>>
            >...
        >
    };

    //Checks for void since void() is a valid expression, but not constructible.
    //In addition, performs the test on _Type and combines that with workarounds.
    template<typename _Type, typename... _Args>
    struct __is_constructible_helper : bool_constant<
        not is_void_v<_Type>
        and not __is_constructing_invalid_rref_from_lref<_Type, _Args...>
        and not __is_constructing_derived_from_base<_Type, _Args...>
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
