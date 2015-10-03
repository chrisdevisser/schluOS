#pragma once

#include "integral_constant.hh"

namespace std {

///bool_constant - [meta.help]
///Used as a base class for various type traits.
template<bool _Value>
using bool_constant = integral_constant<bool, _Value>;

}
