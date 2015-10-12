#pragma once

namespace std {

template<typename _T>
concept bool EqualityComparable = requires(_T __t0, _T __t1) {
    {__t0 == __t1} -> bool;
    {__t0 != __t1} -> bool;
};

}
