#pragma once

#define __cpp_lib_integral_constant_callable 201304

namespace std {

///Helper classes - [meta.help]
///Used as a base class for various type traits.
template<typename _T, _T _Value>
struct integral_constant {
    using value_type = _T;
    using type = integral_constant;

    static constexpr _T value = _Value;

    constexpr operator value_type() const noexcept {return value;}
    constexpr auto operator()() const noexcept {return value;}
};

}
