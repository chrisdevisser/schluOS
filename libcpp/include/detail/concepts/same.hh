#pragma once

#include <detail/type_traits/is_same.hh>

namespace std {

template<typename _T0, typename _T1>
concept bool Same = is_same_v<_T0, _T1>;

}
