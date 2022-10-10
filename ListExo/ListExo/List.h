#pragma once
using namespace std; 

template<typename T>
class List
{
private:
	int count = 0;

public:
	List(initializer_list<T> _tab)
	{
		tab = new T[]
	}
	void Display()
	{
		for (int i = 0; i < count; i++)
			std::cout << tab[i] << " ";
	}
	void Add(T* _index);
	void Remove(); 
	void RemoveAt(T _index);
	void RemoveAll();
	void Clear();
	void Contains(T _index);


};

template<typename T>
inline void List<T>::Add(T* _index)
{
	int _tail = 0;
	while( _tail < count)
	{
		_tail++;
	}
	tab[_tail] = _item;
	count++;
}

template<typename T>
inline void List<T>::Remove()
{
	count--; 
}

template<typename T>
inline void List<T>::RemoveAt(T _index)
{
}

template<typename T>
inline void List<T>::RemoveAll()
{
}

template<typename T>
inline void List<T>::Clear()
{
	delete[] tab;
	count = 0;
	tab = new tab[count];
	
}

template<typename T>
inline void List<T>::Contains(T _index)
{
}
