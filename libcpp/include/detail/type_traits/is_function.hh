#pragma once

#include "false_type.hh"
#include "true_type.hh"

namespace std {

///is_function - [meta.unary.cat]
///True iff _T is a function type per [basic.compound].

//We have 24 cases here:
//4 combinations of const and volatile
//3 combinations of ref qualifiers
//2 combinations of variadic
template<typename _T>
struct is_function : false_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args...)> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args..., ...)> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args...) const> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args..., ...)const > : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args...) volatile> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args..., ...) volatile> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args...) const volatile> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args..., ...) const volatile> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args...) &> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args..., ...) &> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args...) const &> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args..., ...) const &> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args...) volatile &> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args..., ...) volatile &> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args...) const volatile &> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args..., ...) const volatile &> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args...) &&> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args..., ...) &&> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args...) const &&> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args..., ...) const &&> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args...) volatile &&> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args..., ...) volatile &&> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args...) const volatile &&> : true_type {};

template<typename _Ret, typename... _Args>
struct is_function<_Ret(_Args..., ...) const volatile &&> : true_type {};

template<typename _T>
constexpr auto is_function_v{is_function<_T>::value};

}
