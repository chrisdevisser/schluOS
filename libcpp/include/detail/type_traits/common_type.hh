#pragma once

#include <detail/utility/declval.hh>

#include "decay.hh"
#include "void_t.hh"

#define __cpp_lib_common_type_sfinae 201401

namespace std {

namespace __detail {
    //based on Walter Brown's SFINAE proposal
    //http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3843.pdf

    template<typename _T0, typename _T1>
    using __common_type_test = decltype(declval<bool>() ? declval<_T0>() : declval<_T1>());

    template<typename... _Ts>
    struct __common_type_helper {};

    template<typename _T>
    struct __common_type_helper<void, _T> {
        using type = decay_t<_T>;
    };

    template<typename _Head0, typename _Head1, typename... _Tail>
    struct __common_type_helper<void_t<__common_type_test<_Head0, _Head1>>, _Head0, _Head1, _Tail...>
        : __common_type_helper<void, __common_type_test<_Head0, _Head1>, _Tail...> {}
    ;
}

///common_type - [meta.trans.other]
///If sizeof...(_Ts) == 0, no member type.
///If sizeof...(_Ts) == 1, decay_t<T0>, where T0 is the only type in _Ts.
///Otherwise, let T1, T2, and R be the first, second, and remaining
///types in _Ts. Let C be the type, if any, of a conditional expression
///of some bool, an xvalue of type T1, and an xvalue of type T2.
///If C exists, common_type_t<C, R...>. Otherwise, no member type.
template<typename... _Ts>
struct common_type : __detail::__common_type_helper<void, _Ts...> {};

template<typename... _Ts>
using common_type_t = typename common_type<_Ts...>::type;

}
