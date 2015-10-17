#pragma once

#include <detail/functional/invoke.hh>
#include <detail/utility/declval.hh>

#include "is_detected.hh"

namespace std {

namespace __detail {
    template<typename... _Ts>
    using __result_of_test = decltype(_INVOKE(declval<_Ts>()...));
}

///result_of - [meta.trans.other]
///If INVOKE(declval<Fn>(), declval<ArgTypes>()...) is well formed when
///treated as an unevaluated operand, then decltype(that).
///Otherwise, no member type.
template<typename _Signature, bool = is_detected_v<__detail::__result_of_test, _Signature>>
struct result_of {};

template<typename _F, typename... _Args>
struct result_of<_F(_Args...), true> {
    using type = __detail::__result_of_test<_F, _Args...>;
};

}
