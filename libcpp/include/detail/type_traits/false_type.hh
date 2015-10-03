#pragma once

#include "bool_constant.hh"

namespace std {

///false_type - [meta.help]
///Used as a base class in various type traits.
using false_type = bool_constant<false>;

}
