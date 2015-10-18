#pragma once

#include <detail/concepts/referenceable.hh>
#include <detail/type_traits/remove_reference.hh>

namespace std {

///move - [forward]
///Simplifies applying move semantics to an lvalue.
Referenceable{_T}
constexpr decltype(auto) move(_T&& __t) noexcept {
    return static_cast<remove_reference_t<_T>&&>(__t);
}

}
