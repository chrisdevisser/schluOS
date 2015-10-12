#pragma once

namespace std {

//For use in the STL, where only == is required.
template<typename _T>
concept bool WeakEqualityComparable = requires(const _T __t) {
    {__t == __t} -> bool;
};

template<typename _T>
concept bool EqualityComparable = requires(const _T __t) {
    requires WeakEqualityComparable<_T>;
    {__t != __t} -> bool;
};

}
