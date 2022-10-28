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




template<typename... Args>
class Action
{
#pragma region f/p
private: 
	typedef void(Object::* Function)(Args...);
	std::vector<Function> functions = std::vector<Function>(); 
#pragma endregion f/p
#pragma region constructor/destructor
public: 
	Action(nullptr_t);
	template<typename Class>
	Action(void(Class::*_ptr)(Args...));
	~Action(); 
#pragma endregion constructor/destructor
#pragma region methods
public: 
	void Invoke(Object* _instance, Args... _value);

#pragma endregion methods 
#pragma region operator
public:
	template<typename Class>
	void operator+=(void(Class::* _ptr)(Args...));
	template<typename Class>
	void operator-=(void(Class::* _ptr)(Args...));
	template<typename Class>
	void operator=(void(Class::* _ptr)(Args...));
	void operator=(nullptr_t);
#pragma endregion operator
};

#pragma region constructor/destructor

template<typename... Args>
Action<Args...>::Action(nullptr_t)
{
	functions.clear(); 
}
template<typename... Args>
template<typename Class>
Action<Args...>::Action(void(Class::* _ptr)(Args...))
{
	functions.push_back(reinterpret_cast<Function>(_ptr)); 
}


template<typename... Args>
inline Action<Args...>::~Action()
{
	functions.clear(); 
}
#pragma endregion constructor/destructor
#pragma region methods
template<typename... Args>
inline void Action<Args...>::Invoke(Object* _instance, Args... _value)
{
	for (size_t i = 0; i < functions.size(); i++)
	{
		(_instance->*functions[i])(_value...); 
	}
}

#pragma endregion methods 

#pragma region operator

template<typename... Args>
template<typename Class>
inline void Action<Args...>::operator+=(void(Class::* _ptr)(Args...))
{
	functions.push_back(reinterpret_cast<Function>(_ptr));
}

template<typename... Args>
template<typename Class>
inline void Action<Args...>::operator-=(void(Class::* _ptr)(Args...))
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

template<typename... Args>
template<typename Class>
inline void Action<Args...>::operator=(void(Class::* _ptr)(Args...))
{
	functions.clear();
	functions.push_back(reinterpret_cast<Function>(_ptr));
}

template<typename... Args>
inline void Action<Args...>::operator=(nullptr_t)
{
	functions.clear();
}
#pragma endregion operator
