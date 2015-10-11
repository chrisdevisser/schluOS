#pragma once

#include <detail/type_traits/add_rvalue_reference.hh>

namespace std {

///declval - [declval]
///Simplifies the definition of expressions which occur as unevaluated operands.
template<typename _T>
auto declval() noexcept -> add_rvalue_reference_t<_T>;

}
