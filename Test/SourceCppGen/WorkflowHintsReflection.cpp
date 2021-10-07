/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/WorkflowHints.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "WorkflowHintsReflection.h"

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

/***********************************************************************
Reflection
***********************************************************************/

namespace vl
{
	namespace reflection
	{
		namespace description
		{
#ifndef VCZH_DEBUG_NO_REFLECTION
			IMPL_CPP_TYPE_INFO(workflow::hints::Base)
			IMPL_CPP_TYPE_INFO(workflow::hints::Derived)

#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
#define _ ,
			BEGIN_CLASS_MEMBER(::workflow::hints::Base)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::workflow::hints::Base>(), NO_PARAMETER)
				CLASS_MEMBER_CONSTRUCTOR(::workflow::hints::Base*(::vl::vint), { L"x" })
			END_CLASS_MEMBER(::workflow::hints::Base)

			BEGIN_CLASS_MEMBER(::workflow::hints::Derived)
				CLASS_MEMBER_BASE(::workflow::hints::Base)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::workflow::hints::Derived>(), NO_PARAMETER)
				CLASS_MEMBER_CONSTRUCTOR(::workflow::hints::Derived*(::vl::vint), { L"x" })
			END_CLASS_MEMBER(::workflow::hints::Derived)

#undef _
			class WorkflowHintsTypeLoader : public Object, public ITypeLoader
			{
			public:
				void Load(ITypeManager* manager)
				{
					ADD_TYPE_INFO(::workflow::hints::Base)
					ADD_TYPE_INFO(::workflow::hints::Derived)
				}

				void Unload(ITypeManager* manager)
				{
				}
			};
#endif
#endif

			bool LoadWorkflowHintsTypes()
			{
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
				if (auto manager = GetGlobalTypeManager())
				{
					return manager->AddTypeLoader(MakePtr<WorkflowHintsTypeLoader>());
				}
#endif
				return false;
			}
		}
	}
}

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif
