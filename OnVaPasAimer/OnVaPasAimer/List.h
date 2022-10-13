#pragma once
#include "Node.h"

template<typename T>
class List 
{
#pragma region f/p
public:  
	T* tree = nullptr; 
	int count = 0; 
#pragma endregion f/p
#pragma region constructor
public: 
	List() = default; 
	List(const List& _copy);
	~List(); 
#pragma endregion constructor
#pragma region methods
public: 
	void AddFirst(); 
	void AddLast(); 
	void AddAfter(); 
	void AddBefore(); 
	void Remove(); 
	void RemoveFirst();
	void RemoveLast(); 
	void Clear(); 
#pragma endregion methods

};

template<typename T>
inline void List<T>::Clear()
{
	delete tree; 
	count = 0; 
}

template<typename T>
inline List<T>::~List()
{
	Clear(); 
}
