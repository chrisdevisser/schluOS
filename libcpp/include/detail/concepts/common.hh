#pragma once

#include <detail/type_traits/common_type.hh>
#include <detail/utility/forward.hh>

#include "same.hh"

namespace std {

///Common - [concepts.lib.corelang.common]
///If T and U can both be explicitly converted to some third type, C,
///then T and U share a common type, C.
///Let C be CommonType<T, U>. Let t1 and t2 be objects of type T,
///and u1 and u2 be objects of type U.
///Common<T, U>() is satisfied iff:
///- C(t1) equals C(t2) iff t1 equals t2.
///- C(u1) equals C(u2) iff u1 equals u2.
template<typename _T0, typename _T1>
using CommonType = common_type_t<_T0, _T1>;

template<typename _T0, typename _T1>
concept bool Common() {
    return requires(_T0 __t0, _T1 __t1) {
        typename CommonType<_T0, _T1>;
        typename CommonType<_T1, _T0>;
        requires Same<CommonType<_T0, _T1>, CommonType<_T1, _T0>>();

        CommonType<_T0, _T1>(forward<_T0>(__t0));
        CommonType<_T0, _T1>(forward<_T1>(__t1));
    };
}

}
