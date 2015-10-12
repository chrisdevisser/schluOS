#pragma once

#include <detail/size_t.hh>

namespace std {

namespace __detail {
    template<size_t _Len>
    struct __aligned_storage_helper {
        union __aligned_to_len {
            unsigned char __dummy[_Len];
            struct [[aligned]] {} __dummy2;
        };
    };
}

///aligned_storage - [meta.trans.other]
///A POD type suitable for use as uninitialized storage for any
///object whose size is at most _Len and whose alignment is a divisor of _Align.
///The default argument for _Align is the most stringent alignment
///requirement for any C++ object type whose size is no greater than _Len.
template<
    size_t _Len,
    size_t _Align = alignof(typename __detail::__aligned_storage_helper<_Len>::__aligned_to_len)
> struct aligned_storage {
    union type {
        alignas(_Align) unsigned char __dummy[_Len];
    };
};

template<
    size_t _Len,
    size_t _Align = alignof(typename __detail::__aligned_storage_helper<_Len>::__aligned_to_len)
 > using aligned_storage_t = typename aligned_storage<_Len, _Align>::type;

}
