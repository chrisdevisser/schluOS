#pragma once

#include <detail/type_traits/is_reference.hh>

namespace std {

//Extension
template<typename _T>
concept bool Reference() {
    return is_reference_v<_T>;
}

}
