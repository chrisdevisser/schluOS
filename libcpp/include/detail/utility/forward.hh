#pragma once

#include <detail/concepts/lvalue_reference.hh>
#include <detail/concepts/referenceable.hh>
#include <detail/type_traits/remove_reference.hh>

namespace std {

///forward - [forward]
///Simplifies the implementation of forwarding functions.
Referenceable{_T}
constexpr auto forward(remove_reference_t<_T>& __t) noexcept -> _T&& {
    return static_cast<_T&&>(__t);
}

///If instantiated with an lvalue reference type, the program is ill-formed.
template<Referenceable _T> requires not LvalueReference<_T>()
constexpr auto forward(remove_reference_t<_T>&& __t) noexcept -> _T&& {
    return static_cast<_T&&>(__t);
}

}
