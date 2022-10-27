//public:
//
//public:
//    void Invoke(, T _value)
//    {
//
//    }
//    template<typename Class>
//    Action& operator+=(void(Class::* _ptr)(T))
//    {
//       return (Class::*_ptr)(T);
//
//    }
//    template<typename Class>
//    Action& operator-=(void(Class::* _ptr)(T))
//    {
//
//        
//    }
//    template<typename Class>
//    Action& operator=(void(Class::* _ptr)(T))
//    {
//       Action<T> = T(Class::*_ptr) 
//    }

#pragma once
#include <vector>


class Object; 


template<typename T>
class Action
{
#pragma region f/p
private: 
	typedef void(Object::* Function)(T);
	std::vector<Function> functions = std::vector<Function>(); 
#pragma endregion f/p
#pragma region constructor/destructor
public: 
	Action(nullptr_t);
	template<typename Class>
	Action(void(Class::*_ptr)(T));
	~Action(); 
#pragma endregion constructor/destructor
#pragma region methods
public: 
	void Invoke(Object* _instance, T _value);

#pragma endregion methods 
#pragma region operator
public:
	template<typename Class>
	void operator+=(void(Class::* _ptr)(T));
	template<typename Class>
	void operator-=(void(Class::* _ptr)(T));
	template<typename Class>
	void operator=(void(Class::* _ptr)(T));
	void operator=(nullptr_t);
#pragma endregion operator
};

#pragma region constructor/destructor

template<typename T>
Action<T>::Action(nullptr_t)
{
	functions.clear(); 
}
template<typename T>
template<typename Class>
Action<T>::Action(void(Class::* _ptr)(T))
{
	functions.push_back(reinterpret_cast<Function>(_ptr)); 
}


template<typename T>
inline Action<T>::~Action()
{
	functions.clear(); 
}
#pragma endregion constructor/destructor
#pragma region methods
template<typename T>
inline void Action<T>::Invoke(Object* _instance, T _value)
{
	for (size_t i = 0; i < functions.size(); i++)
	{
		(_instance->*functions[i])(_value); 
	}
}

#pragma endregion methods 

#pragma region operator

template<typename T>
template<typename Class>
inline void Action<T>::operator+=(void(Class::* _ptr)(T))
{
	functions.push_back(reinterpret_cast<Function>(_ptr));
}

template<typename T>
template<typename Class>
inline void Action<T>::operator-=(void(Class::* _ptr)(T))
{
	Function _function = reinterpret_cast<Function>(_ptr);
	for (size_t i = 0; i < functions.size(); i++)
	{
		if (functions[i] == _function)
		{
			functions.erase(functions.begin() + i);
			return;
		}
	}
}

template<typename T>
template<typename Class>
inline void Action<T>::operator=(void(Class::* _ptr)(T))
{
	functions.clear();
	functions.push_back(reinterpret_cast<Function>(_ptr));
}

template<typename T>
inline void Action<T>::operator=(nullptr_t)
{
	functions.clear();
}
#pragma endregion operator
