#pragma once

namespace std {

//For use in the STL, where only == is required.
template<typename _T>
concept bool WeakEqualityComparable = requires(_T __t0, _T __t1) {
    {__t0 == __t1} -> bool;
};

template<typename _T>
concept bool EqualityComparable = requires(_T __t0, _T __t1) {
    requires WeakEqualityComparable<_T>;
    {__t0 != __t1} -> bool;
};

}
