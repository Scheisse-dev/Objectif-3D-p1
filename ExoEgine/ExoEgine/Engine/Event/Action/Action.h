#pragma once
#include "../Delegate/Delegate.h"
#include <vector>

namespace Engine::Event
{
	template <typename Res, typename... Params>
	class Action : public Object
	{
		DECLARE_CLASS_INFO(Action, Object)
#pragma region f/p
		std::vector<Delegate<Res, Params...>> delegates = std::vector<Delegate<Res, Params...>>();
#pragma endregion f/p
#pragma region constructor
		Action(nullptr_t)
		{
			delegates.clear();
		}
		template<typename Class>
		Action(Class* _instance, Res(Class::*ptr)(Params...))
		{
			checkBaseOf(Object, Class)
			delegates.push_back(Delegate<Res, Params...>(_instance, ptr));
		}
#pragma endregion constructor
#pragma region methods
		template <typename Class>
		void AddDynamic(Class* _instance, Res(Class::*ptr)(Params...))
		{
			checkBaseOf(Object, Class)
				delegates.push_back(Delegate<Res, Params...>(_instance, ptr));
		}
		template <typename Class>
		void RemoveDynamic(Class* _instance, Res(Class::* ptr)(Params...))
		{
			checkBaseOf(Object, Class)
			typename std::vector<Delegate<Res, Params...>>::iterator it = delegates.begin();
			for (; it != delegates.end(); it++)
			{
				if (*it.GetAdresse() == (void*&)ptr && *it.Instance() == _instance)
				{
					delegates.erase(it);
					break;
				}
			}
		}
		Res Invoke(Params... _params)
		{
			if constexpr (std::is_same_v<Res, void>)
			{
				for (Delegate<Res, Params...> _delegate : delegates)
					_delegate.Invoke(_params...);
				return Res();
			}
			else
			{
				Res _result = Res();
				for (Delegate<Res, Params...> _delegate : delegates)
					_result = _delegate.Invoke(_params...);
				return _result;
			}
		}

#pragma endregion methods

#pragma region operator
		Action& operator=(nullptr_t)
		{
			delegates.clear();
		}
		Action& operator=(const Action& _other)
		{
			delegates = _other.delegates;
			return *this;
		}
#pragma endregion operator
	};
}

template<typename... Params>
using Action = Engine::Event::Action<void, Params...>;
template<typename T, typename... Params>
using Func = Engine::Event::Action<T, Params...>;
template<typename... Params>
using Predicate = Engine::Event::Action<bool, Params...>;