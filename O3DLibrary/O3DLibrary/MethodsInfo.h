#pragma once
#include "O3DLibrary.h"
#include "ParameterInfo.h"
#include <exception>
#include <vector>
namespace Core
{
	class Object;
#pragma warning(disable: 4251)

	class O3DLIBRARY_API BaseMethodInfo
	{
	public:
		virtual ~BaseMethodInfo() = default;
	};

	template<typename Result, typename... Params>
	class O3DLIBRARY_API MethodInfo : public BaseMethodInfo
	{
#pragma region f/p
	private:
		std::vector<ParameterInfo> params = std::vector<ParameterInfo>();
		typedef Result(Object::* Function)(Params...);
		Function functionPtr = nullptr;
		Object* instance = nullptr;
#pragma endregion f/p
#pragma region constructor
	public:
		MethodInfo() = default;
		template<class Class>
		MethodInfo(Class* _instance, Result(Class::* ptr)(Params...),
			std::vector<ParameterInfo> _params = {})
		{
			instance = _instance;
			functionPtr = reinterpret_cast<Function>(ptr);
			params = _params;
		}
#pragma region constructor
#pragma region methods
	public:
		std::vector<ParameterInfo> Parameters() const
		{
			return params;
		}
		Result Invoke(Params... _params)
		{
			if (functionPtr == nullptr)
				throw std::exception("function is null !");
			if (instance == nullptr)
				throw std::exception("instance is null !");
			return (instance->*functionPtr)(_params...);
		}

		void* GetAddress()
		{
			return (void*&)functionPtr;
		}
#pragma endregion methods
	};
}
