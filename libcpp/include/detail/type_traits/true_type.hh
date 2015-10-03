#pragma once

#include "bool_constant.hh"

namespace std {

///true_type - [meta.help]
///Used as a base class in various type traits.
using true_type = bool_constant<true>;

}
