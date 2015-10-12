#pragma once

namespace std {

template<typename _T>
concept bool LessThanComparable = requires(const _T __t) {
    {__t < __t} -> bool;
};

}
