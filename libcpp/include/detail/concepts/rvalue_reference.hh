#pragma once

#include <detail/type_traits/is_rvalue_reference.hh>

namespace std {

//Extension
template<typename _T>
concept bool RvalueReference() {
    return is_rvalue_reference_v<_T>;
}

}
