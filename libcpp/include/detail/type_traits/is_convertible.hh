#pragma once

#include <detail/declval.hh>

#include "false_type.hh"
#include "is_array.hh"
#include "is_function.hh"
#include "is_void.hh"
#include "true_type.hh"
#include "void_t.hh"

namespace std {

namespace __detail {
    template<typename _To>
    auto __is_convertible_test(_To) -> void;

    //General case: _From is void or _To is an array or function
    template<
        typename _From,
        typename _To,
        typename = void_t<>,
        bool = is_void_v<_From> or is_array_v<_To> or is_function_v<_To> //allow calls with these types
    > struct __is_convertible_helper : is_same<_To, void> {}; //but none can be the result of a conversion except void->void

    //_From is not void and _To is not an array or function
    //The conversion test fails (because of the general nature of _Void)
    template<typename _From, typename _To, typename _Void>
    struct __is_convertible_helper<
        _From,
        _To,
        _Void,
        false
    > : std::false_type {};

    //_From is not void and _To is not an array or function
    //The conversion test succeeds
    template<typename _From, typename _To>
    struct __is_convertible_helper<
        _From,
        _To,
        void_t<decltype(__is_convertible_test<_To>(declval<_From>()))>,
        false
    > : true_type {};
}

///is_convertible - [meta.rel]
///True iff the return expression in the following code would be
///well-formed, including implicit conversions to the return type.
///_To test() {return declval<_From>();}
template<typename _From, typename _To>
struct is_convertible : __detail::__is_convertible_helper<_From, _To> {};

template<typename _From, typename _To>
constexpr auto is_convertible_v{is_convertible<_From, _To>::value};

}
