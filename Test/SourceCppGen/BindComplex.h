/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/BindComplex.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_BINDCOMPLEX
#define VCZH_WORKFLOW_COMPILER_GENERATED_BINDCOMPLEX

#include "../Source/CppTypes.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif

namespace vl_workflow_global
{
	class __vwsnc1_BindComplex_main__vl_reflection_description_IValueSubscription;
}

/***********************************************************************
Global Variables and Functions
***********************************************************************/

namespace vl_workflow_global
{
	class BindComplex
	{
	public:

		::vl::WString s;

		void Callback(const ::vl::reflection::description::Value& value);
		::vl::WString main();

		static BindComplex& Instance();
	};

/***********************************************************************
Closures
***********************************************************************/

	class __vwsnc1_BindComplex_main__vl_reflection_description_IValueSubscription : public ::vl::Object, public virtual ::vl::reflection::description::IValueSubscription
	{
	public:
		::vl::Ptr<::test::ObservableValue> x;
		::vl::Ptr<::test::ObservableValue> y;
		::vl::Ptr<::test::ObservableValue> z;

		__vwsnc1_BindComplex_main__vl_reflection_description_IValueSubscription(::vl::Ptr<::test::ObservableValue> __vwsnctor_x, ::vl::Ptr<::test::ObservableValue> __vwsnctor_y, ::vl::Ptr<::test::ObservableValue> __vwsnctor_z);

		::vl::Ptr<::test::ObservableValue> __vwsn_bind_cache_0;
		::vl::Ptr<::test::ObservableValue> __vwsn_bind_cache_1;
		::vl::Ptr<::test::ObservableValue> __vwsn_bind_cache_2;
		::vl::Ptr<::vl::reflection::description::IEventHandler> __vwsn_bind_handler_0_0;
		::vl::Ptr<::vl::reflection::description::IEventHandler> __vwsn_bind_handler_1_0;
		::vl::Ptr<::vl::reflection::description::IEventHandler> __vwsn_bind_handler_2_0;
		bool __vwsn_bind_opened_ = false;
		bool __vwsn_bind_closed_ = false;
		void __vwsn_bind_activator_();
		void __vwsn_bind_callback_0_0(::vl::vint __vwsn_bind_callback_argument_0, ::vl::vint __vwsn_bind_callback_argument_1);
		void __vwsn_bind_callback_1_0(::vl::vint __vwsn_bind_callback_argument_0, ::vl::vint __vwsn_bind_callback_argument_1);
		void __vwsn_bind_callback_2_0(::vl::vint __vwsn_bind_callback_argument_0, ::vl::vint __vwsn_bind_callback_argument_1);
		bool Open() override;
		bool Update() override;
		bool Close() override;
	};
}

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif
