/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/CoSmcCalculator.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "CoSmcCalculatorReflection.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
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
			IMPL_CPP_TYPE_INFO(SMCalculator)

#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
#define _ ,
			BEGIN_CLASS_MEMBER(::SMCalculator)
				CLASS_MEMBER_BASE(::vl::reflection::description::StateMachine)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::SMCalculator>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_state_CreateCoroutine, { L"__vwsn_state_startState" })
				CLASS_MEMBER_METHOD(Add, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Calculate, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Clear, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Digit, { L"i" })
				CLASS_MEMBER_METHOD(Dot, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Equal, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetValue, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Mul, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SetValue, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(Update, { L"value" })
				CLASS_MEMBER_EVENT(ValueChanged)
				CLASS_MEMBER_FIELD(__vwsn_prop_Value)
				CLASS_MEMBER_FIELD(__vwsn_stateip_Digit_i)
				CLASS_MEMBER_FIELD(__vwsn_statesp_Integer_newNumber)
				CLASS_MEMBER_PROPERTY_EVENT(Value, GetValue, SetValue, ValueChanged)
				CLASS_MEMBER_FIELD(op)
				CLASS_MEMBER_FIELD(valueFirst)
			END_CLASS_MEMBER(::SMCalculator)

#undef _
			class CoSmcCalculatorTypeLoader : public Object, public ITypeLoader
			{
			public:
				void Load(ITypeManager* manager)
				{
					ADD_TYPE_INFO(::SMCalculator)
				}

				void Unload(ITypeManager* manager)
				{
				}
			};
#endif
#endif

			bool LoadCoSmcCalculatorTypes()
			{
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
				if (auto manager = GetGlobalTypeManager())
				{
					return manager->AddTypeLoader(MakePtr<CoSmcCalculatorTypeLoader>());
				}
#endif
				return false;
			}
		}
	}
}

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__clang__)
#pragma clang diagnostic pop
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
