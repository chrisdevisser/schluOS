#pragma once

#include <detail/type_traits/detail/is_referenceable.hh>

namespace std {

//Extension
template<typename _T>
concept bool Referenceable() {
    return __detail::__is_referenceable_v<_T>;
}

}
