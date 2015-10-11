#pragma once

#include "../bool_constant.hh"
#include "../is_object.hh"
#include "../is_reference.hh"
#include "../true_type.hh"

namespace std {

namespace __detail {
    //Based on [defns.referenceable]
    //An object type, a reference, or a function type that has
    //no cv-qualifiers and no ref-qualifier.
    template<typename _T>
    struct __is_referenceable : bool_constant<
        is_object_v<_T>
        or is_reference_v<_T>
    > {};

    template<typename _Ret, typename... _Args>
    struct __is_referenceable<_Ret(_Args...)> : true_type {};

    template<typename _Ret, typename... _Args>
    struct __is_referenceable<_Ret(_Args..., ...)> : true_type {};

    template<typename _T>
    constexpr auto __is_referenceable_v{__is_referenceable<_T>::value};
}

}
