#pragma once
#include <vector>
#include <cstddef>

//class Object;
//
//template <typename T, typename D, typename G>
//class Func
//{
//
//	typedef void(Object::* Function)(T);
//	std::vector<Function> functions = std::vector<Function>();
//
//
//	Func(nullptr_t);
//	template<typename Class>
//	Func(void(Class::* _ptr)(T));
//	~Func(); 
//
//	const int Invoke(D _index, G _value);
//
//
//};
//
//template<typename T, typename D, typename G>
//inline Func<T, D, G>::Func(nullptr_t)
//{
//	functions.clear();
//
//}
//
//template<typename T, typename D, typename G>
//template<typename Class>
//inline Func<T, D, G>::Func(void(Class::* _ptr)(T))
//{
//	functions.push_back(reinterpret_cast<Function>(_ptr));
//}
//
//
//template<typename T, typename D, typename G>
//inline Func<T, D, G>::~Func()
//{
//	functions.clear();
//}
//
//template<typename T, typename D, typename G>
//inline const int Func<T, D, G>::Invoke(D _index, G _value)
//{
//	T _result; 
//	for (size_t i = 0; i < functions.size(); i++)
//	{
//		_result = functions[i](_index, _value);
//	}
//
//	return _result;
//}



class Object;

template <typename Out, typename D, typename G>
class Func
{
	typedef Out(Object::* Function)(D, G);
	Function function = nullptr;

#pragma region constructor/destructor
public:
	Func(nullptr_t);
	template <typename Class>
	Func(Out(Class::* _ptr)(D, G));
	~Func();
#pragma endregion constructor/destructor
public:
	Out Invoke(Object* _instance, D _a, G _b);
public:
	void operator=(nullptr_t);
	template <typename Class>
	void operator=(Out(Class::* _ptr)(D, G);

};
#pragma region constructor/destructor
template<typename Out, typename D, typename G>
inline Func<Out, D, G>::Func(nullptr_t)
{
	function = nullptr; 
}

template<typename Out, typename D, typename G>
inline Func<Out, D, G>::~Func()
{
	delete function;
	function = nullptr;
}


template<typename Out, typename D, typename G>
template<typename Class>
inline Func<Out, D, G>::Func(Out(Class::* _ptr)(D, G))
{
	function = reinterpret_cast<Function>(_ptr);
}
#pragma endregion constructor/destructor
#pragma region methods
template<typename Out, typename D, typename G>
inline Out Func<Out, D, G>::Invoke(Object* _instance, D _a, G _b)
{
	return (_instance->*function)(_a; _b);
}


template<typename Out, typename D, typename G>
inline void Func<Out, D, G>::operator=(nullptr_t)
{
	function = nullptr;
}

template<typename Out, typename D, typename G>
template<typename Class>
inline void Func<Out, D, G>::operator=(Out(Class::* _ptr)(D, G))
{
	function = reinterpret_cast<Function>(_ptr);

}



#pragma endregion methods