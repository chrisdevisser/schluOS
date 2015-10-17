#pragma once

#include <detail/type_traits/is_lvalue_reference.hh>

namespace std {

//Extension
template<typename _T>
concept bool LvalueReference() {
    return is_lvalue_reference_v<_T>;
}

}
