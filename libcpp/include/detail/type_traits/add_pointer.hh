#pragma once

#include "remove_reference.hh"

namespace std {

///add_pointer - [meta.trans.ptr]
///remove_reference_t<_T>*
template<typename _T>
struct add_pointer {
    using type = remove_reference_t<_T>*;
};

template<typename _T>
using add_pointer_t = typename add_pointer<_T>::type;

}
