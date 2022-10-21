#pragma once
#include "Object.h"


template<typename T>
class Singleton : public Object
{
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
public:
	virtual void OnDestroy() { }
	static T* Instance()
	{
		if (instance == nullptr)
			instance = new T();
		return instance;
	}
#pragma endregion methods
};