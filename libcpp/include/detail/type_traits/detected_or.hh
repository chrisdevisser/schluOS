#pragma once

#include "false_type.hh"
#include "nonesuch.hh"
#include "true_type.hh"
#include "void_t.hh"

//Library Fundamentals v2 TS.
//N4502: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4502.pdf

namespace std {

namespace __detail {
    template<typename _Default, typename /*should be void*/, template<typename...> typename _Op, typename... _Args>
    struct __detected_or_helper {
        using type = _Default;
        using value_t = false_type;
    };

    template<typename _Default, template<typename...> typename _Op, typename... _Args>
    struct __detected_or_helper<_Default, void_t<_Op<_Args...>>, _Op, _Args...> {
        using type = _Op<_Args...>;
        using value_t = true_type;
    };
}

//If _Op<_Args...> is valid, type is _Op<_Args...>, otherwise _Default.
//If _Op<_Args...> is valid, value_t is true_type, otherwise false_type.
template<typename _Default, template<typename...> typename _Op, typename... _Args>
using detected_or = __detail::__detected_or_helper<_Default, void, _Op, _Args...>;

template<typename _Default, template<typename...> typename _Op, typename... _Args>
using detected_or_t = typename detected_or<_Default, _Op, _Args...>::type;

}
