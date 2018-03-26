﻿/***********************************************************************
THIS FILE IS AUTOMATICALLY GENERATED. DO NOT MODIFY
DEVELOPER: Zihan Chen(vczh)
***********************************************************************/
#include "Vlpp.h"

/***********************************************************************
.\WFLIBRARYCPPHELPER.H
***********************************************************************/
/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
Framework::Reflection

Interfaces:
***********************************************************************/

#ifndef VCZH_WORKFLOW_LIBRARY_CPPLIBRARY
#define VCZH_WORKFLOW_LIBRARY_CPPLIBRARY


namespace vl
{
	namespace __vwsn
	{
		template<typename T>
		struct RunOnExit
		{
			T* function;

			RunOnExit(T* _function)
				:function(_function)
			{
			}

			~RunOnExit()
			{
				function->operator()();
			}
		};

		template<typename T>
		T* This(T* thisValue)
		{
			CHECK_ERROR(thisValue != nullptr, L"The this pointer cannot be null.");
			return thisValue;
		}

		template<typename T>
		T* Ensure(T* pointer)
		{
			CHECK_ERROR(pointer != nullptr, L"The pointer cannot be null.");
			return pointer;
		}

		template<typename T>
		Ptr<T>& Ensure(Ptr<T>& pointer)
		{
			CHECK_ERROR(pointer != nullptr, L"The pointer cannot be null.");
			return pointer;
		}

		template<typename T>
		Ptr<T> Ensure(Ptr<T>&& pointer)
		{
			CHECK_ERROR(pointer != nullptr, L"The pointer cannot be null.");
			return MoveValue(pointer);
		}

		template<typename T>
		Nullable<T> Ensure(Nullable<T>&& nullable)
		{
			CHECK_ERROR(nullable, L"The pointer cannot be null.");
			return MoveValue(nullable);
		}

		template<typename T>
		Nullable<T>& Ensure(Nullable<T>& nullable)
		{
			CHECK_ERROR(nullable, L"The pointer cannot be null.");
			return nullable;
		}

		template<typename T>
		WString ToString(const T& value)
		{
			using Type = typename RemoveCVR<T>::Type;
			WString str;
			CHECK_ERROR(reflection::description::TypedValueSerializerProvider<T>::Serialize(value, str), L"Failed to serialize.");
			return str;
		}

		template<typename T>
		T Parse(const WString& str)
		{
			using Type = typename RemoveCVR<T>::Type;
			T value;
			CHECK_ERROR(reflection::description::TypedValueSerializerProvider<T>::Deserialize(str, value), L"Failed to serialize.");
			return value;
		}

		template<typename TTo, typename TFrom>
		struct NullableCastHelper
		{
			static Nullable<TTo> Cast(Nullable<TFrom> nullable)
			{
				return Nullable<TTo>(static_cast<TTo>(nullable.Value()));
			}
		};

		template<typename TFrom>
		struct NullableCastHelper<WString, TFrom>
		{
			static Nullable<WString> Cast(Nullable<TFrom> nullable)
			{
				return Nullable<WString>(ToString(nullable.Value()));
			}
		};

		template<typename TTo>
		struct NullableCastHelper<TTo, WString>
		{
			static Nullable<TTo> Cast(Nullable<WString> nullable)
			{
				return Nullable<TTo>(Parse<TTo>(nullable.Value()));
			}
		};

		template<typename TTo, typename TFrom>
		Nullable<TTo> NullableCast(Nullable<TFrom> nullable)
		{
			if (!nullable) return Nullable<TTo>();
			return NullableCastHelper<TTo, TFrom>::Cast(nullable);
		}

		template<typename TTo, typename TFrom>
		TTo* RawPtrCast(TFrom* pointer)
		{
			if (!pointer) return nullptr;
			return pointer->template SafeAggregationCast<TTo>();
		}

		template<typename TTo, typename TFrom>
		Ptr<TTo> SharedPtrCast(TFrom* pointer)
		{
			if (!pointer) return nullptr;
			return pointer->template SafeAggregationCast<TTo>();
		}

		template<typename T>
		reflection::description::Value Box(const T& value)
		{
			using Type = typename RemoveCVR<T>::Type;
			return reflection::description::BoxParameter<Type>(const_cast<T&>(value));
		}

		template<typename T>
		T Unbox(const reflection::description::Value& value)
		{
			using Type = typename RemoveCVR<T>::Type;
			T result;
			reflection::description::UnboxParameter<Type>(value, result);
			return result;
		}

		template<typename T>
		struct UnboxWeakHelper
		{
		};

		template<typename T>
		struct UnboxWeakHelper<T*>
		{
			static T* Unbox(const reflection::description::Value& value)
			{
				if (value.IsNull()) return nullptr;
				return value.GetRawPtr()->SafeAggregationCast<T>();
			}
		};

		template<typename T>
		struct UnboxWeakHelper<Ptr<T>>
		{
			static Ptr<T> Unbox(const reflection::description::Value& value)
			{
				if (value.IsNull()) return nullptr;
				return value.GetRawPtr()->SafeAggregationCast<T>();
			}
		};

		template<typename T>
		struct UnboxWeakHelper<Nullable<T>>
		{
			static Nullable<T> Unbox(const reflection::description::Value& value)
			{
				if (value.IsNull()) return Nullable<T>();
				auto boxed = value.GetBoxedValue().Cast<reflection::description::IValueType::TypedBox<T>>();
				if (!boxed) return Nullable<T>();
				return Nullable<T>(boxed->value);
			}
		};

		template<typename T>
		T UnboxWeak(const reflection::description::Value& value)
		{
			using Type = typename RemoveCVR<T>::Type;
			return UnboxWeakHelper<Type>::Unbox(value);
		}

		template<typename T>
		collections::LazyList<T> Range(T begin, T end)
		{
			return collections::Range<T>(begin, end - begin);
		}

		template<typename T>
		bool InSet(const T& value, const collections::LazyList<T>& collection)
		{
			return collection.Any([&](const T& element) {return element == value; });
		}

		template<typename T>
		bool InSet(const T& value, Ptr<reflection::description::IValueReadonlyList> collection)
		{
			return InSet<T>(value, reflection::description::GetLazyList<T>(collection));
		}

		template<typename T, typename U>
		Ptr<T> UnboxCollection(U& value)
		{
			auto boxedValue = reflection::description::BoxParameter<U>(value);
			Ptr<T> result;
			reflection::description::UnboxParameter<Ptr<T>>(boxedValue, result);
			return result;
		}

		template<typename T, typename U>
		Ptr<T> UnboxCollection(const collections::LazyList<U>& value)
		{
			auto boxedValue = reflection::description::BoxParameter<collections::LazyList<U>>(const_cast<collections::LazyList<U>&>(value));
			Ptr<T> result;
			reflection::description::UnboxParameter<Ptr<T>>(boxedValue, result);
			return result;
		}

		struct CreateList
		{
			using IValueList = reflection::description::IValueList;

			Ptr<IValueList>			list;

			CreateList();
			CreateList(Ptr<IValueList> _list);

			template<typename T>
			CreateList Add(const T& value)
			{
				list->Add(Box(value));
				return{ list };
			}
		};

		struct CreateObservableList
		{
			using IValueObservableList = reflection::description::IValueObservableList;

			Ptr<IValueObservableList>			list;

			CreateObservableList();
			CreateObservableList(Ptr<IValueObservableList> _list);

			template<typename T>
			CreateObservableList Add(const T& value)
			{
				list->Add(Box(value));
				return{ list };
			}
		};

		struct CreateDictionary
		{
			using IValueDictionary = reflection::description::IValueDictionary;

			Ptr<IValueDictionary>	dictionary;

			CreateDictionary();
			CreateDictionary(Ptr<IValueDictionary> _dictionary);

			template<typename K, typename V>
			CreateDictionary Add(const K& key, const V& value)
			{
				dictionary->Set(Box(key), Box(value));
				return{ dictionary };
			}
		};

		template<typename T>
		struct EventHelper
		{
		};

		template<typename T>
		Ptr<reflection::description::IEventHandler> EventAttach(T& e, typename EventHelper<T>::Handler handler)
		{
			return EventHelper<T>::Attach(e, handler);
		}

		template<typename T>
		bool EventDetach(T& e, Ptr<reflection::description::IEventHandler> handler)
		{
			return EventHelper<T>::Detach(e, handler);
		}

		template<typename T>
		decltype(auto) EventInvoke(T& e)
		{
			return EventHelper<T>::Invoke(e);
		}

		template<typename ...TArgs>
		struct EventHelper<Event<void(TArgs...)>>
		{
			using Handler = const Func<void(TArgs...)>&;

			class EventHandlerImpl : public Object, public reflection::description::IEventHandler
			{
			public:
				Ptr<EventHandler> handler;

				EventHandlerImpl(Ptr<EventHandler> _handler)
					:handler(_handler)
				{
				}

				bool IsAttached()override
				{
					return handler->IsAttached();
				}
			};

			static Ptr<reflection::description::IEventHandler> Attach(Event<void(TArgs...)>& e, Handler handler)
			{
				return MakePtr<EventHandlerImpl>(e.Add(handler));
			}

			static bool Detach(Event<void(TArgs...)>& e, Ptr<reflection::description::IEventHandler> handler)
			{
				auto impl = handler.Cast<EventHandlerImpl>();
				if (!impl) return false;
				return e.Remove(impl->handler);
			}

			static Event<void(TArgs...)>& Invoke(Event<void(TArgs...)>& e)
			{
				return e;
			}
		};
	}
}

#endif

/***********************************************************************
.\WFLIBRARYPREDEFINED.H
***********************************************************************/
/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
Framework::Reflection

Interfaces:
***********************************************************************/

#ifndef VCZH_WORKFLOW_LIBRARY_PREDEFINED
#define VCZH_WORKFLOW_LIBRARY_PREDEFINED

#include <math.h>

namespace vl
{
	namespace reflection
	{
		namespace description
		{

/***********************************************************************
Coroutine
***********************************************************************/

			enum class CoroutineStatus
			{
				Waiting,
				Executing,
				Stopped,
			};

			class CoroutineResult : public virtual IDescriptable, public Description<CoroutineResult>
			{
			protected:
				Value									result;
				Ptr<IValueException>					failure;

			public:
				Value									GetResult();
				void									SetResult(const Value& value);
				Ptr<IValueException>					GetFailure();
				void									SetFailure(Ptr<IValueException> value);
			};

			class ICoroutine : public virtual IDescriptable, public Description<ICoroutine>
			{
			public:
				virtual void							Resume(bool raiseException, Ptr<CoroutineResult> output) = 0;
				virtual Ptr<IValueException>			GetFailure() = 0;
				virtual CoroutineStatus					GetStatus() = 0;
			};

/***********************************************************************
Coroutine (Enumerable)
***********************************************************************/

			class EnumerableCoroutine : public Object, public Description<EnumerableCoroutine>
			{
			public:
				class IImpl : public virtual IValueEnumerator, public Description<IImpl>
				{
				public:
					virtual void						OnYield(const Value& value) = 0;
					virtual void						OnJoin(Ptr<IValueEnumerable> value) = 0;
				};

				typedef Func<Ptr<ICoroutine>(IImpl*)>	Creator;

				static void								YieldAndPause(IImpl* impl, const Value& value);
				static void								JoinAndPause(IImpl* impl, Ptr<IValueEnumerable> value);
				static void								ReturnAndExit(IImpl* impl);
				static Ptr<IValueEnumerable>			Create(const Creator& creator);
			};

/***********************************************************************
Coroutine (Async)
***********************************************************************/

			enum class AsyncStatus
			{
				Ready,
				Executing,
				Stopped,
			};

			class AsyncContext : public virtual IDescriptable, public Description<AsyncContext>
			{
			protected:
				SpinLock								lock;
				bool									cancelled = false;
				Value									context;

			public:
				AsyncContext(const Value& _context = {});
				~AsyncContext();

				bool									IsCancelled();
				bool									Cancel();

				const description::Value&				GetContext();
				void									SetContext(const description::Value& value);
			};

			class IAsync : public virtual IDescriptable, public Description<IAsync>
			{
			public:
				virtual AsyncStatus						GetStatus() = 0;
				virtual bool							Execute(const Func<void(Ptr<CoroutineResult>)>& callback, Ptr<AsyncContext> context = nullptr) = 0;

				static Ptr<IAsync>						Delay(vint milliseconds);
			};

			class IPromise : public virtual IDescriptable, public Description<IPromise>
			{
			public:
				virtual bool							SendResult(const Value& result) = 0;
				virtual bool							SendFailure(Ptr<IValueException> failure) = 0;
			};

			class IFuture : public virtual IAsync, public Description<IFuture>
			{
			public:
				virtual Ptr<IPromise>					GetPromise() = 0;

				static Ptr<IFuture>						Create();
			};

			class IAsyncScheduler : public virtual IDescriptable, public Description<IAsyncScheduler>
			{
			public:
				virtual void							Execute(const Func<void()>& callback) = 0;
				virtual void							ExecuteInBackground(const Func<void()>& callback) = 0;
				virtual void							DelayExecute(const Func<void()>& callback, vint milliseconds) = 0;

				static void								RegisterDefaultScheduler(Ptr<IAsyncScheduler> scheduler);
				static void								RegisterSchedulerForCurrentThread(Ptr<IAsyncScheduler> scheduler);
				static Ptr<IAsyncScheduler>				UnregisterDefaultScheduler();
				static Ptr<IAsyncScheduler>				UnregisterSchedulerForCurrentThread();
				static Ptr<IAsyncScheduler>				GetSchedulerForCurrentThread();
			};

			class AsyncCoroutine : public Object, public Description<AsyncCoroutine>
			{
			public:
				class IImpl : public virtual IAsync, public Description<IImpl>
				{
				public:
					virtual Ptr<IAsyncScheduler>		GetScheduler() = 0;
					virtual Ptr<AsyncContext>			GetContext() = 0;
					virtual void						OnContinue(Ptr<CoroutineResult> output) = 0;
					virtual void						OnReturn(const Value& value) = 0;
				};

				typedef Func<Ptr<ICoroutine>(IImpl*)>	Creator;

				static void								AwaitAndRead(IImpl* impl, Ptr<IAsync> value);
				static void								ReturnAndExit(IImpl* impl, const Value& value);
				static Ptr<AsyncContext>				QueryContext(IImpl* impl);
				static Ptr<IAsync>						Create(const Creator& creator);
				static void								CreateAndRun(const Creator& creator);
			};

/***********************************************************************
Coroutine (State Machine)
***********************************************************************/

			class StateMachine : public Object, public AggregatableDescription<StateMachine>
			{
#ifndef VCZH_DEBUG_NO_REFLECTION
				friend struct CustomTypeDescriptorSelector<StateMachine>;
#endif
			protected:
				bool									stateMachineInitialized = false;
				bool									stateMachineStopped = false;
				vint									stateMachineInput = -1;
				Ptr<ICoroutine>							stateMachineCoroutine;

				void									ResumeStateMachine();
			public:
				StateMachine();
				~StateMachine();

				CoroutineStatus							GetStateMachineStatus();
			};

/***********************************************************************
Libraries
***********************************************************************/

			class Sys : public Description<Sys>
			{
			public:
				static vint			Len(const WString& value)							{ return value.Length(); }
				static WString		Left(const WString& value, vint length)				{ return value.Left(length); }
				static WString		Right(const WString& value, vint length)			{ return value.Right(length); }
				static WString		Mid(const WString& value, vint start, vint length)	{ return value.Sub(start, length); }
				static vint			Find(const WString& value, const WString& substr)	{ return INVLOC.FindFirst(value, substr, Locale::Normalization::None).key; }
				static WString		UCase(const WString& value)							{ return wupper(value); }
				static WString		LCase(const WString& value)							{ return wlower(value); }

				static WString		LoremIpsumTitle(vint bestLength)					{ return vl::LoremIpsumTitle(bestLength); }
				static WString		LoremIpsumSentence(vint bestLength)					{ return vl::LoremIpsumSentence(bestLength); }
				static WString		LoremIpsumParagraph(vint bestLength)				{ return vl::LoremIpsumParagraph(bestLength); }

#define DEFINE_COMPARE(TYPE) static vint Compare(TYPE a, TYPE b);
				REFLECTION_PREDEFINED_PRIMITIVE_TYPES(DEFINE_COMPARE)
				DEFINE_COMPARE(DateTime)
#undef DEFINE_COMPARE

				static DateTime		GetLocalTime();
				static DateTime		GetUtcTime();
				static DateTime		ToLocalTime(DateTime dt);
				static DateTime		ToUtcTime(DateTime dt);
				static DateTime		Forward(DateTime dt, vuint64_t milliseconds);
				static DateTime		Backward(DateTime dt, vuint64_t milliseconds);
				static DateTime		CreateDateTime(vint year, vint month, vint day);
				static DateTime		CreateDateTime(vint year, vint month, vint day, vint hour, vint minute, vint second, vint milliseconds);
				static DateTime		CreateDateTime(vuint64_t filetime);

				static Ptr<IValueEnumerable>		ReverseEnumerable(Ptr<IValueEnumerable> value);
			};

			class Math : public Description<Math>
			{
			public:
				static double		Pi()							{ return ASin(1) * 2; }

				static vint8_t		Abs(vint8_t value)				{ return value > 0 ? value : -value; }
				static vint16_t		Abs(vint16_t value)				{ return value > 0 ? value : -value; }
				static vint32_t		Abs(vint32_t value)				{ return value > 0 ? value : -value; }
				static vint64_t		Abs(vint64_t value)				{ return value > 0 ? value : -value; }
				static float		Abs(float value)				{ return value > 0 ? value : -value; }
				static double		Abs(double value)				{ return value > 0 ? value : -value; }
				
#define DEFINE_MINMAX(TYPE)\
				static TYPE Min(TYPE a, TYPE b);\
				static TYPE Max(TYPE a, TYPE b);\

				REFLECTION_PREDEFINED_PRIMITIVE_TYPES(DEFINE_MINMAX)
				DEFINE_MINMAX(DateTime)
#undef DEFINE_MINMAX

				static double		Sin(double value)				{ return sin(value); }
				static double		Cos(double value)				{ return cos(value); }
				static double		Tan(double value)				{ return tan(value); }
				static double		ASin(double value)				{ return asin(value); }
				static double		ACos(double value)				{ return acos(value); }
				static double		ATan(double value)				{ return atan(value); }
				static double		ATan2(double x, double y)		{ return atan2(y, x); }

				static double		Exp(double value)				{ return exp(value);  }
				static double		LogN(double value)				{ return log(value); }
				static double		Log10(double value)				{ return log10(value); }
				static double		Log(double value, double base)	{ return log(value) / log(base); }
				static double		Pow(double value, double power)	{ return pow(value, power); }
				static double		Ceil(double value)				{ return ceil(value); }
				static double		Floor(double value)				{ return floor(value); }
				static double		Round(double value)				{ return round(value); }
				static double		Trunc(double value)				{ return trunc(value); }
			};
		}
	}
}

#endif


/***********************************************************************
.\WFLIBRARYREFLECTION.H
***********************************************************************/
/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
Framework::Reflection

Interfaces:
***********************************************************************/

#ifndef VCZH_WORKFLOW_LIBRARY_REFLECTION
#define VCZH_WORKFLOW_LIBRARY_REFLECTION


namespace vl
{
	namespace reflection
	{
		namespace description
		{

/***********************************************************************
Predefined Types
***********************************************************************/

#ifndef VCZH_DEBUG_NO_REFLECTION

#define WORKFLOW_LIBRARY_TYPES(F)\
			F(Sys)							\
			F(Math)							\
			F(CoroutineStatus)				\
			F(CoroutineResult)				\
			F(ICoroutine)					\
			F(EnumerableCoroutine::IImpl)	\
			F(EnumerableCoroutine)			\
			F(AsyncStatus)					\
			F(AsyncContext)					\
			F(IAsync)						\
			F(IPromise)						\
			F(IFuture)						\
			F(IAsyncScheduler)				\
			F(AsyncCoroutine::IImpl)		\
			F(AsyncCoroutine)				\
			F(StateMachine)					\

			WORKFLOW_LIBRARY_TYPES(DECL_TYPE_INFO)

#endif

/***********************************************************************
Interface Implementation Proxy (Implement)
***********************************************************************/

#ifndef VCZH_DEBUG_NO_REFLECTION

#pragma warning(push)
#pragma warning(disable:4250)

			BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(ICoroutine)

				void Resume(bool raiseException, Ptr<CoroutineResult> output)override
				{
					INVOKE_INTERFACE_PROXY(Resume, raiseException, output);
				}

				Ptr<IValueException> GetFailure()override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetFailure);
				}

				CoroutineStatus GetStatus()override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetStatus);
				}
			END_INTERFACE_PROXY(ICoroutine)

			BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(IAsync)

				AsyncStatus GetStatus()override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetStatus);
				}

				bool Execute(const Func<void(Ptr<CoroutineResult>)>& callback, Ptr<AsyncContext> context)override
				{
					INVOKEGET_INTERFACE_PROXY(Execute, callback, context);
				}
			END_INTERFACE_PROXY(IAsync)

#pragma warning(pop)

#endif

/***********************************************************************
LoadPredefinedTypes
***********************************************************************/

			extern bool										WfLoadLibraryTypes();
		}
	}
}

#endif

