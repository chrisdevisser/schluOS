#pragma once

#include <detail/type_traits/is_signed.hh>

#include "integral.hh"

namespace std {

///Integral - [concepts.lib.corelang.integral]
template<typename _T>
concept bool SignedIntegral() {
    return Integral<_T> and is_signed_v<_T>;
}

}
