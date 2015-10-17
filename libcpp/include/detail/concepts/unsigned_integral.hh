#pragma once

#include "integral.hh"
#include "signed_integral.hh"

namespace std {

///UnsignedIntegral - [concepts.lib.corelang.unsignedintegral]
template<typename _T>
concept bool UnsignedIntegral() {
    return Integral<_T> and !SignedIntegral<_T>;
}

}
