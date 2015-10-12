#pragma once

namespace std {

template<typename _T>
concept bool EqualityComparable = requires(const _T __t) {
    {__t == __t} -> bool;
    {__t != __t} -> bool;
};

}
