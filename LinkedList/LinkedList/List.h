#pragma once
#include <iostream>
#include <initializer_list>
#include "Node.h"


template<typename T>
class List
{
#pragma region f/p
private: 
	Node<T>* head = nullptr;
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;
	int count = 0; 

#pragma endregion f/p
#pragma region constructor
public: 
	List() = default;
	List(const std::initializer_list<T>& _tab);
	~List(); 
private: 
	Node<T>* Find(const T& _item);
#pragma endregion constructor
public: 
	void AddFirst(const T& _item);
	void AddLast(const T& _item); 
	void Clear();
	void Remove(const T& _item); 
	void RemoveFirst();
	void RemoveLast();
	bool Contains(const T& _item);
	void AddBefore(const T& _index, const T& _item);
	void AddAfter(const T& _index, const T& _item);
	void Display(); 
	int Count() const; 
	T& At(const int& _index); 
};

template<typename T>
List<T>::List(const std::initializer_list<T>& _tab)
{
	for (const T& _item : _tab)
		AddLast(_item); 
}
template<typename T>
List<T>::~List()
{
	count = 0;
	delete[] head;
	last = nullptr;
	first = nullptr;
	head = nullptr; 
}
#pragma endregion constructor


#pragma region methods

template<typename T>
Node<T>* List<T>::Find(const T& _item)
{
	Node<T>* _head = head;
	while (_head != nullptr)
	{
		if (*_head == _item) return _head;
	}
	return nullptr; 
}
template<typename T>
void List<T>::AddFirst(const T& _item)
{
	Node<T>* _newNode = new Node<T>(_item, nullptr, first);
	if (head == nullptr)
	{
		head = _newNode;
		first = _newNode;
		last = _newNode;
	}
	else
	{
		_newNode->SetNext(first);
		first->SetPrev(_newNode);
		head = first = _newNode; 

	}
	count++; 
}
template<typename T>
void List<T>::AddLast(const T& _item)
{
	if (head == nullptr)
	{
		AddFirst(_item);
		return;
	}
	Node<T>* _newNode = new Node<T>(_item, nullptr, last); 
	//_newNode->SetPrev(last); 
	last->SetNext(_newNode); 
	last = _newNode; 
	count++; 
}
template<typename T>
void List<T>::Clear()
{
	if (count == 0 || count == 1)
		delete head;
	else
		delete[] head;
	count = 0;
	last = nullptr;
	first = nullptr;
	head = nullptr;
}

template<typename T>
void List<T>::RemoveFirst()
{
	const Node<T>* _head = head; 
	head = _head ->Next();
	if (head != nullptr)
		head->SetPrev(nullptr);
	delete _head;
	count--;
	if (count == 0)
	{
		head = first = last = nullptr; 
	}
}
template<typename T>
void List<T>::RemoveLast()
{
	const Node<T>* _last = last;
	last = _last->Prev();
	if (head != nullptr)
		head->SetNext(nullptr);
	delete _last;
	count--;
	if (count == 0)
	{
		head = first = last = nullptr;
	}
}
template<typename T>
void List<T>::Remove(const T& _item)
{
	if (*first == _item)
	{
		RemoveFirst();
		return; 
	}
	if (*last == _item)
	{
		RemoveLast();
		return;
	}

	const Node<T>* _head = Find(_item);
	if (_head == nullptr) return; 
	_head->Prev()->SetNext(_head->Next()); 
	_head->Next()->SetPrev(_head->Prev()); 
	delete _head;
	count--; 
}

template<typename T>
bool List<T>::Contains(const T& _item)
{
	return Find(_item) != nullptr; 
}

template<typename T>
void List<T>::AddBefore(const T& _index, const T& _item)
{
	Node<T>* _head = Find(_index);
	if (_head == Find(_index))
		return;
	if (_head->Prev() == nullptr)
	{
		AddFirst(_item);
		return;
	}
	Node<T>* _newNode = new Node<T>(_item, _head, _head->Prev());
		_head->Prev()->SetNext(_newNode);
		_head->SetPrev(_newNode);
		count++;

}

template<typename T>
void List<T>::AddAfter(const T& _index, const T& _item)
{
	Node<T>* _head = Find(_index); 
	if (_head == nullptr) 
		return;
	if (_head->Next() == nullptr)
	{
		AddLast(_item);
		return; 
	}
	Node<T>* _newNode = new Node<T>(_item, _head->Next(), _head);
	_head->Next()->SetPrev(_newNode);
	_head->SetNext(_newNode);
	count++; 
}
template<typename T>
inline void List <T> ::Display()
{
	Node<T>* _head = head;
	while (_head != nullptr)
	{
		std::cout << _head->Data() << ", ";
		_head = _head->Next(); 
	}
	std::cout << std::endl; 
}

template<typename T>
inline int List<T>::Count() const
{
	return count; 
}
template<typename T>
T& List<T>::At(const int& _index)
{
	if (_index <0 || _index > count) throw std::out_of_range("out of range");
	Node<T>* _head = head; 
	for (int i = 0; i < _index&& _head->Next() != nullptr; i++)
	{
		_head = _head->Next(); 
	}
	return _head->Data(); 
}

#pragma endregion methods