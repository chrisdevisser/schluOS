#pragma once

#include "remove_const.hh"
#include "remove_volatile.hh"

namespace std {

///remove_cv - [meta.trans.cv]
///_T with any top-level cv-qualifier removed.
template<typename _T>
struct remove_cv {
    using type = remove_const_t<remove_volatile_t<_T>>;
};

template<typename _T>
using remove_cv_t = typename remove_cv<_T>::type;

}
