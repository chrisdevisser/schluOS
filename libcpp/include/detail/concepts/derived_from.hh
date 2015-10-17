#pragma once

#include <detail/type_traits/is_base_of.hh>

namespace std {

///DerivedFrom - [concepts.lib.corelang.derived]
///True iff is_base_of_v<_Base, _Derived> is true.
template<typename _Derived, typename _Base>
concept bool DerivedFrom() {
    return is_base_of_v<_Base, _Derived>;
}

}
