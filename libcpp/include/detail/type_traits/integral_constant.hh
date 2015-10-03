#pragma once

namespace std {

///Helper classes - [meta.help]
///Used as a base class for various type traits.
template<typename T, T _Value>
struct integral_constant {
    using value_type = T;
    using type = integral_constant<T, _Value>;

    static constexpr T value = _Value;

    constexpr operator value_type() const noexcept {return value;}
    constexpr auto operator()() const noexcept {return value;}
};

}
