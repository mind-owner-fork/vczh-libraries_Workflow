/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/NewCustomInterface3.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "NewCustomInterface3Reflection.h"

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
			IMPL_CPP_TYPE_INFO(IMyInterface3)
			IMPL_CPP_TYPE_INFO(MyClass)

#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
#define _ ,
			BEGIN_INTERFACE_MEMBER(::IMyInterface3)
				CLASS_MEMBER_BASE(::vl::reflection::description::IValueEnumerable)
				CLASS_MEMBER_METHOD(Get100, NO_PARAMETER)
			END_INTERFACE_MEMBER(::IMyInterface3)

			BEGIN_CLASS_MEMBER(::MyClass)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::MyClass>(::vl::vint, ::vl::vint), { L"_begin" _ L"_end" })
				CLASS_MEMBER_METHOD(CreateMyInterface, NO_PARAMETER)
				CLASS_MEMBER_STATIC_METHOD(Get50, NO_PARAMETER)
				CLASS_MEMBER_FIELD(begin)
				CLASS_MEMBER_FIELD(end)
			END_CLASS_MEMBER(::MyClass)

#undef _
			class NewCustomInterface3TypeLoader : public Object, public ITypeLoader
			{
			public:
				void Load(ITypeManager* manager)
				{
					ADD_TYPE_INFO(::IMyInterface3)
					ADD_TYPE_INFO(::MyClass)
				}

				void Unload(ITypeManager* manager)
				{
				}
			};
#endif
#endif

			bool LoadNewCustomInterface3Types()
			{
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
				if (auto manager = GetGlobalTypeManager())
				{
					return manager->AddTypeLoader(MakePtr<NewCustomInterface3TypeLoader>());
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
