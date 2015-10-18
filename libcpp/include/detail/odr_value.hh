#pragma once

namespace std {
namespace __detail {

//Equivalent of Eric Niebler's __static_const.
//Allows a constexpr variable to not violate ODR.
template<typename _T>
constexpr _T __odr_value{};

}
}
