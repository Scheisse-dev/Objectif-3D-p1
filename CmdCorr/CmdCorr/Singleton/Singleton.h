#pragma once
#include "../Object/Object.h"

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
	~Singleton()
	{
		OnDestroy(); 
		delete instance;
	}
#pragma endregion constructor/destructor
#pragma region methods
public: 
	static inline T* Instance()
	{
		if (instance == nullptr)
			instance = new T(); 
		return instance;
	}
protected: 
	virtual void OnDestroy()
	{

	}
#pragma endregion methods
};