#pragma once
#include <string>

#define UCLASS()

class Object
{
#pragma region constructor/destructor
public:
	Object() = default; 
	virtual ~Object() = default;
#pragma endregion constructor/destructor
#pragma region methods
public:
	virtual std::string ToString() const;
	template<typename T>
	T* GetInterface() const; 
#pragma endregion methods
};

template<typename T> 
inline T* Object::GetInterface() const
{
	return dynamic_cast<T*>(this);
}
