#pragma once

#include "bool_constant.hh"

namespace std {

///is_base_of - [meta.rel]
///True iff _Base is a base class of _Derived without regard to cv-qualifiers
///or _Base and _Derived are not unions and name the same type without regard to cv-quaifiers.
template<typename _Base, typename _Derived>
struct is_base_of : bool_constant<__is_base_of(_Base, _Derived)> {};

template<typename _Base, typename _Derived>
constexpr auto is_base_of_v{is_base_of<_Base, _Derived>::value};

}
