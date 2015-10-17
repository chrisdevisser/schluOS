#pragma once

#include <detail/type_traits/is_signed.hh>

#include "integral.hh"

namespace std {

///SignedIntegral - [concepts.lib.corelang.signedintegral]
template<typename _T>
concept bool SignedIntegral() {
    return Integral<_T> and is_signed_v<_T>;
}

}
