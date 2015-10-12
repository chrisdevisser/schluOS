#pragma once

namespace std {

///remove_pointer - [meta.trans.ptr]
///If _T is a possibly cv-qualified pointer to T1, then T1, otherwise _T.
template<typename _T>
struct remove_pointer {
    using type = _T;
};

template<typename _T>
struct remove_pointer<_T*> {
    using type = _T;
};

}
