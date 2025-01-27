/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/ClassMethod.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "ClassMethod.h"
/* CodePack:BeginIgnore() */
#ifndef VCZH_DEBUG_NO_REFLECTION
/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, ClassMethodReflection.h) */
#include "ClassMethodReflection.h"
#endif
/* CodePack:EndIgnore() */

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#endif

#define GLOBAL_SYMBOL ::vl_workflow_global::ClassMethod::
#define GLOBAL_NAME ::vl_workflow_global::ClassMethod::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::ClassMethod::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_ClassMethod)
	vl_workflow_global::ClassMethod instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS

		instance.s = ::vl::WString::Unmanaged(L"");
	FINALIZE_GLOBAL_STORAGE_CLASS

		instance.s = ::vl::WString::Empty;
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_ClassMethod)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::WString ClassMethod::main()
	{
		{
			auto a = ::vl::Ptr<::Methods>(new ::Methods());
			(GLOBAL_NAME s = (GLOBAL_NAME s + ((::vl::WString::Unmanaged(L"[") + ::vl::__vwsn::ToString(::vl::__vwsn::This(a.Obj())->x)) + ::vl::WString::Unmanaged(L"]"))));
		}
		{
			auto a = ::vl::Ptr<::Methods>(new ::Methods(static_cast<::vl::vint>(100)));
			(GLOBAL_NAME s = (GLOBAL_NAME s + ((::vl::WString::Unmanaged(L"[") + ::vl::__vwsn::ToString(::vl::__vwsn::This(a.Obj())->x)) + ::vl::WString::Unmanaged(L"]"))));
		}
		{
			auto a = ::vl::Ptr<::Methods>(new ::Methods(static_cast<::vl::vint>(1)));
			auto handler = ::vl::__vwsn::EventAttach(::vl::__vwsn::This(a.Obj())->XChanged, LAMBDA(::vl_workflow_global::__vwsnf1_ClassMethod_main_(a)));
			::vl::__vwsn::This(a.Obj())->SetX((::vl::__vwsn::This(a.Obj())->GetX() + static_cast<::vl::vint>(1)));
			::vl::__vwsn::This(a.Obj())->SetX((::vl::__vwsn::This(a.Obj())->GetX() - static_cast<::vl::vint>(1)));
			::vl::__vwsn::This(a.Obj())->SetX(::vl::__vwsn::This(a.Obj())->GetX());
			::vl::__vwsn::EventDetach(::vl::__vwsn::This(a.Obj())->XChanged, handler);
			::vl::__vwsn::This(a.Obj())->SetX(static_cast<::vl::vint>(100));
			(GLOBAL_NAME s = (GLOBAL_NAME s + ((::vl::WString::Unmanaged(L"[") + ::vl::__vwsn::ToString(::vl::__vwsn::This(a.Obj())->GetX())) + ::vl::WString::Unmanaged(L"]"))));
		}
		return GLOBAL_NAME s;
	}

	ClassMethod& ClassMethod::Instance()
	{
		return Getvl_workflow_global_ClassMethod().instance;
	}

/***********************************************************************
Closures
***********************************************************************/

	//-------------------------------------------------------------------

	__vwsnf1_ClassMethod_main_::__vwsnf1_ClassMethod_main_(::vl::Ptr<::Methods> __vwsnctor_a)
		:a(__vwsnctor_a)
	{
	}

	void __vwsnf1_ClassMethod_main_::operator()() const
	{
		(GLOBAL_NAME s = (GLOBAL_NAME s + ((::vl::WString::Unmanaged(L"[") + ::vl::__vwsn::ToString(::vl::__vwsn::This(this->a.Obj())->GetX())) + ::vl::WString::Unmanaged(L"]"))));
	}
}

/***********************************************************************
Class (::Methods)
***********************************************************************/

Methods::Methods()
	: x(static_cast<::vl::vint>(0))
{
}

Methods::Methods(::vl::vint _x)
	: x(static_cast<::vl::vint>(0))
{
	(this->x = _x);
	if ((::vl::__vwsn::This(this)->x != this->x))
	{
		throw ::vl::Exception(::vl::WString::Unmanaged(L"The \"this\" expression is not correctly implemented."));
	}
}

::vl::vint Methods::GetX()
{
	if ((::vl::__vwsn::This(this)->x != this->x))
	{
		throw ::vl::Exception(::vl::WString::Unmanaged(L"The \"this\" expression is not correctly implemented."));
	}
	return this->x;
}

void Methods::SetX(::vl::vint _x)
{
	if ((this->x != _x))
	{
		(this->x = _x);
		::vl::__vwsn::EventInvoke(this->XChanged)();
	}
}

#undef GLOBAL_SYMBOL
#undef GLOBAL_NAME
#undef GLOBAL_OBJ

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__clang__)
#pragma clang diagnostic pop
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
