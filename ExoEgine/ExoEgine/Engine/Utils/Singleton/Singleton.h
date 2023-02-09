#pragma once
#include "../../Object/Object.h"

namespace Engine::Utils
{
	template<typename T>
	class Singleton : public Object
	{
		DECLARE_CLASS_INFO(Singleton, Object)
#pragma region f/p
	private:
		static inline T* instance = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
	public:
		Singleton() = default; 
		~Singleton() override
		{
			OnDestroy();
		}
#pragma endregion constructor/destructor
#pragma region methods
		static T* Instance()
		{
			if (instance == nullptr) instance = new T();
			return instance; 
		}
		void Destroy()
		{
			delete instance;
			instance = nullptr;
		}
		virtual void OnDestroy() {}
#pragma endregion methods
	};

}

template<typename T>
Engine::Utils::Singleton<T>::Singleton(const Singleton& _copy)
{
	instance = _copy.instance;
}