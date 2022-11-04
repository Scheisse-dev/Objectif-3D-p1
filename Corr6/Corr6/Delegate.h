#pragma once
#include "Object.h"
#include <string>

template<typename Res, typename... Args>
class Delegate : public Object
{
private:
	typedef Res(Object::* Function)(Args...);
	Function function = nullptr;
public: 
	Delegate() = default;
	template<typename Class>
	Delegate(Res(Class::* ptr)(Args...));
	template<typename Class>
	Delegate(Res(Class::* ptr)(Args...));
	~Delegate() override;
public:
	Res Invoke(object _instance, Args... _args);
	void* GetAdresse();
public:
	void operator=(nullptr_t);

};

template<typename Res, typename ...Args>
template<typename Class>
inline Delegate<Res, Args...>::Delegate(Res(Class::* ptr)(Args...))
{
	fonction = reinterpret_cast<Function>(ptr);
}

template<typename Res, typename ...Args>
inline Delegate<Res, Args...>::~Delegate()
{
}

template<typename Res, typename ...Args>
inline Res Delegate<Res, Args...>::Invoke(object _instance, Args ..._args)
{
	return Res();
}

template<typename Res, typename ...Args>
inline void* Delegate<Res, Args...>::GetAdresse()
{
	return nullptr;
}

template<typename Res, typename ...Args>
template<typename Class>
inline Delegate<Res, Args...>::Delegate(Res(Class::* ptr)(Args...))
{
}

template<typename Res, typename ...Args>
template<typename Class>
inline void Delegate<Res, Args...>::operator=(Res(Class::* ptr)(Args...))
{
	fonction = reinterpret_cast<Function>(ptr);
}