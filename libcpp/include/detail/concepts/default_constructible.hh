#pragma once

#include <detail/size_t.hh>

#include "constructible.hh"

namespace std {

///DefaultConstructible - [concepts.lib.object.defaultconstructible]
template<typename _T>
concept bool DefaultConstructible() {
    return requires(const size_t __n) {
        requires Constructible<_T>;
        new _T[__n]{}; ///prohibits explicit default constructors
    };
}

}
