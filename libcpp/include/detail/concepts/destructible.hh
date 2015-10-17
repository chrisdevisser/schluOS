#pragma once

#include "same.hh"

namespace std {

///Destructible - [concepts.lib.object.destructible]
///Describes properties that all object concept types have in common.
///Given a (possibly const) lvalue t of type T and pointer p of type T*,
///Destructible<T>() is satisfied iff:
///- After evaluating t.~T(), delete p, or delete[] p, all owned resources are reclaimed.
///- &t == addressof(t).
///- &t is non-modifying.
template<typename _T>
concept bool Destructible() {
    return requires(_T __t, const _T __ct, _T* __p) {
        {__t.~_T()} noexcept;

        {&__t} -> Same<_T*>;
        {&__ct} -> Same<const _T*>;

        delete __p;
        delete[] __p;
    };
}

}
