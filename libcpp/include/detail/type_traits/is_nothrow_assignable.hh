#pragma once

#include <detail/utility/declval.hh>

#include "bool_constant.hh"
#include "false_type.hh"
#include "is_assignable.hh"

namespace std {

namespace __detail {
    template<typename _Lhs, typename _Rhs, bool = is_assignable_v<_Lhs, _Rhs>>
    struct __is_nothrow_assignable_helper : false_type {};

    template<typename _Lhs, typename _Rhs>
    struct __is_nothrow_assignable_helper<_Lhs, _Rhs, true>  : bool_constant<
        noexcept(declval<_Lhs>() = declval<_Rhs>())
    > {};
}

///is_nothrow_assignable - [meta.unary.prop]
///True iff is_assignable_v<_Lhs, _Rhs> is true and this
///is known not to throw any exceptions.
template<typename _Lhs, typename _Rhs>
struct is_nothrow_assignable : __detail::__is_nothrow_assignable_helper<_Lhs, _Rhs> {};

template<typename _Lhs, typename _Rhs>
constexpr auto is_nothrow_assignable_v{is_nothrow_assignable<_Lhs, _Rhs>::value};

}
