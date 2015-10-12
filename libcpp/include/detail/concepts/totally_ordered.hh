#pragma once

#include "equality_comparable.hh"

namespace std {

template<typename _T>
concept bool TotallyOrdered = requires(const _T __t) {
    requires EqualityComparable<_T>;
    {__t < __t} -> bool;
    {__t > __t} -> bool;
    {__t <= __t} -> bool;
    {__t >= __t} -> bool;
};

}
