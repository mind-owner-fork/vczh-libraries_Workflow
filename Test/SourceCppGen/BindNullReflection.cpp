/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/BindNull.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "BindNullReflection.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
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
			IMPL_CPP_TYPE_INFO(A)
			IMPL_CPP_TYPE_INFO(B)
			IMPL_CPP_TYPE_INFO(C)

#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
#define _ ,
			BEGIN_CLASS_MEMBER(::A)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::A>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(Getb, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Setb, { L"__vwsn_value_" })
				CLASS_MEMBER_EVENT(bChanged)
				CLASS_MEMBER_FIELD(__vwsn_prop_b)
				CLASS_MEMBER_PROPERTY_EVENT(b, Getb, Setb, bChanged)
			END_CLASS_MEMBER(::A)

			BEGIN_CLASS_MEMBER(::B)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::B>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(Getc, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Setc, { L"__vwsn_value_" })
				CLASS_MEMBER_EVENT(cChanged)
				CLASS_MEMBER_FIELD(__vwsn_prop_c)
				CLASS_MEMBER_PROPERTY_EVENT(c, Getc, Setc, cChanged)
			END_CLASS_MEMBER(::B)

			BEGIN_CLASS_MEMBER(::C)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::C>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(Getx, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Setx, { L"__vwsn_value_" })
				CLASS_MEMBER_EVENT(xChanged)
				CLASS_MEMBER_FIELD(__vwsn_prop_x)
				CLASS_MEMBER_PROPERTY_EVENT(x, Getx, Setx, xChanged)
			END_CLASS_MEMBER(::C)

#undef _
			class BindNullTypeLoader : public Object, public ITypeLoader
			{
			public:
				void Load(ITypeManager* manager)
				{
					ADD_TYPE_INFO(::A)
					ADD_TYPE_INFO(::B)
					ADD_TYPE_INFO(::C)
				}

				void Unload(ITypeManager* manager)
				{
				}
			};
#endif
#endif

			bool LoadBindNullTypes()
			{
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
				if (auto manager = GetGlobalTypeManager())
				{
					return manager->AddTypeLoader(MakePtr<BindNullTypeLoader>());
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
