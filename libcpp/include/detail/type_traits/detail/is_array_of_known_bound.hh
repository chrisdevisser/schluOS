#pragma once

#include <detail/size_t.hh>

#include "../false_type.hh"
#include "../true_type.hh"

namespace std {

namespace __detail {
    template<typename _T>
    struct __is_array_of_known_bound : false_type {};

    template<typename _T, size_t _N>
    struct __is_array_of_known_bound<_T[_N]> : true_type {};

    template<typename _T>
    constexpr auto __is_array_of_known_bound_v{__is_array_of_known_bound<_T>::value};
}

}
