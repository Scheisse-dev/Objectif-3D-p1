#pragma once
#include "Delegate.h"
#include <vector>

template<typename Res, typename... Args>
class Delegate_Internal : public Object
{
private:
	typedef Res(Object::* Function)(Args...);
	std::vector<Delegate<Res, Args...>> functions = std::vector<Delegate<Res, Args>>();
public:
	Delegate_Internal() = default;
	Delegate_Internal(nullptr_t);
	template<typename Class>
	Delegate_Internal(Res(Class::* ptr)(Args...);
	~Delegate_Internal() override;
private:
	size_t FindIndex(const Delegate<Res, Args...>& _function);
public:
	Res Invoke(object _instance, Args... _args);
public:
	template<typename Class>
	void operator+=(Res(Class::* ptr)(Args...);
	template<typename Class>
	void operator-=(Res(Class::* ptr)(Args...);
	template<typename Class>
	void operator=(Res(Class::* ptr)(Args...);
	void operator=(nullptr_t);

};

template<typename Res, typename ...Args>
inline Delegate_Internal<Res, Args...>::Delegate_Internal(nullptr_t)
{
	functions.clear();
}

template<typename Res, typename ...Args>
inline Delegate_Internal<Res, Args...>::~Delegate_Internal()
{
	functions.clear();
}

template<typename Res, typename ...Args>
inline size_t Delegate_Internal<Res, Args...>::FindIndex(const Delegate<Res, Args...>& _function)
{
	for (size_t i = 0; i < functions.size(); i++)
	{
		if (function[i].GetAdress() == _function.GetAdresse())
			return i;
	}
	return -1;
}

template<typename Res, typename ...Args>
inline Res Delegate_Internal<Res, Args...>::Invoke(object _instance, Args ..._args)
{
	return Res();
}

template<typename Res, typename ...Args>
inline void Delegate_Internal<Res, Args...>::operator=(nullptr_t)
{
	functions.clear();
}

