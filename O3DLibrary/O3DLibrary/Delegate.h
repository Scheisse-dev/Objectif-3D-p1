#pragma once
#include "Object.h"
#include "Exception.h"

namespace Core
{
	namespace Event
	{
		template <typename Res, typename... Params>
		class O3DLIBRARY_API Delegate : public Object
		{
#pragma region f/p
		private:
			typedef Res(Object::* Function)(Params...);
			Function functionPtr = nullptr;
			Object* instance = nullptr; 
#pragma endregion f/p
#pragma region constructor
		public:
			Delegate(nullptr_t)
			{
				instance = nullptr;
				functionPtr = nullptr;
			}

#pragma endregion constructor
#pragma region methods
		public:
			template<typename Class>
			void SetDynamic(Class* _instance, Res(Class::* ptr)(Params...))
			{
				if (!std::is_base_of_v<Object, Class>)
					throw Exception("Class must be  inherited of Object");
				instance = _instance;
				functionPtr = reinterpret_cast<Function>(ptr); 
			}
			template<typename Class>
			void SetDynamic(nullptr_t, Res(Class::* ptr)(Params...))
			{
				if (!std::is_base_of_v<Object, Class>)
					throw Exception("Class must be  inherited of Object");
				instance = nullptr;
				functionPtr = nullptr;
			}

			Res Invoke(Params... _params)
			{
				if (instance == nullptr) throw Exception("instance is nullptr !");
				if (functionPtr == nullptr) throw Exception("function is nullptr !");
				return (instance->*functionPtr)(_params...);
			}

			void* GetAddress() const
			{
				return (void*&)functionPtr;
			}

#pragma endregion methods
#pragma region operator
		public:
			void operator=(nullptr_t)
			{
				instance = functionPtr = nullptr; 
			}
			bool operator==(const Delegate& _other)
			{
				return GetAddress() == _other.GetAddress();
			}
			bool operator !=(const Delegate& _other)
			{
				return !this->operator==(_other);
			}
			template<typename Class>
			bool operator==(Res(Class::* ptr)(Params...))
			{
				return GetAddress() == (void*&)ptr;
			}
			template<typename Class>
			bool operator!=(Res(Class::* ptr)(Params...))
			{
				return !this->operator==(ptr);
			}
			template<typename Class>
			bool operator==(Class _instance)
			{
				return instance == _instance; 
			}
			template<typename Class>
			bool operator!=(Class _instance)
			{
				return instance != _instance;
			}
#pragma endregion operator

		};
	}
}