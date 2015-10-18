#pragma once

#include "assignable.hh"
#include "move_constructible.hh"

#include <type_traits>

namespace std {

///Movable - [concepts.lib.object.movable]
///Let rv be an rvalue of type _T and let t be an lvalue of type _T.
///The Movable<_T>() is satisfied iff:
///- After the assignment t = rv, t is equal to the value of rv before the assignment.
///rv's resulting state is unspecified.
template<typename _T>
concept bool Movable() {
    return MoveConstructible<_T>() and Assignable<_T&, _T&&>();
}

}
