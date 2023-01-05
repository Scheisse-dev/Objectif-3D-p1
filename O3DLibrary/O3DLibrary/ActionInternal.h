#pragma once
#include "Delegate.h"
#include <vector>
namespace Core
{
	namespace Event
	{
		template<typename Res, typename... Params>
		class O3DLIBRARY_API ActionInternal : public Object
		{
#pragma region f/p
		private:
			std::vector<Delegate<Res, Params...>> delegates = std::vector<Delegate<Res, Params...>>();
#pragma endregion f/p
#pragma region constructor
		public:
			ActionInternal(nullptr_t) {}
#pragma endregion constructor
#pragma region methods
		public:
			template<typename Class>
			void AddDynamic(Class* _instance, Res(Class::* ptr)(Params...))
			{
				if constexpr (!std::is_base_of_v<Object, Class>)
					throw Exception("Class must be inherited of Object");
				Delegate<Res, Params...> _delegate = nullptr;
				_delegate.SetDynamic(_instance, ptr); 
				delegates.push_back(_delegate);
			}

			template<typename Class>
			void RemoveDynamic(Class* _instance, Res(Class::* ptr)(Params...))
			{
				const size_t _size = delegates.size(); 
				for (size_t i = 0; i < _size; i++)
				{
					if (delegates[i] == ptr && delegates[i] == _instance)
					{
						delegates.erase(delegates.begin() + i);
						break;
					}
				}
			}
			Res Invoke(Params... _params)
			{
					if (delegates.empty()) return Res();
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
		public:
			void operator=(nullptr_t)
			{
				delegates.clear();
			}
			bool operator==(const ActionInternal& _other)
			{
				const size_t _size = delegates.size();
				if (_size != _other.delegates.size()) return false;
				for (size_t i = 0; i < _size; i++)
				{
					if (delegates[i] != _other.delegates[i])
						return false;
				}
				return true;
			}
			bool operator!=(const ActionInternal& _other)
			{
				return !this->operator==(_other);
			}
#pragma endregion operator

		};

	}
}
template<typename... Params>
using Action = Core::Event::ActionInternal<void, Params...>;

template<typename Out, typename... Params>
using Func = Core::Event::ActionInternal<Out, Params...>;

template<typename... Params>
using Predicate = Core::Event::ActionInternal<bool, Params...>;