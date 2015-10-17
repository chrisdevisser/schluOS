#pragma once

#include <detail/type_traits/remove_cv.hh>

#include "constructible.hh"
#include "convertible_to.hh"
#include "move_constructible.hh"

namespace std {

///CopyConstructible - [concepts.lib.object.copyconstructible]
///Let v be an lvalue of type (possibly const) remove_cv_t<_T> or
///an rvalue of type const remove_cv_t<_T>. Then CopyConstructible<_T>()
///is satisfied iff:
///- After _T u = v;, v is equal to u.
///- _T{v} or *new _T{v} is equal to v is unchanged.
template<typename _T>
concept bool CopyConstructible() {
    return
        MoveConstructible<_T>
        and Constructible<_T, const remove_cv_t<_T>&>()
        and ConvertibleTo<remove_cv_t<_T>&, _T>()
        and ConvertibleTo<const remove_cv_t<_T>&, _T>()
        and ConvertibleTo<const remove_cv_t<_T>&&, _T>()
    ;
}

}
