/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/MethodClosure.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "MethodClosure.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif

#define GLOBAL_SYMBOL ::vl_workflow_global::MethodClosure::
#define GLOBAL_NAME ::vl_workflow_global::MethodClosure::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::MethodClosure::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_MethodClosure)
	vl_workflow_global::MethodClosure instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_MethodClosure)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::WString MethodClosure::main()
	{
		auto x = ::vl::Ptr<::test::ObservableValue>(new ::test::ObservableValue(static_cast<::vl::vint>(10)));
		auto get = ::vl::Func<::vl::vint()>(::vl::__vwsn::This(x.Obj()), &::test::ObservableValue::GetValue);
		auto set = ::vl::Func<void(::vl::vint)>(::vl::__vwsn::This(x.Obj()), &::test::ObservableValue::SetValue);
		auto s1 = get();
		set(static_cast<::vl::vint>(20));
		auto s2 = get();
		return ((::vl::__vwsn::ToString(s1) + ::vl::WString(L", ", false)) + ::vl::__vwsn::ToString(s2));
	}

	MethodClosure& MethodClosure::Instance()
	{
		return Getvl_workflow_global_MethodClosure().instance;
	}
}

#undef GLOBAL_SYMBOL
#undef GLOBAL_NAME
#undef GLOBAL_OBJ

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif
