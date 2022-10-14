#pragma once
#include <iostream>
#include <initializer_list>
#include <string>
template<typename T>
class Invent
{
private: 
	T* invent = nullptr; 
	int objectNum = 0; 
	int numPopo = 0; 
public: 
	Invent();
	Invent(std::initializer_list<T> _invent);
	Invent(const T& _copy);
	~Invent(); 
	void Add(const T& _item);
	bool UsePotion(); 
	void Display(); 

};

#pragma region constructor

template<typename T>
Invent<T>::Invent()
{
	invent = new T[0];
	objectNum = 0; 
}

template<typename T>
inline Invent<T>::Invent(std::initializer_list<T> _invent)
{
	objectNum = _invent.size(); 
}

template<typename T>
inline Invent<T>::Invent(const T& _copy)
{
	for (int i = 0; i < objectNum; i++)
		Add(_copy.invent[i]); 
}

template<typename T>
inline Invent<T>::~Invent()
{
	delete[] invent;
	objectNum = 0;
	invent = new T[0];

}
#pragma endregion constructor
template<typename T>
inline void Invent<T>::Add(const T& _item)
{
	// if _item = int -> string
	T* _invent = invent; 
	for (int i = 0; i < objectNum; i++)
	{
		if (_item == _tolower("popo") && _invent[i] == "popo") numPopo++;

	}
		T* _tmp = invent;
		invent = new T[objectNum + 1];
		for (int i = 0; i < objectNum; i++)
			invent[i] = _tmp[i];
		invent[objectNum] = _item;
		objectNum++;
		for (int i = 0; i < objectNum; i++) {
			if (_item == _tolower("popo") && _invent[i] == "popo")
			{
				_tmp = invent;
				invent = new T[objectNum - 1];
				for (int i = 0; i < objectNum; i++)
					invent[i] = _tmp[i];
				objectNum--;
			}
		}


}

template<typename T>
inline bool Invent<T>::UsePotion()
{
	return true; 
}

template<typename T>
inline void Invent<T>::Display()
{
	for (int i = 0; i < objectNum; i++)
	{
		if (invent[i]== _tolower("popo"))
			std::cout << invent[i] << numPopo << std::endl;
		std::cout << invent[i] << std::endl;
	}

}
