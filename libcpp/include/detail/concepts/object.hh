#pragma once

#include <detail/type_traits/is_object.hh>

namespace std {

//Extension
template<typename _T>
concept bool Object() {
    return is_object_v<_T>;
}

}
