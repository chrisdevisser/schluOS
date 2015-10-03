#pragma once 

#include "integral_constant.hh"

namespace std {

template<bool _Value>
using bool_constant = integral_constant<bool, _Value>;

}
