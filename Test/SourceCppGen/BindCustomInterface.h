/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/BindCustomInterface.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_BINDCUSTOMINTERFACE
#define VCZH_WORKFLOW_COMPILER_GENERATED_BINDCUSTOMINTERFACE

#include "../Source/CppTypes.h"

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

namespace vl_workflow_global
{
	struct __vwsnf1_BindCustomInterface_Bind_;
	class __vwsnc1_BindCustomInterface_Bind__vl_reflection_description_IValueSubscription;
	class __vwsnc2_BindCustomInterface_main__IAdder;
}

class ISummer;
class IAdder;

class ISummer : public virtual ::vl::reflection::IDescriptable, public ::vl::reflection::Description<ISummer>
{
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
	friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<ISummer>;
#endif
public:
	virtual ::vl::vint GetSum() = 0;
	::vl::Event<void()> SumChanged;
};

class IAdder : public virtual ::ISummer, public ::vl::reflection::Description<IAdder>
{
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
	friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<IAdder>;
#endif
public:
	virtual void Add(::vl::vint value) = 0;
};

/***********************************************************************
Global Variables and Functions
***********************************************************************/

namespace vl_workflow_global
{
	class BindCustomInterface
	{
	public:

		::vl::WString s;

		::vl::Ptr<::vl::reflection::description::IValueSubscription> Bind(::vl::Ptr<::ISummer> summer);
		void Execute(::vl::Ptr<::IAdder> adder);
		::vl::WString main();

		static BindCustomInterface& Instance();
	};

/***********************************************************************
Closures
***********************************************************************/

	struct __vwsnf1_BindCustomInterface_Bind_
	{
		__vwsnf1_BindCustomInterface_Bind_();

		void operator()(const ::vl::reflection::description::Value& value) const;
	};

	class __vwsnc1_BindCustomInterface_Bind__vl_reflection_description_IValueSubscription : public ::vl::Object, public virtual ::vl::reflection::description::IValueSubscription
	{
	public:
		::vl::Ptr<::ISummer> summer;

		__vwsnc1_BindCustomInterface_Bind__vl_reflection_description_IValueSubscription(::vl::Ptr<::ISummer> __vwsnctor_summer);

		::vl::Ptr<::ISummer> __vwsn_bind_cache_0;
		::vl::Ptr<::vl::reflection::description::IEventHandler> __vwsn_bind_handler_0_0;
		bool __vwsn_bind_opened_ = false;
		bool __vwsn_bind_closed_ = false;
		void __vwsn_bind_activator_();
		void __vwsn_bind_callback_0_0();
		bool Open() override;
		bool Update() override;
		bool Close() override;
	};

	class __vwsnc2_BindCustomInterface_main__IAdder : public ::vl::Object, public virtual ::IAdder
	{
	public:
		__vwsnc2_BindCustomInterface_main__IAdder();

		::vl::vint sum = 0;
		::vl::vint GetSum() override;
		void Add(::vl::vint value) override;
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
