#pragma once

#include "detected_or.hh"
#include "nonesuch.hh"

//Library Fundamentals v2 TS.
//N4502: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4502.pdf

namespace std {

template<template<typename...> typename _Op, typename... _Args>
using is_detected = typename detected_or<nonesuch, _Op, _Args...>::value_t;

template<template<typename...> typename _Op, typename... _Args>
using detected_t = detected_or_t<nonesuch, _Op, _Args...>;

template<template<typename...> typename _Op, typename... _Args>
constexpr auto is_detected_v{is_detected<_Op, _Args...>::value};

}
