#pragma once

#include <initializer_list>

#include <detail/size_t.hh>

namespace std {

namespace __detail {
    //Implemented here because I don't feel like getting the Ranges TS
    //version of std::max set up quite yet.
    constexpr auto __max(initializer_list<size_t> __values) {
        size_t __ret{};
        for (const auto& __value : __values) {
            __ret = __value > __ret ? __value : __ret;
        }

        return __ret;
    }
}

///aligned_union - [meta.trans.other]
///A POD type suitable for use as uninitialized storage for any object
///whose type is listed in _Types. Its size is at least _Len.
template<size_t _Len, typename... _Types>
struct aligned_union {
    ///alignment_value is an integral constant of type size_t
    ///whose value is the strictest alignment of all types in _Types.
    static constexpr size_t alignment_value{__detail::__max({alignof(_Types)...})};

    struct type {
        alignas(alignment_value) unsigned char __dummy[__detail::__max({_Len, sizeof(_Types)...})];
    };
};

template<size_t _Len, typename... _Types>
using aligned_union_t = typename aligned_union<_Len, _Types...>::type;

}
