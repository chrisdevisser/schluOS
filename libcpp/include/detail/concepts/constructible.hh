#pragma once

#include <detail/utility/forward.hh>

#include "destructible.hh"
#include "reference.hh"

namespace std {

namespace __detail {
    template<typename _Type, typename... _Args>
    concept bool _ConstructibleObject = requires(_Args&&... __args) {
        requires Destructible<_Type>();
        _Type{forward<_Args>(__args)...};
        new _Type{forward<_Args>(__args)...};
    };

    template<typename _Type, typename... _Args>
    concept bool _BindableReference = requires(_Args&&... __args) {
        requires Reference<_Type>();
        _Type(forward<_Args>(__args)...);
    };
}

///Constructible - [concepts.lib.object.constructible]
///Used to constrain the type of a variable to be either an object type
///constructible from a given set of argument types, or a reference type
///that can be bound to those arguments.
template<typename _Type, typename... _Args>
concept bool Constructible() {
    return __detail::_ConstructibleObject<_Type, _Args...> or __detail::_BindableReference<_Type, _Args...>;
}

}
