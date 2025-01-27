/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/WorkflowAttributes.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "WorkflowAttributesIncludes.h"
/* CodePack:BeginIgnore() */
#ifndef VCZH_DEBUG_NO_REFLECTION
/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, WorkflowAttributesReflection.h) */
#include "WorkflowAttributesReflection.h"
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

#define GLOBAL_SYMBOL ::vl_workflow_global::WorkflowAttributes::
#define GLOBAL_NAME ::vl_workflow_global::WorkflowAttributes::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::WorkflowAttributes::Instance()

/* USER_CONTENT_BEGIN(custom global declarations) */
/* USER_CONTENT_END() */

/***********************************************************************
Class (::calculator::Expression)
***********************************************************************/

namespace calculator
{
	::vl::WString Expression::Print()
	{/* USER_CONTENT_BEGIN(::calculator::Expression) */
		{
			return GLOBAL_NAME Print(this);
		}
	}/* USER_CONTENT_END() */

	::vl::vint Expression::Evaluate()
	{/* USER_CONTENT_BEGIN(::calculator::Expression) */
		return GLOBAL_NAME Evaluate(this);
	}/* USER_CONTENT_END() */

	Expression::Expression()
	{
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
