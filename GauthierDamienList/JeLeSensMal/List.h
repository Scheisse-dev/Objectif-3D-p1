#pragma once

template<typename T>
class List
{
private: 
	int count = 0; 
	T* tab = nullptr;

public: 
	List();
	~List(); 
	void Clear();
	void Add(const T& _item); 
	void Remove(); 
	void RemoveAll(); 
	void RemoveAt(const T& _item);
	int FindOf(const T& _item);
	bool Contains(const T& _item);
	

};





template<typename T>
inline List<T>::~List()
{
}

template<typename T>
inline void List<T>::Clear()
{
	if (tab == nullptr)
		delete tab;
	else
		delete[]tab;
	count = 0;
	tab = new T[count];

}

template<typename T>
inline void List<T>::Add(const T& _item)
{
	tab = new T[count + 1];
	for (int i = 0; i < count; i++)
	{
		if (tab[i] = nullptr)
			tab[i] = _item; 
	}
	count++; 


}

template<typename T>
inline void List<T>::Remove()
{

}

template<typename T>
inline void List<T>::RemoveAll()
{

}

template<typename T>
inline void List<T>::RemoveAt(const T& _item)
{
}

template<typename T>
inline int List<T>::FindOf(const T& _item)
{
	for (int i = 0; i < count; i++)
	{
		if (i == _item)
			return i;
	}
	return -1; 
}

template<typename T>
inline bool List<T>::Contains(const T& _item)
{
	return FindOf(_item);
}
