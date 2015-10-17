#pragma once

#include <detail/utility/forward.hh>

#include "same.hh"

namespace std {

///Assignable - [concepts.lib.corelang.assignable]
///Let t be an lvalue of type _T0. If _T1 is an lvalue reference type,
///let v be an lvalue of type _T1; otherwise, let v be an rvalue
///of type _T1. Then Assignable<_T0, _T1>() is satisfied iff:
///- addressof(t = v) == addressof(t).
template<typename _T0, typename _T1 = _T0>
concept bool Assignable() {
    return requires(_T0&& __t0, _T1&& __t1) {
        {forward<_T0>(__t0) = forward<_T1>(__t1)} -> Same<_T0&>;
    };
}

}
