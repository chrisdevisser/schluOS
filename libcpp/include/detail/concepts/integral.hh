#pragma once

#include <detail/type_traits/is_integral.hh>

namespace std {

///Integral - [concepts.lib.corelang.integral]
template<typename _T>
concept bool Integral() {
    return is_integral_v<_T>;
}

}
