#pragma once
template <typename T>
class Node
{
#pragma region f/p 
	T* next = nullptr; 
	T* prev = nullptr;
	T* list = nullptr; 
#pragma endregion f/p
#pragma region methods
	void Next(const T& _next); 
	void Prev(const T& _prev); 
	void SetNext(const T& _prev,const T& _next, const T& _index);
	void SetPrev(const T& _prev, const T& _next, const T& _index);
#pragma endregion methods

};


template<typename T>
inline void Node<T>::Next(const T& _next)
{
	next = _next; 
}

template<typename T>
inline void Node<T>::Prev(const T& _prev)
{
	prev = _prev; 
}

template<typename T>
inline void Node<T>::SetNext(const T& _next, const T& _prev, const T& _index)
{
	const T _tmp = new Node(T); 
 
		
	delete _tmp; 
}

template<typename T>
inline void Node<T>::SetPrev(const T& _prev, const T& _next, const T& _index)
{
	const T _tmp = new Node(T);


	delete _tmp; 
}
