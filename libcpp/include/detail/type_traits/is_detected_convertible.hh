#pragma once

#include "is_convertible.hh"
#include "is_detected.hh"

namespace std {

//True iff _Op<_Args...> is convertible to _To.
//False if _Op<_Args...> is not valid.
template<typename _To, template<typename...> typename _Op, typename... _Args>
using is_detected_convertible = is_convertible<detected_t<_Op, _Args...>, _To>;

template<typename _To, template<typename...> typename _Op, typename... _Args>
constexpr auto is_detected_convertible_v{is_detected_convertible<_To, _Op, _Args...>::value};

}
