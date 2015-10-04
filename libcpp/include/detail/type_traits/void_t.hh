#pragma once

#define __cpp_lib_void_t 201411

namespace std {

//Always void. Used in the detection idiom.
template<typename...>
using void_t = void;

}
