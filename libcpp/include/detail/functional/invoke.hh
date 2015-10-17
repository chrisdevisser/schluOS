#pragma once

#include <detail/concepts/derived_from.hh>
#include <detail/type_traits/is_class.hh>
#include <detail/type_traits/is_union.hh>
#include <detail/type_traits/is_member_function_pointer.hh>
#include <detail/type_traits/is_member_object_pointer.hh>
#include <detail/type_traits/remove_reference.hh>
#include <detail/utility/forward.hh>


namespace std {
namespace __detail {

///INVOKE - [func.require]
///Define INVOKE(f, t1..N) as follows:

///- (t1.*f)(t2..N) when f is a pointer to a member function of class T
///  and t1 is an object of type T or a reference to an object of type T
///  or a reference to an object of a type derived from T;

///- ((*t1).*f)(t2..N) when f is a pointer to a member function of class T
///  and t1 is not one of the types described in the previous item;

///- t1.*f when N == 1 and f is a pointer to member data of a class T
///  or a reference to an object of type T or a reference to an object
///  derived from T;

///- (*t1).*f when N == 1 and f is a pointer to member data of a class T
///  and t1 is not one of the types described in the previous item;

///- f(t1..N) in all other cases.

//An explicit return type with decltype is used for SFINAE between PMD and PMF versions.
//Each version is noexcept(auto).

//all other cases
template<typename _F, typename... _Args>
constexpr auto _INVOKE(_F&& __f, _Args&&... __args)
noexcept(noexcept(forward<_F>(__f)(forward<_Args>(__args)...)))
-> decltype(forward<_F>(__f)(forward<_Args>(__args)...)) {
    return forward<_F>(__f)(forward<_Args>(__args)...);
}

//PMF called on general object
template<typename _Base, typename _Derived, typename _Type, typename... _Args>
    requires (is_class_v<_Base> or is_union_v<_Base>)
    and (is_class_v<remove_reference_t<_Derived>> or is_union_v<remove_reference_t<_Derived>>)
    and DerivedFrom<remove_reference_t<_Derived>, _Base>()
constexpr auto _INVOKE(_Type _Base::*__pmf, _Derived&& __obj, _Args&&... __args)
noexcept(noexcept((forward<_Derived>(__obj).*__pmf)(forward<_Args>(__args)...)))
-> decltype((forward<_Derived>(__obj).*__pmf)(forward<_Args>(__args)...)) {
    return (forward<_Derived>(__obj).*__pmf)(forward<_Args>(__args)...);
}

//PMF called on pointer-like object
template<typename _Pmf, typename _Ptr, typename... _Args>
    requires is_member_function_pointer_v<remove_reference_t<_Pmf>>
constexpr auto _INVOKE(_Pmf&& __pmf, _Ptr&& __ptr, _Args&&... __args)
noexcept(noexcept(((*forward<_Ptr>(__ptr)).*forward<_Pmf>(__pmf))(forward<_Args>(__args)...)))
-> decltype(((*forward<_Ptr>(__ptr)).*forward<_Pmf>(__pmf))(forward<_Args>(__args)...)) {
    ((*forward<_Ptr>(__ptr)).*forward<_Pmf>(__pmf))(forward<_Args>(__args)...);
}

//PMD accessed through general object
template<typename _Base, typename _Derived, typename _Type>
    requires (is_class_v<_Base> or is_union_v<_Base>)
    and (is_class_v<remove_reference_t<_Derived>> or is_union_v<remove_reference_t<_Derived>>)
    and DerivedFrom<remove_reference_t<_Derived>, _Base>()
constexpr auto _INVOKE(_Type _Base::*__pmd, _Derived&& __obj)
noexcept(noexcept(forward<_Derived>(__obj).*__pmd))
-> decltype(forward<_Derived>(__obj).*__pmd) {
    return forward<_Derived>(__obj).*__pmd;
}

//PMD accessed through pointer-like object
template<typename _Pmd, typename _Ptr>
    requires is_member_object_pointer_v<remove_reference_t<_Pmd>>
constexpr auto _INVOKE(_Pmd&& __pmd, _Ptr&& __ptr)
noexcept(noexcept((*forward<_Ptr>(__ptr)).*forward<_Pmd>(__pmd)))
-> decltype((*forward<_Ptr>(__ptr)).*forward<_Pmd>(__pmd)) {
    return (*forward<_Ptr>(__ptr)).*forward<_Pmd>(__pmd);
}

}
}
