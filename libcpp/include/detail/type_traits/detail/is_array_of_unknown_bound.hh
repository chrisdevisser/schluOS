#pragma once

#include "../false_type.hh"
#include "../true_type.hh"

namespace std {

namespace __detail {
    template<typename _T>
    struct __is_array_of_unknown_bound : false_type {};

    template<typename _T>
    struct __is_array_of_unknown_bound<_T[]> : true_type {};

    template<typename _T>
    constexpr auto __is_array_of_unknown_bound_v{__is_array_of_unknown_bound<_T>::value};
}

}
