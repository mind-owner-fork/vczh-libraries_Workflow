/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/NewEmptyInterface.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "NewEmptyInterface.h"
/* CodePack:BeginIgnore() */
#ifndef VCZH_DEBUG_NO_REFLECTION
/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, NewEmptyInterfaceReflection.h) */
#include "NewEmptyInterfaceReflection.h"
#endif
/* CodePack:EndIgnore() */

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses-equality"
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif

#define GLOBAL_SYMBOL ::vl_workflow_global::NewEmptyInterface::
#define GLOBAL_NAME ::vl_workflow_global::NewEmptyInterface::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::NewEmptyInterface::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_NewEmptyInterface)
	vl_workflow_global::NewEmptyInterface instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_NewEmptyInterface)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::WString NewEmptyInterface::main()
	{
		auto xs = ::vl::Ptr<::IMyEmptyInterface>(new ::vl_workflow_global::__vwsnc1_NewEmptyInterface_main__IMyEmptyInterface());
		return ((::vl::WString(L"[", false) + ::vl::__vwsn::ToString(::IMyEmptyInterface::Get50())) + ::vl::WString(L"]", false));
	}

	NewEmptyInterface& NewEmptyInterface::Instance()
	{
		return Getvl_workflow_global_NewEmptyInterface().instance;
	}

/***********************************************************************
Closures
***********************************************************************/

	//-------------------------------------------------------------------

	__vwsnc1_NewEmptyInterface_main__IMyEmptyInterface::__vwsnc1_NewEmptyInterface_main__IMyEmptyInterface()
	{
	}

}

/***********************************************************************
Class (::IMyEmptyInterface)
***********************************************************************/

::vl::vint IMyEmptyInterface::Get50()
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
