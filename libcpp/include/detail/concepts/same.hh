#pragma once

#include <detail/type_traits/is_same.hh>

namespace std {

///Same - [concepts.lib.corelang.same]
///Satisfied iff _T0 and _T1 are the same type.
///Implies Same<_T1, _T0>().
template<typename _T0, typename _T1>
concept bool Same() {
    return is_same_v<_T0, _T1>;
}

}
