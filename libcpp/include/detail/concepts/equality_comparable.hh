#pragma once

namespace std {

//For use in the STL, where only == is required.
template<typename _T>
concept bool WeakEqualityComparable = requires(const _T __t0) {
    {__t0 == __t0} -> bool;
};

template<typename _T>
concept bool EqualityComparable = requires(const _T __t0) {
    requires WeakEqualityComparable<_T>;
    {__t0 != __t0} -> bool;
};

}
