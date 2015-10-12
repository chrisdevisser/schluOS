#pragma once

#include <type_traits>

namespace std {

//These are all extensions. There is no proposal for type trait
//concepts that I know of. However, they can be useful and safe
//as long as namespaces aren't subverted.

template<typename _T> concept bool Abstract{is_abstract_v<_T>};
template<typename _T> concept bool Arithmetic{is_arithmetic_v<_T>};
template<typename _T> concept bool Array{is_array_v<_T>};
template<typename _T> concept bool Class{is_class_v<_T>};
template<typename _T> concept bool Compound{is_compound_v<_T>};
template<typename _T> concept bool Const{is_const_v<_T>};
template<typename _T> concept bool CopyAssignable{is_copy_assignable_v<_T>};
template<typename _T> concept bool Destructible{is_destructible_v<_T>};
template<typename _T> concept bool Empty{is_empty_v<_T>};
template<typename _T> concept bool Enum{is_enum_v<_T>};
template<typename _T> concept bool FloatingPoint{is_floating_point_v<_T>};
template<typename _T> concept bool Function{is_function_v<_T>};
template<typename _T> concept bool Fundamental{is_fundamental_v<_T>};
template<typename _T> concept bool HasVirtualDestructor{has_virtual_destructor_v<_T>};
template<typename _T> concept bool Integral{is_integral_v<_T>};
template<typename _T> concept bool LiteralType{is_literal_type_v<_T>};
template<typename _T> concept bool LvalueReference{is_lvalue_reference_v<_T>};
template<typename _T> concept bool MemberFunctionPointer{is_member_function_pointer_v<_T>};
template<typename _T> concept bool MemberObjectPointer{is_member_object_pointer_v<_T>};
template<typename _T> concept bool MemberPointer{is_member_pointer_v<_T>};
template<typename _T> concept bool MoveAssignable{is_move_assignable_v<_T>};
template<typename _T> concept bool NothrowCopyAssignable{is_nothrow_copy_assignable_v<_T>};
template<typename _T> concept bool NothrowDestructible{is_nothrow_destructible_v<_T>};
template<typename _T> concept bool NothrowMoveAssignable{is_nothrow_move_assignable_v<_T>};
template<typename _T> concept bool NullPointer{is_null_pointer_v<_T>};
template<typename _T> concept bool Object{is_object_v<_T>};
template<typename _T> concept bool Pod{is_pod_v<_T>};
template<typename _T> concept bool Pointer{is_pointer_v<_T>};
template<typename _T> concept bool Polymorphic{is_polymorphic_v<_T>};
template<typename _T> concept bool Reference{is_reference_v<_T>};
template<typename _T> concept bool RvalueReference{is_rvalue_reference_v<_T>};
template<typename _T> concept bool Scalar{is_scalar_v<_T>};
template<typename _T> concept bool Signed{is_signed_v<_T>};
template<typename _T> concept bool StandardLayout{is_standard_layout_v<_T>};
template<typename _T> concept bool TriviallyCopyable{is_trivially_copyable_v<_T>};
template<typename _T> concept bool TriviallyCopyAssignable{is_trivially_copy_assignable_v<_T>};
template<typename _T> concept bool TriviallyDestructible{is_trivially_destructible_v<_T>};
template<typename _T> concept bool TriviallyMoveAssignable{is_trivially_move_assignable_v<_T>};
template<typename _T> concept bool Trivial{is_trivial_v<_T>};
template<typename _T> concept bool Union{is_union_v<_T>};
template<typename _T> concept bool Unsigned{is_unsigned_v<_T>};
template<typename _T> concept bool Void{is_void_v<_T>};
template<typename _T> concept bool Volatile{is_volatile_v<_T>};

template<typename _Type> concept bool CopyConstructible{is_copy_constructible_v<_Type>};
template<typename _Type> concept bool DefaultConstructible{is_default_constructible_v<_Type>};
template<typename _Type> concept bool MoveConstructible{is_move_constructible_v<_Type>};
template<typename _Type> concept bool NothrowCopyConstructible{is_nothrow_copy_constructible_v<_Type>};
template<typename _Type> concept bool NothrowDefaultConstructible{is_nothrow_default_constructible_v<_Type>};
template<typename _Type> concept bool NothrowMoveConstructible{is_nothrow_move_constructible_v<_Type>};
template<typename _Type> concept bool TriviallyCopyConstructible{is_trivially_copy_constructible_v<_Type>};
template<typename _Type> concept bool TriviallyDefaultConstructible{is_trivially_default_constructible_v<_Type>};
template<typename _Type> concept bool TriviallyMoveConstructible{is_trivially_move_constructible_v<_Type>};

template<typename _Base, typename _Derived> concept bool BaseOf{is_base_of_v<_Base, _Derived>};
template<typename _From, typename _To> concept bool Convertible{is_convertible_v<_From, _To>};
template<typename _T0, typename _T1> concept bool Same{is_same_v<_T0, _T1>};

template<typename _Lhs, typename _Rhs> concept bool Assignable{is_assignable_v<_Lhs, _Rhs>};
template<typename _Lhs, typename _Rhs> concept bool NothrowAssignable{is_nothrow_assignable_v<_Lhs, _Rhs>};
template<typename _Lhs, typename _Rhs> concept bool TriviallyAssignable{is_trivially_assignable_v<_Lhs, _Rhs>};

template<typename _Type, typename... _Args> concept bool Constructible{is_constructible_v<_Type, _Args...>};
template<typename _Type, typename... _Args> concept bool NothrowConstructible{is_nothrow_constructible_v<_Type, _Args...>};
template<typename _Type, typename... _Args> concept bool TriviallyConstructible{is_trivially_constructible_v<_Type, _Args...>};

}
