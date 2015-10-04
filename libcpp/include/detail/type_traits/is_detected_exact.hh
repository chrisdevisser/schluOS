#pragma once

#include "is_detected.hh"
#include "is_same.hh"

//Library Fundamentals v2 TS.
//N4502: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4502.pdf

namespace std {

//True iff _Op<_Args...> is the same type as _Expected.
//Unless _Expected is nonesuch, false if _Op<_Args...> is not valid.
template<typename _Expected, template<typename...> typename _Op, typename... _Args>
using is_detected_exact = is_same<detected_t<_Op, _Args...>, _Expected>;

template<typename _Expected, template<typename...> typename _Op, typename... _Args>
constexpr auto is_detected_exact_v{is_detected_exact<_Expected, _Op, _Args...>::value};

}
