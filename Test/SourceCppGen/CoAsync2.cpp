/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/CoAsync2.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "CoAsync2.h"
/* CodePack:BeginIgnore() */
#ifndef VCZH_DEBUG_NO_REFLECTION
/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, CoAsync2Reflection.h) */
#include "CoAsync2Reflection.h"
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

#define GLOBAL_SYMBOL ::vl_workflow_global::CoAsync2::
#define GLOBAL_NAME ::vl_workflow_global::CoAsync2::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::CoAsync2::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_CoAsync2)
	vl_workflow_global::CoAsync2 instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS

		instance.s = ::vl::WString::Unmanaged(L"");
	FINALIZE_GLOBAL_STORAGE_CLASS

		instance.s = ::vl::WString::Empty;
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_CoAsync2)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::Ptr<::CoAsync2_types::IStringAsync> CoAsync2::GetStringAsync(::vl::vint x)
	{
		auto __vwsn_co_mixin_source_variable_ = ::vl::reflection::description::AsyncCoroutine::Create(LAMBDA(::vl_workflow_global::__vwsnf1_CoAsync2_GetStringAsync_(x)));
		return ::vl::Ptr<::CoAsync2_types::IStringAsync>(new ::vl_workflow_global::__vwsnc2_CoAsync2_GetStringAsync__CoAsync2_types_IStringAsync(__vwsn_co_mixin_source_variable_));
	}

	::vl::Ptr<::vl::reflection::description::IAsync> CoAsync2::GetMultipleString()
	{
		return ::vl::reflection::description::AsyncCoroutine::Create(LAMBDA(::vl_workflow_global::__vwsnf2_CoAsync2_GetMultipleString_()));
	}

	::vl::WString CoAsync2::main()
	{
		::test::SyncScheduler::Run(LAMBDA(::vl_workflow_global::__vwsnf3_CoAsync2_main_()));
		return GLOBAL_NAME s;
	}

	CoAsync2& CoAsync2::Instance()
	{
		return Getvl_workflow_global_CoAsync2().instance;
	}

/***********************************************************************
Closures
***********************************************************************/

	//-------------------------------------------------------------------

	__vwsnf1_CoAsync2_GetStringAsync_::__vwsnf1_CoAsync2_GetStringAsync_(::vl::vint __vwsnctor_x)
		:x(__vwsnctor_x)
	{
	}

	::vl::Ptr<::vl::reflection::description::ICoroutine> __vwsnf1_CoAsync2_GetStringAsync_::operator()(::vl::reflection::description::AsyncCoroutine::IImpl* __vwsn_co_impl_) const
	{
		return ::vl::Ptr<::vl::reflection::description::ICoroutine>(new ::vl_workflow_global::__vwsnc1_CoAsync2_GetStringAsync___vl_reflection_description_ICoroutine(__vwsn_co_impl_, x));
	}

	//-------------------------------------------------------------------

	__vwsnf2_CoAsync2_GetMultipleString_::__vwsnf2_CoAsync2_GetMultipleString_()
	{
	}

	::vl::Ptr<::vl::reflection::description::ICoroutine> __vwsnf2_CoAsync2_GetMultipleString_::operator()(::vl::reflection::description::AsyncCoroutine::IImpl* __vwsn_co_impl_) const
	{
		return ::vl::Ptr<::vl::reflection::description::ICoroutine>(new ::vl_workflow_global::__vwsnc3_CoAsync2_GetMultipleString___vl_reflection_description_ICoroutine(__vwsn_co_impl_));
	}

	//-------------------------------------------------------------------

	__vwsnf3_CoAsync2_main_::__vwsnf3_CoAsync2_main_()
	{
	}

	void __vwsnf3_CoAsync2_main_::operator()() const
	{
		::vl::__vwsn::This(GLOBAL_NAME GetMultipleString().Obj())->Execute(LAMBDA(::vl_workflow_global::__vwsnf4_CoAsync2_main__()), ::vl::Ptr<::vl::reflection::description::AsyncContext>(new ::vl::reflection::description::AsyncContext(::vl::reflection::description::Value())));
	}

	//-------------------------------------------------------------------

	__vwsnf4_CoAsync2_main__::__vwsnf4_CoAsync2_main__()
	{
	}

	void __vwsnf4_CoAsync2_main__::operator()(::vl::Ptr<::vl::reflection::description::CoroutineResult> result) const
	{
		(GLOBAL_NAME s = ((((::vl::WString::Unmanaged(L"") + GLOBAL_NAME s) + ::vl::WString::Unmanaged(L"[")) + ::vl::__vwsn::This(::vl::__vwsn::This(result.Obj())->GetFailure().Obj())->GetMessage()) + ::vl::WString::Unmanaged(L"]")));
	}

	//-------------------------------------------------------------------

	__vwsnc1_CoAsync2_GetStringAsync___vl_reflection_description_ICoroutine::__vwsnc1_CoAsync2_GetStringAsync___vl_reflection_description_ICoroutine(::vl::reflection::description::AsyncCoroutine::IImpl* __vwsnctor___vwsn_co_impl_, ::vl::vint __vwsnctor_x)
		:__vwsn_co_impl_(__vwsnctor___vwsn_co_impl_)
		, x(__vwsnctor_x)
	{
		this->__vwsn_co_state_ = static_cast<::vl::vint>(0);
		this->__vwsn_co_state_before_pause_ = (- static_cast<::vl::vint>(1));
		this->__vwsn_prop_Failure = ::vl::Ptr<::vl::reflection::description::IValueException>();
		this->__vwsn_prop_Status = ::vl::reflection::description::CoroutineStatus::Waiting;
	}

	::vl::Ptr<::vl::reflection::description::IValueException> __vwsnc1_CoAsync2_GetStringAsync___vl_reflection_description_ICoroutine::GetFailure()
	{
		return __vwsn_prop_Failure;
	}
	void __vwsnc1_CoAsync2_GetStringAsync___vl_reflection_description_ICoroutine::SetFailure(::vl::Ptr<::vl::reflection::description::IValueException> __vwsn_value_)
	{
		(__vwsn_prop_Failure = __vwsn_value_);
	}

	::vl::reflection::description::CoroutineStatus __vwsnc1_CoAsync2_GetStringAsync___vl_reflection_description_ICoroutine::GetStatus()
	{
		return __vwsn_prop_Status;
	}
	void __vwsnc1_CoAsync2_GetStringAsync___vl_reflection_description_ICoroutine::SetStatus(::vl::reflection::description::CoroutineStatus __vwsn_value_)
	{
		(__vwsn_prop_Status = __vwsn_value_);
	}

	void __vwsnc1_CoAsync2_GetStringAsync___vl_reflection_description_ICoroutine::Resume(bool __vwsn_raise_exception_, ::vl::Ptr<::vl::reflection::description::CoroutineResult> __vwsn_co_result_)
	{
		if ((this->GetStatus() != ::vl::reflection::description::CoroutineStatus::Waiting))
		{
			throw ::vl::Exception(::vl::WString::Unmanaged(L"Resume should be called only when the coroutine is in the waiting status."));
		}
		this->SetStatus(::vl::reflection::description::CoroutineStatus::Executing);
		try
		{
			{
				if ((__vwsn_co_state_before_pause_ != (- static_cast<::vl::vint>(1))))
				{
					if ((! static_cast<bool>(__vwsn_co_result_)))
					{
						(__vwsn_co_state_before_pause_ = (- static_cast<::vl::vint>(1)));
					}
					else if ((! static_cast<bool>(::vl::__vwsn::This(__vwsn_co_result_.Obj())->GetFailure())))
					{
						(__vwsn_co_state_before_pause_ = (- static_cast<::vl::vint>(1)));
					}
					else
					{
						{
							(__vwsn_co_state_before_pause_ = (- static_cast<::vl::vint>(1)));
							throw ::vl::Exception(::vl::__vwsn::This(::vl::__vwsn::This(__vwsn_co_result_.Obj())->GetFailure().Obj())->GetMessage());
						}
					}
				}
				while (true)
				{
					if ((__vwsn_co_state_ == static_cast<::vl::vint>(0)))
					{
						if (::vl::__vwsn::This(::vl::reflection::description::AsyncCoroutine::QueryContext(__vwsn_co_impl_).Obj())->IsCancelled())
						{
							throw ::vl::Exception(::vl::WString::Unmanaged(L"Cancelled"));
						}
						::vl::reflection::description::AsyncCoroutine::ReturnAndExit(__vwsn_co_impl_, ::CoAsync2_types::IStringAsync::StoreResult(::vl::__vwsn::ToString(x)));
						this->SetStatus(::vl::reflection::description::CoroutineStatus::Stopped);
						return;
						(__vwsn_co_state_ = static_cast<::vl::vint>(1));
						continue;
					}
					if ((__vwsn_co_state_ == static_cast<::vl::vint>(1)))
					{
						this->SetStatus(::vl::reflection::description::CoroutineStatus::Stopped);
						return;
					}
				}
			}
		}
		catch(const ::vl::Exception& __vwsne_0)
		{
			auto __vwsn_co_ex_ = ::vl::reflection::description::IValueException::Create(__vwsne_0.Message());
			{
				this->SetFailure(__vwsn_co_ex_);
				this->SetStatus(::vl::reflection::description::CoroutineStatus::Stopped);
				if (__vwsn_raise_exception_)
				{
					throw;
				}
			}
		}
	}

	//-------------------------------------------------------------------

	__vwsnc2_CoAsync2_GetStringAsync__CoAsync2_types_IStringAsync::__vwsnc2_CoAsync2_GetStringAsync__CoAsync2_types_IStringAsync(::vl::Ptr<::vl::reflection::description::IAsync> __vwsnctor___vwsn_co_mixin_source_variable_)
	{
		this->__vwsn_mixin_source_ = __vwsnctor___vwsn_co_mixin_source_variable_;
	}

	bool __vwsnc2_CoAsync2_GetStringAsync__CoAsync2_types_IStringAsync::Execute(const ::vl::Func<void(::vl::Ptr<::vl::reflection::description::CoroutineResult>)>& __vwsn_mixin_parameter_callback, ::vl::Ptr<::vl::reflection::description::AsyncContext> __vwsn_mixin_parameter_context)
	{
		return ::vl::__vwsn::This(__vwsn_mixin_source_.Obj())->Execute(__vwsn_mixin_parameter_callback, __vwsn_mixin_parameter_context);
	}

	::vl::reflection::description::AsyncStatus __vwsnc2_CoAsync2_GetStringAsync__CoAsync2_types_IStringAsync::GetStatus()
	{
		return ::vl::__vwsn::This(__vwsn_mixin_source_.Obj())->GetStatus();
	}

	//-------------------------------------------------------------------

	__vwsnc3_CoAsync2_GetMultipleString___vl_reflection_description_ICoroutine::__vwsnc3_CoAsync2_GetMultipleString___vl_reflection_description_ICoroutine(::vl::reflection::description::AsyncCoroutine::IImpl* __vwsnctor___vwsn_co_impl_)
		:__vwsn_co_impl_(__vwsnctor___vwsn_co_impl_)
	{
		this->__vwsn_co0_x = ::vl::WString::Unmanaged(L"");
		this->__vwsn_co1_for_begin_i = static_cast<::vl::vint>(0);
		this->__vwsn_co2_for_end_i = static_cast<::vl::vint>(0);
		this->__vwsn_co3_i = static_cast<::vl::vint>(0);
		this->__vwsn_co_state_ = static_cast<::vl::vint>(0);
		this->__vwsn_co_state_before_pause_ = (- static_cast<::vl::vint>(1));
		this->__vwsn_prop_Failure = ::vl::Ptr<::vl::reflection::description::IValueException>();
		this->__vwsn_prop_Status = ::vl::reflection::description::CoroutineStatus::Waiting;
	}

	::vl::Ptr<::vl::reflection::description::IValueException> __vwsnc3_CoAsync2_GetMultipleString___vl_reflection_description_ICoroutine::GetFailure()
	{
		return __vwsn_prop_Failure;
	}
	void __vwsnc3_CoAsync2_GetMultipleString___vl_reflection_description_ICoroutine::SetFailure(::vl::Ptr<::vl::reflection::description::IValueException> __vwsn_value_)
	{
		(__vwsn_prop_Failure = __vwsn_value_);
	}

	::vl::reflection::description::CoroutineStatus __vwsnc3_CoAsync2_GetMultipleString___vl_reflection_description_ICoroutine::GetStatus()
	{
		return __vwsn_prop_Status;
	}
	void __vwsnc3_CoAsync2_GetMultipleString___vl_reflection_description_ICoroutine::SetStatus(::vl::reflection::description::CoroutineStatus __vwsn_value_)
	{
		(__vwsn_prop_Status = __vwsn_value_);
	}

	void __vwsnc3_CoAsync2_GetMultipleString___vl_reflection_description_ICoroutine::Resume(bool __vwsn_raise_exception_, ::vl::Ptr<::vl::reflection::description::CoroutineResult> __vwsn_co_result_)
	{
		if ((this->GetStatus() != ::vl::reflection::description::CoroutineStatus::Waiting))
		{
			throw ::vl::Exception(::vl::WString::Unmanaged(L"Resume should be called only when the coroutine is in the waiting status."));
		}
		this->SetStatus(::vl::reflection::description::CoroutineStatus::Executing);
		try
		{
			{
				if ((__vwsn_co_state_before_pause_ != (- static_cast<::vl::vint>(1))))
				{
					if ((! static_cast<bool>(__vwsn_co_result_)))
					{
						(__vwsn_co_state_before_pause_ = (- static_cast<::vl::vint>(1)));
					}
					else if ((! static_cast<bool>(::vl::__vwsn::This(__vwsn_co_result_.Obj())->GetFailure())))
					{
						(__vwsn_co_state_before_pause_ = (- static_cast<::vl::vint>(1)));
					}
					else
					{
						{
							(__vwsn_co_state_before_pause_ = (- static_cast<::vl::vint>(1)));
							throw ::vl::Exception(::vl::__vwsn::This(::vl::__vwsn::This(__vwsn_co_result_.Obj())->GetFailure().Obj())->GetMessage());
						}
					}
				}
				while (true)
				{
					if ((__vwsn_co_state_ == static_cast<::vl::vint>(0)))
					{
						(__vwsn_co1_for_begin_i = static_cast<::vl::vint>(1));
						(__vwsn_co2_for_end_i = static_cast<::vl::vint>(10));
						(__vwsn_co3_i = __vwsn_co1_for_begin_i);
						if ((__vwsn_co3_i <= __vwsn_co2_for_end_i))
						{
							(__vwsn_co_state_ = static_cast<::vl::vint>(3));
							continue;
						}
						(__vwsn_co_state_ = static_cast<::vl::vint>(1));
						continue;
					}
					if ((__vwsn_co_state_ == static_cast<::vl::vint>(1)))
					{
						this->SetStatus(::vl::reflection::description::CoroutineStatus::Stopped);
						return;
					}
					if ((__vwsn_co_state_ == static_cast<::vl::vint>(2)))
					{
						if (static_cast<bool>(::vl::__vwsn::This(__vwsn_co_result_.Obj())->GetFailure()))
						{
							throw ::vl::Exception(::vl::__vwsn::This(::vl::__vwsn::This(__vwsn_co_result_.Obj())->GetFailure().Obj())->GetMessage());
						}
						(__vwsn_co0_x = ::CoAsync2_types::IStringAsync::CastResult(::vl::__vwsn::This(__vwsn_co_result_.Obj())->GetResult()));
						(GLOBAL_NAME s = ((((::vl::WString::Unmanaged(L"") + GLOBAL_NAME s) + ::vl::WString::Unmanaged(L"[")) + __vwsn_co0_x) + ::vl::WString::Unmanaged(L"]")));
						if ((__vwsn_co3_i == static_cast<::vl::vint>(5)))
						{
							::vl::__vwsn::This(::vl::reflection::description::AsyncCoroutine::QueryContext(__vwsn_co_impl_).Obj())->Cancel();
						}
						(__vwsn_co3_i = (__vwsn_co3_i + static_cast<::vl::vint>(1)));
						if ((__vwsn_co3_i <= __vwsn_co2_for_end_i))
						{
							(__vwsn_co_state_ = static_cast<::vl::vint>(3));
							continue;
						}
						(__vwsn_co_state_ = static_cast<::vl::vint>(1));
						continue;
					}
					if ((__vwsn_co_state_ == static_cast<::vl::vint>(3)))
					{
						this->SetStatus(::vl::reflection::description::CoroutineStatus::Waiting);
						(__vwsn_co_state_before_pause_ = __vwsn_co_state_);
						(__vwsn_co_state_ = static_cast<::vl::vint>(2));
						{
							::vl::reflection::description::AsyncCoroutine::AwaitAndRead(__vwsn_co_impl_, ::vl::Ptr<::vl::reflection::description::IAsync>(GLOBAL_NAME GetStringAsync(__vwsn_co3_i)));
						}
						return;
					}
				}
			}
		}
		catch(const ::vl::Exception& __vwsne_0)
		{
			auto __vwsn_co_ex_ = ::vl::reflection::description::IValueException::Create(__vwsne_0.Message());
			{
				this->SetFailure(__vwsn_co_ex_);
				this->SetStatus(::vl::reflection::description::CoroutineStatus::Stopped);
				if (__vwsn_raise_exception_)
				{
					throw;
				}
			}
		}
	}

}

/***********************************************************************
Class (::CoAsync2_types::IStringAsync)
***********************************************************************/

namespace CoAsync2_types
{
	::vl::WString IStringAsync::CastResult(const ::vl::reflection::description::Value& value)
	{
		return ::vl::__vwsn::Unbox<::vl::WString>(value);
	}

	::vl::reflection::description::Value IStringAsync::StoreResult(const ::vl::WString& value)
	{
		return ::vl::__vwsn::Box(value);
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
