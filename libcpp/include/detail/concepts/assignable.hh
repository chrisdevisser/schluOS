#pragma once

#include <detail/utility/forward.hh>

#include "same.hh"

namespace std {

///Assignable - [concepts.lib.corelang.assignable]
///Let t be an lvalue of type _Lhs. If _Rhs is an lvalue reference type,
///let v be an lvalue of type _Rhs; otherwise, let v be an rvalue
///of type _Rhs. Then Assignable<_Lhs, _Rhs>() is satisfied iff:
///- addressof(t = v) == addressof(t).
template<typename _Lhs, typename _Rhs = _Lhs>
concept bool Assignable() {
    return requires(_Lhs&& __lhs, _Rhs&& __rhs) {
        //{...} -> Same<_Lhs> is currently buggy in the compiler.
        Same<decltype(forward<_Lhs>(__lhs) = forward<_Rhs>(__rhs)), _Lhs&>();
    };
}

}
