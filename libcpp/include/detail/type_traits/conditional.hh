#pragma once

namespace std {

///conditional - [meta.trans.other]
///If _Cond is true, then _True, otherwise _False.
template<bool _Cond, typename _True, typename _False>
struct conditional {
    using type = _False;
};

template<typename _True, typename _False>
struct conditional<true, _True, _False> {
    using type = _True;
};

template<bool _Cond, typename _True, typename _False>
using conditional_t = typename conditional<_Cond, _True, _False>::type;

}
