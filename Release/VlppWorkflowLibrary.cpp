﻿/***********************************************************************
THIS FILE IS AUTOMATICALLY GENERATED. DO NOT MODIFY
DEVELOPER: Zihan Chen(vczh)
***********************************************************************/
#include "VlppWorkflowLibrary.h"

/***********************************************************************
.\WFLIBRARYCPPHELPER.CPP
***********************************************************************/

namespace vl
{
	namespace __vwsn
	{

/***********************************************************************
CreateList
***********************************************************************/

		CreateList::CreateList()
			:list(IValueList::Create())
		{
		}

		CreateList::CreateList(Ptr<IValueList> _list)
			:list(_list)
		{
		}

/***********************************************************************
CreateObservableList
***********************************************************************/

		CreateObservableList::CreateObservableList()
			:list(IValueObservableList::Create())
		{
		}

		CreateObservableList::CreateObservableList(Ptr<IValueObservableList> _list)
			:list(_list)
		{
		}

/***********************************************************************
CreateDictionary
***********************************************************************/

		CreateDictionary::CreateDictionary()
			:dictionary(IValueDictionary::Create())
		{
		}

		CreateDictionary::CreateDictionary(Ptr<IValueDictionary> _dictionary)
			:dictionary(_dictionary)
		{
		}
	}
}

/***********************************************************************
.\WFLIBRARYPREDEFINED.CPP
***********************************************************************/

namespace vl
{
	using namespace collections;

	namespace reflection
	{
		namespace description
		{

/***********************************************************************
CoroutineResult
***********************************************************************/

			Value CoroutineResult::GetResult()
			{
				return result;
			}

			void CoroutineResult::SetResult(const Value& value)
			{
				result = value;
			}

			Ptr<IValueException> CoroutineResult::GetFailure()
			{
				return failure;
			}

			void CoroutineResult::SetFailure(Ptr<IValueException> value)
			{
				failure = value;
			}

/***********************************************************************
EnumerableCoroutine
***********************************************************************/

			class CoroutineEnumerator : public Object, public virtual EnumerableCoroutine::IImpl, public Description<CoroutineEnumerator>
			{
			protected:
				EnumerableCoroutine::Creator		creator;
				Ptr<ICoroutine>						coroutine;
				Value								current;
				vint								index = -1;
				Ptr<IValueEnumerator>				joining;

			public:
				CoroutineEnumerator(const EnumerableCoroutine::Creator& _creator)
					:creator(_creator)
				{
				}

				Value GetCurrent()override
				{
					return current;
				}

				vint GetIndex()override
				{
					return index;
				}

				bool Next()override
				{
					if (!coroutine)
					{
						coroutine = creator(this);
					}

					while (coroutine->GetStatus() == CoroutineStatus::Waiting)
					{
						if (joining)
						{
							if (joining->Next())
							{
								current = joining->GetCurrent();
								index++;
								return true;
							}
							else
							{
								joining = nullptr;
							}
						}

						coroutine->Resume(true, nullptr);
						if (coroutine->GetStatus() != CoroutineStatus::Waiting)
						{
							break;
						}

						if (!joining)
						{
							index++;
							return true;
						}
					}
					return false;
				}

				void OnYield(const Value& value)override
				{
					current = value;
					joining = nullptr;
				}

				void OnJoin(Ptr<IValueEnumerable> value)override
				{
					if (!value)
					{
						throw Exception(L"Cannot join a null collection.");
					}
					current = Value();
					joining = value->CreateEnumerator();
				}
			};

			class CoroutineEnumerable : public Object, public virtual IValueEnumerable, public Description<CoroutineEnumerable>
			{
			protected:
				EnumerableCoroutine::Creator		creator;

			public:
				CoroutineEnumerable(const EnumerableCoroutine::Creator& _creator)
					:creator(_creator)
				{
				}

				Ptr<IValueEnumerator> CreateEnumerator()override
				{
					return new CoroutineEnumerator(creator);
				}
			};

			void EnumerableCoroutine::YieldAndPause(IImpl* impl, const Value& value)
			{
				impl->OnYield(value);
			}

			void EnumerableCoroutine::JoinAndPause(IImpl* impl, Ptr<IValueEnumerable> value)
			{
				impl->OnJoin(value);
			}

			void EnumerableCoroutine::ReturnAndExit(IImpl* impl)
			{
			}

			Ptr<IValueEnumerable> EnumerableCoroutine::Create(const Creator& creator)
			{
				return new CoroutineEnumerable(creator);
			}

/***********************************************************************
AsyncContext
***********************************************************************/

			AsyncContext::AsyncContext(const Value& _context)
				:context(_context)
			{
			}

			AsyncContext::~AsyncContext()
			{
			}

			bool AsyncContext::IsCancelled()
			{
				SPIN_LOCK(lock)
				{
					return cancelled;
				}
				CHECK_FAIL(L"Not reachable");
			}

			bool AsyncContext::Cancel()
			{
				SPIN_LOCK(lock)
				{
					if (cancelled) return false;
					cancelled = true;
					return true;
				}
				CHECK_FAIL(L"Not reachable");
			}

			const description::Value& AsyncContext::GetContext()
			{
				SPIN_LOCK(lock)
				{
					return context;
				}
				CHECK_FAIL(L"Not reachable");
			}

			void AsyncContext::SetContext(const description::Value& value)
			{
				SPIN_LOCK(lock)
				{
					context = value;
				}
			}

/***********************************************************************
DelayAsync
***********************************************************************/

			class DelayAsync : public Object, public virtual IAsync, public Description<DelayAsync>
			{
			protected:
				SpinLock							lock;
				vint								milliseconds;
				AsyncStatus							status = AsyncStatus::Ready;

			public:
				DelayAsync(vint _milliseconds)
					:milliseconds(_milliseconds)
				{
				}

				AsyncStatus GetStatus()override
				{
					return status;
				}

				bool Execute(const Func<void(Ptr<CoroutineResult>)>& _callback, Ptr<AsyncContext> context)override
				{
					SPIN_LOCK(lock)
					{
						if (status != AsyncStatus::Ready) return false;
						status = AsyncStatus::Executing;
						IAsyncScheduler::GetSchedulerForCurrentThread()->DelayExecute([async = Ptr<DelayAsync>(this), callback = _callback]()
						{
							if (callback)
							{
								callback(nullptr);
							}
						}, milliseconds);
					}
					return true;
				}
			};

			Ptr<IAsync> IAsync::Delay(vint milliseconds)
			{
				return new DelayAsync(milliseconds);
			}

/***********************************************************************
FutureAndPromiseAsync
***********************************************************************/

			class FutureAndPromiseAsync : public virtual IFuture, public virtual IPromise, public Description<FutureAndPromiseAsync>
			{
			public:
				SpinLock							lock;
				AsyncStatus							status = AsyncStatus::Ready;
				Ptr<CoroutineResult>				cr;
				Func<void(Ptr<CoroutineResult>)>	callback;

				void ExecuteCallbackAndClear()
				{
					status = AsyncStatus::Stopped;
					if (callback)
					{
						callback(cr);
					}
					cr = nullptr;
					callback = {};
				}

				template<typename F>
				bool Send(F f)
				{
					SPIN_LOCK(lock)
					{
						if (status == AsyncStatus::Stopped || cr) return false;
						cr = MakePtr<CoroutineResult>();
						f();
						if (status == AsyncStatus::Executing)
						{
							ExecuteCallbackAndClear();
						}
					}
					return true;
				}

				AsyncStatus GetStatus()override
				{
					return status;
				}

				bool Execute(const Func<void(Ptr<CoroutineResult>)>& _callback, Ptr<AsyncContext> context)override
				{
					SPIN_LOCK(lock)
					{
						if (status != AsyncStatus::Ready) return false;
						callback = _callback;
						if (cr)
						{
							ExecuteCallbackAndClear();
						}
						else
						{
							status = AsyncStatus::Executing;
						}
					}
					return true;
				}

				Ptr<IPromise> GetPromise()override
				{
					return this;
				}

				bool SendResult(const Value& result)override
				{
					return Send([=]()
					{
						cr->SetResult(result);
					});
				}

				bool SendFailure(Ptr<IValueException> failure)override
				{
					return Send([=]()
					{
						cr->SetFailure(failure);
					});
				}
			};

			Ptr<IFuture> IFuture::Create()
			{
				return new FutureAndPromiseAsync();
			}

/***********************************************************************
IAsyncScheduler
***********************************************************************/

			class AsyncSchedulerMap
			{
			public:
				Dictionary<vint, Ptr<IAsyncScheduler>>		schedulers;
				Ptr<IAsyncScheduler>						defaultScheduler;
			};

			AsyncSchedulerMap* asyncSchedulerMap = nullptr;
			SpinLock asyncSchedulerLock;

#define ENSURE_ASYNC_SCHEDULER_MAP\
			if (!asyncSchedulerMap) asyncSchedulerMap = new AsyncSchedulerMap;

#define DISPOSE_ASYNC_SCHEDULER_MAP_IF_NECESSARY\
			if (asyncSchedulerMap->schedulers.Count() == 0 && !asyncSchedulerMap->defaultScheduler)\
			{\
				delete asyncSchedulerMap;\
				asyncSchedulerMap = nullptr;\
			}\

			void IAsyncScheduler::RegisterDefaultScheduler(Ptr<IAsyncScheduler> scheduler)
			{
				SPIN_LOCK(asyncSchedulerLock)
				{
					ENSURE_ASYNC_SCHEDULER_MAP
					CHECK_ERROR(!asyncSchedulerMap->defaultScheduler, L"IAsyncScheduler::RegisterDefaultScheduler()#A default scheduler has already been registered.");
					asyncSchedulerMap->defaultScheduler = scheduler;
				}
			}

			void IAsyncScheduler::RegisterSchedulerForCurrentThread(Ptr<IAsyncScheduler> scheduler)
			{
				SPIN_LOCK(asyncSchedulerLock)
				{
					ENSURE_ASYNC_SCHEDULER_MAP
					CHECK_ERROR(!asyncSchedulerMap->schedulers.Keys().Contains(Thread::GetCurrentThreadId()), L"IAsyncScheduler::RegisterDefaultScheduler()#A scheduler for this thread has already been registered.");
					asyncSchedulerMap->schedulers.Add(Thread::GetCurrentThreadId(), scheduler);
				}
			}

			Ptr<IAsyncScheduler> IAsyncScheduler::UnregisterDefaultScheduler()
			{
				Ptr<IAsyncScheduler> scheduler;
				SPIN_LOCK(asyncSchedulerLock)
				{
					if (asyncSchedulerMap)
					{
						scheduler = asyncSchedulerMap->defaultScheduler;
						asyncSchedulerMap->defaultScheduler = nullptr;
						DISPOSE_ASYNC_SCHEDULER_MAP_IF_NECESSARY
					}
				}
				return scheduler;
			}

			Ptr<IAsyncScheduler> IAsyncScheduler::UnregisterSchedulerForCurrentThread()
			{
				Ptr<IAsyncScheduler> scheduler;
				SPIN_LOCK(asyncSchedulerLock)
				{
					if (asyncSchedulerMap)
					{
						vint index = asyncSchedulerMap->schedulers.Keys().IndexOf(Thread::GetCurrentThreadId());
						if (index != -1)
						{
							scheduler = asyncSchedulerMap->schedulers.Values()[index];
							asyncSchedulerMap->schedulers.Remove(Thread::GetCurrentThreadId());
						}
						DISPOSE_ASYNC_SCHEDULER_MAP_IF_NECESSARY
					}
				}
				return scheduler;
			}

#undef ENSURE_ASYNC_SCHEDULER_MAP
#undef DISPOSE_ASYNC_SCHEDULER_MAP_IF_NECESSARY

			Ptr<IAsyncScheduler> IAsyncScheduler::GetSchedulerForCurrentThread()
			{
				Ptr<IAsyncScheduler> scheduler;
				SPIN_LOCK(asyncSchedulerLock)
				{
					CHECK_ERROR(asyncSchedulerMap != nullptr, L"IAsyncScheduler::GetSchedulerForCurrentThread()#There is no scheduler registered for the current thread.");
					vint index = asyncSchedulerMap->schedulers.Keys().IndexOf(Thread::GetCurrentThreadId());
					if (index != -1)
					{
						scheduler = asyncSchedulerMap->schedulers.Values()[index];
					}
					else if (asyncSchedulerMap->defaultScheduler)
					{
						scheduler = asyncSchedulerMap->defaultScheduler;
					}
					else
					{
						CHECK_FAIL(L"IAsyncScheduler::GetSchedulerForCurrentThread()#There is no scheduler registered for the current thread.");
					}
				}
				return scheduler;
			}

/***********************************************************************
AsyncCoroutine
***********************************************************************/

			class CoroutineAsync : public Object, public virtual AsyncCoroutine::IImpl, public Description<CoroutineAsync>
			{
			protected:
				Ptr<ICoroutine>						coroutine;
				AsyncCoroutine::Creator				creator;
				Ptr<IAsyncScheduler>				scheduler;
				Func<void(Ptr<CoroutineResult>)>	callback;
				Ptr<AsyncContext>					context;
				Value								result;

			public:
				CoroutineAsync(AsyncCoroutine::Creator _creator)
					:creator(_creator)
				{
				}

				AsyncStatus GetStatus()override
				{
					if (!coroutine)
					{
						return AsyncStatus::Ready;
					}
					else if (coroutine->GetStatus() != CoroutineStatus::Stopped)
					{
						return AsyncStatus::Executing;
					}
					else
					{
						return AsyncStatus::Stopped;
					}
				}

				bool Execute(const Func<void(Ptr<CoroutineResult>)>& _callback, Ptr<AsyncContext> _context)override
				{
					if (coroutine) return false;
					scheduler = IAsyncScheduler::GetSchedulerForCurrentThread();
					callback = _callback;
					context = _context;
					coroutine = creator(this);
					OnContinue(nullptr);
					return true;
				}

				Ptr<IAsyncScheduler> GetScheduler()override
				{
					return scheduler;
				}

				Ptr<AsyncContext> GetContext()override
				{
					if (!context)
					{
						context = new AsyncContext;
					}
					return context;
				}

				void OnContinue(Ptr<CoroutineResult> output)override
				{
					scheduler->Execute([async = Ptr<CoroutineAsync>(this), output]()
					{
						async->coroutine->Resume(false, output);
						if (async->coroutine->GetStatus() == CoroutineStatus::Stopped && async->callback)
						{
							auto result = MakePtr<CoroutineResult>();
							if (async->coroutine->GetFailure())
							{
								result->SetFailure(async->coroutine->GetFailure());
							}
							else
							{
								result->SetResult(async->result);
							}
							async->callback(result);
						}
					});
				}

				void OnReturn(const Value& value)override
				{
					result = value;
				}
			};
			
			void AsyncCoroutine::AwaitAndRead(IImpl* impl, Ptr<IAsync> value)
			{
				value->Execute([async = Ptr<IImpl>(impl)](auto output)
				{
					async->OnContinue(output);
				}, impl->GetContext());
			}

			void AsyncCoroutine::ReturnAndExit(IImpl* impl, const Value& value)
			{
				impl->OnReturn(value);
			}

			Ptr<AsyncContext> AsyncCoroutine::QueryContext(IImpl* impl)
			{
				return impl->GetContext();
			}

			Ptr<IAsync> AsyncCoroutine::Create(const Creator& creator)
			{
				return new CoroutineAsync(creator);
			}
			void AsyncCoroutine::CreateAndRun(const Creator& creator)
			{
				MakePtr<CoroutineAsync>(creator)->Execute(
					[](Ptr<CoroutineResult> cr)
					{
						if (cr->GetFailure())
						{
#pragma push_macro("GetMessage")
#if defined GetMessage
#undef GetMessage
#endif
							throw Exception(cr->GetFailure()->GetMessage());
#pragma pop_macro("GetMessage")
						}
					}, nullptr);
			}

/***********************************************************************
StateMachine
***********************************************************************/

			void StateMachine::ResumeStateMachine()
			{
				Ptr<CoroutineResult> previousResult;
				while (true)
				{
					if (stateMachineCoroutine == nullptr)
					{
						if (!stateMachineInitialized)
						{
							throw Exception(L"The state machine has not been initialized.");
						}
						if (stateMachineStopped)
						{
							throw Exception(L"The state machine has been stopped.");
						}
						stateMachineStopped = true;

						if (previousResult)
						{
							if (auto failure = previousResult->GetFailure())
							{
								throw Exception(failure->GetMessage());
							}
						}
						break;
					}
					else if (stateMachineCoroutine->GetStatus() != CoroutineStatus::Stopped)
					{
						auto currentCoroutine = stateMachineCoroutine;
						currentCoroutine->Resume(false, previousResult);
						if (stateMachineCoroutine == currentCoroutine)
						{
							// wait for input
							break;
						}
						else if (currentCoroutine->GetStatus() == CoroutineStatus::Stopped)
						{
							// leave a state machine
							previousResult = MakePtr<CoroutineResult>();
							if (auto failure = currentCoroutine->GetFailure())
							{
								previousResult->SetFailure(failure);
							}
						}
						else
						{
							// enter a state machine
						}
					}
				}
			}

			StateMachine::StateMachine()
			{
			}

			StateMachine::~StateMachine()
			{
				FinalizeAggregation();
			}

			CoroutineStatus StateMachine::GetStateMachineStatus()
			{
				if (stateMachineStopped)
				{
					return CoroutineStatus::Stopped;
				}
				else if (stateMachineCoroutine)
				{
					if (stateMachineCoroutine->GetStatus() == CoroutineStatus::Waiting)
					{
						return CoroutineStatus::Waiting;
					}
					else
					{
						return CoroutineStatus::Executing;
					}
				}
				else
				{
					return CoroutineStatus::Waiting;
				}
			}

/***********************************************************************
Sys
***********************************************************************/

			namespace system_sys
			{
				class ReverseEnumerable : public Object, public IValueEnumerable
				{
				protected:
					Ptr<IValueReadonlyList>					list;

					class Enumerator : public Object, public IValueEnumerator
					{
					protected:
						Ptr<IValueReadonlyList>				list;
						vint								index;

					public:
						Enumerator(Ptr<IValueReadonlyList> _list)
							:list(_list), index(_list->GetCount())
						{
						}

						Value GetCurrent()
						{
							return list->Get(index);
						}

						vint GetIndex()
						{
							return list->GetCount() - 1 - index;
						}

						bool Next()
						{
							if (index <= 0) return false;
							index--;
							return true;
						}
					};

				public:
					ReverseEnumerable(Ptr<IValueReadonlyList> _list)
						:list(_list)
					{
					}

					Ptr<IValueEnumerator> CreateEnumerator()override
					{
						return MakePtr<Enumerator>(list);
					}
				};
			}

			DateTime Sys::GetLocalTime()
			{
				return DateTime::LocalTime();
			}

			DateTime Sys::GetUtcTime()
			{
				return DateTime::UtcTime();
			}

			DateTime Sys::ToLocalTime(DateTime dt)
			{
				return dt.ToLocalTime();
			}

			DateTime Sys::ToUtcTime(DateTime dt)
			{
				return dt.ToUtcTime();
			}

			DateTime Sys::Forward(DateTime dt, vuint64_t milliseconds)
			{
				return dt.Forward(milliseconds);
			}

			DateTime Sys::Backward(DateTime dt, vuint64_t milliseconds)
			{
				return dt.Backward(milliseconds);
			}

			DateTime Sys::CreateDateTime(vint year, vint month, vint day)
			{
				return DateTime::FromDateTime(year, month, day);
			}

			DateTime Sys::CreateDateTime(vint year, vint month, vint day, vint hour, vint minute, vint second, vint milliseconds)
			{
				return DateTime::FromDateTime(year, month, day, hour, minute, second, milliseconds);
			}

			DateTime Sys::CreateDateTime(vuint64_t filetime)
			{
				return DateTime::FromFileTime(filetime);
			}

			Ptr<IValueEnumerable> Sys::ReverseEnumerable(Ptr<IValueEnumerable> value)
			{
				auto list = value.Cast<IValueReadonlyList>();
				if (!list)
				{
					list = IValueList::Create(GetLazyList<Value>(value));
				}
				return new system_sys::ReverseEnumerable(list);
			}

#define DEFINE_COMPARE(TYPE)\
			vint Sys::Compare(TYPE a, TYPE b)\
			{\
				auto result = TypedValueSerializerProvider<TYPE>::Compare(a, b);\
				switch (result)\
				{\
				case IBoxedValue::Smaller:	return -1;\
				case IBoxedValue::Greater:	return 1;\
				case IBoxedValue::Equal:	return 0;\
				default:\
					CHECK_FAIL(L"Unexpected compare result.");\
				}\
			}\

			REFLECTION_PREDEFINED_PRIMITIVE_TYPES(DEFINE_COMPARE)
			DEFINE_COMPARE(DateTime)
#undef DEFINE_COMPARE

/***********************************************************************
Math
***********************************************************************/

#define DEFINE_MINMAX(TYPE)\
			TYPE Math::Min(TYPE a, TYPE b)\
			{\
				return Sys::Compare(a, b) < 0 ? a : b;\
			}\
			TYPE Math::Max(TYPE a, TYPE b)\
			{\
				return Sys::Compare(a, b) > 0 ? a : b;\
			}\

			REFLECTION_PREDEFINED_PRIMITIVE_TYPES(DEFINE_MINMAX)
			DEFINE_MINMAX(DateTime)
#undef DEFINE_MINMAX

/***********************************************************************
Localization
***********************************************************************/

			Locale Localization::Invariant()
			{
				return Locale::Invariant();
			}

			Locale Localization::System()
			{
				return Locale::SystemDefault();
			}

			Locale Localization::User()
			{
				return Locale::UserDefault();
			}

			collections::LazyList<Locale> Localization::Locales()
			{
				auto result = MakePtr<List<Locale>>();
				Locale::Enumerate(*result.Obj());
				return result;
			}

			collections::LazyList<WString> Localization::GetShortDateFormats(Locale locale)
			{
				auto result = MakePtr<List<WString>>();
				locale.GetShortDateFormats(*result.Obj());
				return result;
			}

			collections::LazyList<WString> Localization::GetLongDateFormats(Locale locale)
			{
				auto result = MakePtr<List<WString>>();
				locale.GetLongDateFormats(*result.Obj());
				return result;
			}

			collections::LazyList<WString> Localization::GetYearMonthDateFormats(Locale locale)
			{
				auto result = MakePtr<List<WString>>();
				locale.GetYearMonthDateFormats(*result.Obj());
				return result;
			}

			collections::LazyList<WString> Localization::GetLongTimeFormats(Locale locale)
			{
				auto result = MakePtr<List<WString>>();
				locale.GetLongTimeFormats(*result.Obj());
				return result;
			}

			collections::LazyList<WString> Localization::GetShortTimeFormats(Locale locale)
			{
				auto result = MakePtr<List<WString>>();
				locale.GetShortTimeFormats(*result.Obj());
				return result;
			}

			WString Localization::GetShortDayOfWeekName(Locale locale, vint dayOfWeek)
			{
				return locale.GetShortDayOfWeekName(dayOfWeek);
			}

			WString Localization::GetLongDayOfWeekName(Locale locale, vint dayOfWeek)
			{
				return locale.GetLongDayOfWeekName(dayOfWeek);
			}

			WString Localization::GetShortMonthName(Locale locale, vint month)
			{
				return locale.GetShortMonthName(month);
			}

			WString Localization::GetLongMonthName(Locale locale, vint month)
			{
				return locale.GetLongMonthName(month);
			}

			WString Localization::FormatDate(Locale locale, const WString& format, DateTime date)
			{
				return locale.FormatDate(format, date);
			}

			WString Localization::FormatTime(Locale locale, const WString& format, DateTime date)
			{
				return locale.FormatTime(format, date);
			}

			WString Localization::FormatNumber(Locale locale, const WString& number)
			{
				return locale.FormatNumber(number);
			}

			WString Localization::FormatCurrency(Locale locale, const WString& number)
			{
				return locale.FormatCurrency(number);
			}
		}
	}
}


/***********************************************************************
.\WFLIBRARYREFLECTION.CPP
***********************************************************************/
#include <limits.h>
#include <float.h>

namespace vl
{
	using namespace collections;
	using namespace regex;

	namespace reflection
	{
		namespace description
		{

/***********************************************************************
TypeName
***********************************************************************/

#ifndef VCZH_DEBUG_NO_REFLECTION

			IMPL_TYPE_INFO_RENAME(vl::reflection::description::Sys, system::Sys)
			IMPL_TYPE_INFO_RENAME(vl::reflection::description::Math, system::Math)
			IMPL_TYPE_INFO_RENAME(vl::reflection::description::Localization, system::Localization)
			IMPL_TYPE_INFO_RENAME(vl::reflection::description::CoroutineStatus, system::CoroutineStatus)
			IMPL_TYPE_INFO_RENAME(vl::reflection::description::CoroutineResult, system::CoroutineResult)
			IMPL_TYPE_INFO_RENAME(vl::reflection::description::ICoroutine, system::Coroutine)
			IMPL_TYPE_INFO_RENAME(vl::reflection::description::EnumerableCoroutine::IImpl, system::EnumerableCoroutine::IImpl)
			IMPL_TYPE_INFO_RENAME(vl::reflection::description::EnumerableCoroutine, system::EnumerableCoroutine)
			IMPL_TYPE_INFO_RENAME(vl::reflection::description::AsyncStatus, system::AsyncStatus)
			IMPL_TYPE_INFO_RENAME(vl::reflection::description::AsyncContext, system::AsyncContext)
			IMPL_TYPE_INFO_RENAME(vl::reflection::description::IAsync, system::Async)
			IMPL_TYPE_INFO_RENAME(vl::reflection::description::IPromise, system::Promise)
			IMPL_TYPE_INFO_RENAME(vl::reflection::description::IFuture, system::Future)
			IMPL_TYPE_INFO_RENAME(vl::reflection::description::IAsyncScheduler, system::AsyncScheduler)
			IMPL_TYPE_INFO_RENAME(vl::reflection::description::AsyncCoroutine::IImpl, system::AsyncCoroutine::IImpl)
			IMPL_TYPE_INFO_RENAME(vl::reflection::description::AsyncCoroutine, system::AsyncCoroutine)
			IMPL_TYPE_INFO_RENAME(vl::reflection::description::StateMachine, system::StateMachine)

#endif

/***********************************************************************
WfLoadLibraryTypes
***********************************************************************/

#ifndef VCZH_DEBUG_NO_REFLECTION

#define _ ,	

			template<>
			struct CustomTypeDescriptorSelector<DescriptableObject>
			{
			public:
				class CustomTypeDescriptorImpl : public TypeDescriptorImpl
				{
				public:
					CustomTypeDescriptorImpl()
						:TypeDescriptorImpl(TypeDescriptorFlags::Class, &TypeInfo<DescriptableObject>::content)
					{
						Description<DescriptableObject>::SetAssociatedTypeDescroptor(this);
					}
					~CustomTypeDescriptorImpl()
					{
						Description<DescriptableObject>::SetAssociatedTypeDescroptor(0);
					}
				protected:
					void LoadInternal()override
					{
					}
				};
			};

			BEGIN_CLASS_MEMBER(Sys)
				CLASS_MEMBER_STATIC_METHOD(Len, { L"value" })
				CLASS_MEMBER_STATIC_METHOD(Left, { L"value" _ L"length" })
				CLASS_MEMBER_STATIC_METHOD(Right, { L"value" _ L"length" })
				CLASS_MEMBER_STATIC_METHOD(Mid, { L"value" _ L"start" _ L"length" })
				CLASS_MEMBER_STATIC_METHOD(Find, { L"value" _ L"substr" })
				CLASS_MEMBER_STATIC_METHOD(UCase, { L"value" })
				CLASS_MEMBER_STATIC_METHOD(LCase, { L"value" })
				CLASS_MEMBER_STATIC_METHOD(LoremIpsumTitle, { L"bestLength" })
				CLASS_MEMBER_STATIC_METHOD(LoremIpsumSentence, { L"bestLength" })
				CLASS_MEMBER_STATIC_METHOD(LoremIpsumParagraph, { L"bestLength" })
				CLASS_MEMBER_STATIC_METHOD(ReverseEnumerable, { L"value" })
#pragma push_macro("CompareString")
#if defined CompareString
#undef CompareString
#endif
#define DEFINE_COMPARE(TYPE) CLASS_MEMBER_STATIC_METHOD_OVERLOAD(Compare, PROTECT_PARAMETERS({L"a" _ L"b"}), vint(*)(TYPE, TYPE))
				REFLECTION_PREDEFINED_PRIMITIVE_TYPES(DEFINE_COMPARE)
				DEFINE_COMPARE(DateTime)
#undef DEFINE_COMPARE
#pragma pop_macro("CompareString")

				CLASS_MEMBER_STATIC_METHOD(GetLocalTime, NO_PARAMETER)
				CLASS_MEMBER_STATIC_METHOD(GetUtcTime, NO_PARAMETER)
				CLASS_MEMBER_STATIC_METHOD(ToLocalTime, { L"dt" })
				CLASS_MEMBER_STATIC_METHOD(ToUtcTime, { L"dt" })
				CLASS_MEMBER_STATIC_METHOD(Forward, { L"dt" _ L"milliseconds" })
				CLASS_MEMBER_STATIC_METHOD(Backward, { L"dt" _ L"milliseconds" })

				CLASS_MEMBER_STATIC_METHOD_OVERLOAD(CreateDateTime, {L"year" _ L"month" _ L"day" }, DateTime(*)(vint, vint, vint))
				CLASS_MEMBER_STATIC_METHOD_OVERLOAD(CreateDateTime, { L"year" _ L"month" _ L"day" _ L"hour" _ L"minute" _ L"second" _ L"milliseconds" }, DateTime(*)(vint, vint, vint, vint, vint, vint, vint))
				CLASS_MEMBER_STATIC_METHOD_OVERLOAD(CreateDateTime, { L"filetime" }, DateTime(*)(vuint64_t))
			END_CLASS_MEMBER(Sys)

			BEGIN_CLASS_MEMBER(Math)
				CLASS_MEMBER_STATIC_METHOD(Pi, NO_PARAMETER)

				CLASS_MEMBER_STATIC_METHOD_OVERLOAD(Abs, { L"value" }, vint8_t(*)(vint8_t))
				CLASS_MEMBER_STATIC_METHOD_OVERLOAD(Abs, { L"value" }, vint16_t(*)(vint16_t))
				CLASS_MEMBER_STATIC_METHOD_OVERLOAD(Abs, { L"value" }, vint32_t(*)(vint32_t))
				CLASS_MEMBER_STATIC_METHOD_OVERLOAD(Abs, { L"value" }, vint64_t(*)(vint64_t))
				CLASS_MEMBER_STATIC_METHOD_OVERLOAD(Abs, { L"value" }, float(*)(float))
				CLASS_MEMBER_STATIC_METHOD_OVERLOAD(Abs, { L"value" }, double(*)(double))

#define DEFINE_MINMAX(TYPE)\
				CLASS_MEMBER_STATIC_METHOD_OVERLOAD(Min, PROTECT_PARAMETERS({L"a" _ L"b"}), TYPE(*)(TYPE, TYPE))\
				CLASS_MEMBER_STATIC_METHOD_OVERLOAD(Max, PROTECT_PARAMETERS({L"a" _ L"b"}), TYPE(*)(TYPE, TYPE))\

				REFLECTION_PREDEFINED_PRIMITIVE_TYPES(DEFINE_MINMAX)
				DEFINE_MINMAX(DateTime)
#undef DEFINE_MINMAX

				CLASS_MEMBER_STATIC_METHOD(Sin, { L"value" })
				CLASS_MEMBER_STATIC_METHOD(Cos, { L"value" })
				CLASS_MEMBER_STATIC_METHOD(Tan, { L"value" })
				CLASS_MEMBER_STATIC_METHOD(ASin, { L"value" })
				CLASS_MEMBER_STATIC_METHOD(ACos, { L"value" })
				CLASS_MEMBER_STATIC_METHOD(ATan, { L"value" })
				CLASS_MEMBER_STATIC_METHOD(ATan2, { L"x" _ L"y" })

				CLASS_MEMBER_STATIC_METHOD(Exp, { L"value" })
				CLASS_MEMBER_STATIC_METHOD(LogN, { L"value" })
				CLASS_MEMBER_STATIC_METHOD(Log10, { L"value" })
				CLASS_MEMBER_STATIC_METHOD(Log, { L"value" _ L"base" })
				CLASS_MEMBER_STATIC_METHOD(Pow, { L"value" _ L"power" })
				CLASS_MEMBER_STATIC_METHOD(Ceil, { L"value" })
				CLASS_MEMBER_STATIC_METHOD(Floor, { L"value" })
				CLASS_MEMBER_STATIC_METHOD(Round, { L"value" })
				CLASS_MEMBER_STATIC_METHOD(Trunc, { L"value" })
			END_CLASS_MEMBER(Math)

			BEGIN_CLASS_MEMBER(Localization)
				CLASS_MEMBER_STATIC_METHOD(Invariant, NO_PARAMETER)
				CLASS_MEMBER_STATIC_METHOD(System, NO_PARAMETER)
				CLASS_MEMBER_STATIC_METHOD(User, NO_PARAMETER)
				CLASS_MEMBER_STATIC_METHOD(Locales, NO_PARAMETER)

				CLASS_MEMBER_STATIC_METHOD(GetShortDateFormats, { L"locale" })
				CLASS_MEMBER_STATIC_METHOD(GetLongDateFormats, { L"locale" })
				CLASS_MEMBER_STATIC_METHOD(GetYearMonthDateFormats, { L"locale" })
				CLASS_MEMBER_STATIC_METHOD(GetLongTimeFormats, { L"locale" })
				CLASS_MEMBER_STATIC_METHOD(GetShortTimeFormats, { L"locale" })

				CLASS_MEMBER_STATIC_METHOD(GetShortDayOfWeekName, { L"locale" _ L"dayOfWeek" })
				CLASS_MEMBER_STATIC_METHOD(GetLongDayOfWeekName, { L"locale" _ L"dayOfWeek" })
				CLASS_MEMBER_STATIC_METHOD(GetShortMonthName, { L"locale" _ L"month" })
				CLASS_MEMBER_STATIC_METHOD(GetLongMonthName, { L"locale" _ L"month" })

				CLASS_MEMBER_STATIC_METHOD(FormatDate, { L"locale" _ L"format" _ L"date" })
				CLASS_MEMBER_STATIC_METHOD(FormatTime, { L"locale" _ L"format" _ L"date" })
				CLASS_MEMBER_STATIC_METHOD(FormatNumber, { L"locale" _ L"number" })
				CLASS_MEMBER_STATIC_METHOD(FormatCurrency, { L"locale" _ L"number" })
			END_CLASS_MEMBER(Localization)

			BEGIN_ENUM_ITEM(CoroutineStatus)
				ENUM_CLASS_ITEM(Waiting)
				ENUM_CLASS_ITEM(Executing)
				ENUM_CLASS_ITEM(Stopped)
			END_ENUM_ITEM(CoroutineStatus)

			BEGIN_INTERFACE_MEMBER(ICoroutine)
				CLASS_MEMBER_METHOD(Resume, { L"raiseException" _ L"output" })
				CLASS_MEMBER_PROPERTY_READONLY_FAST(Failure)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(Status)
			END_INTERFACE_MEMBER(ICoroutine)

			BEGIN_CLASS_MEMBER(CoroutineResult)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<CoroutineResult>(), NO_PARAMETER)
				CLASS_MEMBER_PROPERTY_FAST(Result)
				CLASS_MEMBER_PROPERTY_FAST(Failure)
			END_CLASS_MEMBER(CoroutineResult)

			BEGIN_INTERFACE_MEMBER_NOPROXY(EnumerableCoroutine::IImpl)
				CLASS_MEMBER_BASE(IValueEnumerator)
			END_INTERFACE_MEMBER(EnumerableCoroutine::IImpl)

			BEGIN_CLASS_MEMBER(EnumerableCoroutine)
				CLASS_MEMBER_STATIC_METHOD(YieldAndPause, { L"impl" _ L"value" })
				CLASS_MEMBER_STATIC_METHOD(JoinAndPause, { L"impl" _ L"value" })
				CLASS_MEMBER_STATIC_METHOD(ReturnAndExit, { L"impl" })
				CLASS_MEMBER_STATIC_METHOD(Create, { L"creator" })
			END_CLASS_MEMBER(EnumerableCoroutine)

			BEGIN_ENUM_ITEM(AsyncStatus)
				ENUM_CLASS_ITEM(Ready)
				ENUM_CLASS_ITEM(Executing)
				ENUM_CLASS_ITEM(Stopped)
			END_ENUM_ITEM(AsyncStatus)

			BEGIN_CLASS_MEMBER(AsyncContext)
				CLASS_MEMBER_CONSTRUCTOR(Ptr<AsyncContext>(const Value&), {L"context"})
				CLASS_MEMBER_METHOD(IsCancelled, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Cancel, NO_PARAMETER)
				CLASS_MEMBER_PROPERTY_FAST(Context)
			END_CLASS_MEMBER(AsyncContext)

			BEGIN_INTERFACE_MEMBER(IAsync)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(Status)
				CLASS_MEMBER_METHOD(Execute, { L"callback" _ L"context" })
				CLASS_MEMBER_STATIC_METHOD(Delay, { L"milliseconds" })
			END_INTERFACE_MEMBER(IAsync)

			BEGIN_INTERFACE_MEMBER_NOPROXY(IPromise)
				CLASS_MEMBER_METHOD(SendResult, { L"result" })
				CLASS_MEMBER_METHOD(SendFailure, { L"failure" })
			END_INTERFACE_MEMBER(IPromise)

			BEGIN_INTERFACE_MEMBER_NOPROXY(IFuture)
				CLASS_MEMBER_BASE(IAsync)
				CLASS_MEMBER_BASE(IPromise)
				CLASS_MEMBER_PROPERTY_READONLY_FAST(Promise)
				CLASS_MEMBER_STATIC_METHOD(Create, NO_PARAMETER)
			END_INTERFACE_MEMBER(IFuture)

			BEGIN_INTERFACE_MEMBER_NOPROXY(IAsyncScheduler)
				CLASS_MEMBER_METHOD(Execute, { L"callback" })
				CLASS_MEMBER_METHOD(ExecuteInBackground, { L"callback" })
				CLASS_MEMBER_METHOD(DelayExecute, { L"callback" _ L"milliseconds" })
				CLASS_MEMBER_STATIC_METHOD(GetSchedulerForCurrentThread, NO_PARAMETER)
			END_INTERFACE_MEMBER(IAsyncScheduler)

			BEGIN_INTERFACE_MEMBER_NOPROXY(AsyncCoroutine::IImpl)
				CLASS_MEMBER_BASE(IAsync)
			END_INTERFACE_MEMBER(AsyncCoroutine::IImpl)

			BEGIN_CLASS_MEMBER(AsyncCoroutine)
				CLASS_MEMBER_STATIC_METHOD(AwaitAndRead, { L"impl" _ L"value" })
				CLASS_MEMBER_STATIC_METHOD(ReturnAndExit, { L"impl" _ L"value"})
				CLASS_MEMBER_STATIC_METHOD(QueryContext, { L"impl" })
				CLASS_MEMBER_STATIC_METHOD(Create, { L"creator" })
				CLASS_MEMBER_STATIC_METHOD(CreateAndRun, { L"creator" })
			END_CLASS_MEMBER(AsyncCoroutine)

			BEGIN_CLASS_MEMBER(StateMachine)
				CLASS_MEMBER_FIELD(stateMachineInitialized)
				CLASS_MEMBER_FIELD(stateMachineStopped)
				CLASS_MEMBER_FIELD(stateMachineInput)
				CLASS_MEMBER_FIELD(stateMachineCoroutine)

				CLASS_MEMBER_CONSTRUCTOR(Ptr<StateMachine>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(ResumeStateMachine, NO_PARAMETER)

				CLASS_MEMBER_PROPERTY_READONLY_FAST(StateMachineStatus)
			END_CLASS_MEMBER(StateMachine)
#undef _

			class WfLibraryTypeLoader : public Object, public ITypeLoader
			{
			public:
				void Load(ITypeManager* manager)override
				{
					WORKFLOW_LIBRARY_TYPES(ADD_TYPE_INFO)
				}

				void Unload(ITypeManager* manager)override
				{
				}
			};

#endif

			bool WfLoadLibraryTypes()
			{
#ifndef VCZH_DEBUG_NO_REFLECTION
				ITypeManager* manager = GetGlobalTypeManager();
				if (manager)
				{
					Ptr<ITypeLoader> loader = new WfLibraryTypeLoader;
					return manager->AddTypeLoader(loader);
				}
#endif
				return false;
			}
		}
	}
}

