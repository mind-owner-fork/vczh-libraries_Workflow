/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/NewCustomInterface.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "NewCustomInterface.h"
/* CodePack:BeginIgnore() */
#ifndef VCZH_DEBUG_NO_REFLECTION
/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, NewCustomInterfaceReflection.h) */
#include "NewCustomInterfaceReflection.h"
#endif
/* CodePack:EndIgnore() */

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif

#define GLOBAL_SYMBOL ::vl_workflow_global::NewCustomInterface::
#define GLOBAL_NAME ::vl_workflow_global::NewCustomInterface::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::NewCustomInterface::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_NewCustomInterface)
	vl_workflow_global::NewCustomInterface instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_NewCustomInterface)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::WString NewCustomInterface::main()
	{
		auto begin = static_cast<::vl::vint>(1);
		auto end = static_cast<::vl::vint>(5);
		auto xs = ::vl::Ptr<::IMyInterface>(new ::vl_workflow_global::__vwsnc1_NewCustomInterface_main__IMyInterface(begin, end));
		return ((((((::vl::WString(L"[", false) + ::vl::__vwsn::ToString(::vl::__vwsn::This(xs.Obj())->Get100())) + ::vl::WString(L"][", false)) + ::vl::__vwsn::ToString(::test::CustomInterfaceProcessor::Sum(::vl::Ptr<::vl::reflection::description::IValueEnumerable>(xs)))) + ::vl::WString(L"][", false)) + ::vl::__vwsn::ToString(::test::CustomInterfaceProcessor::Sum(::vl::Ptr<::vl::reflection::description::IValueEnumerable>(xs)))) + ::vl::WString(L"]", false));
	}

	NewCustomInterface& NewCustomInterface::Instance()
	{
		return Getvl_workflow_global_NewCustomInterface().instance;
	}

/***********************************************************************
Closures
***********************************************************************/

	//-------------------------------------------------------------------

	__vwsnc1_NewCustomInterface_main__IMyInterface::__vwsnc1_NewCustomInterface_main__IMyInterface(::vl::vint __vwsnctor_begin, ::vl::vint __vwsnctor_end)
		:begin(__vwsnctor_begin)
		, end(__vwsnctor_end)
	{
	}

	::vl::Ptr<::vl::reflection::description::IValueEnumerator> __vwsnc1_NewCustomInterface_main__IMyInterface::CreateEnumerator()
	{
		return ::vl::Ptr<::vl::reflection::description::IValueEnumerator>(new ::vl_workflow_global::__vwsnc2_NewCustomInterface_main_CreateEnumerator__vl_reflection_description_IValueEnumerator(this->begin, this->end, this));
	}

	::vl::vint __vwsnc1_NewCustomInterface_main__IMyInterface::Get100()
	{
		return (::IMyInterface::Get50() * static_cast<::vl::vint>(2));
	}

	//-------------------------------------------------------------------

	__vwsnc2_NewCustomInterface_main_CreateEnumerator__vl_reflection_description_IValueEnumerator::__vwsnc2_NewCustomInterface_main_CreateEnumerator__vl_reflection_description_IValueEnumerator(::vl::vint __vwsnctor_begin, ::vl::vint __vwsnctor_end, ::IMyInterface* __vwsnctorthis_0)
		:begin(__vwsnctor_begin)
		, end(__vwsnctor_end)
		, __vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
	{
		this->index = (- static_cast<::vl::vint>(1));
	}

	::vl::reflection::description::Value __vwsnc2_NewCustomInterface_main_CreateEnumerator__vl_reflection_description_IValueEnumerator::GetCurrent()
	{
		return ::vl::__vwsn::Box((this->begin + index));
	}

	::vl::vint __vwsnc2_NewCustomInterface_main_CreateEnumerator__vl_reflection_description_IValueEnumerator::GetIndex()
	{
		return index;
	}

	bool __vwsnc2_NewCustomInterface_main_CreateEnumerator__vl_reflection_description_IValueEnumerator::Next()
	{
		if ((index == (this->end - this->begin)))
		{
			return false;
		}
		else
		{
			(index = (index + static_cast<::vl::vint>(1)));
			return true;
		}
	}

}

/***********************************************************************
Class (::IMyInterface)
***********************************************************************/

::vl::vint IMyInterface::Get50()
{
	return static_cast<::vl::vint>(50);
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
