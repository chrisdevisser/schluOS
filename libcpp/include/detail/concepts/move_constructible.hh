#pragma once

#include <detail/type_traits/remove_cv.hh>

#include "constructible.hh"

namespace std {

///MoveConstructible - [concepts.lib.object.moveconstructible]
///Let rv be an rvalue of type remove_cv_t<_T>. Then MoveConstructible<_T>()
///is satisfied iff:
///- After _T u = rv;, u is equal to the value of rv before the construction.
///- _T{rv} or *new _T{rv} is equal to the value of rv before the construction.
///rv's resulting state is unspecified.
template<typename _T>
concept bool MoveConstructible() {
    return Constructible<_T, remove_cv_t<_T>&&>() and Constructible<remove_cv_t<_T>&&, _T>();
}

}
