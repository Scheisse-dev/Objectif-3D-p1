#pragma once
template<typename T>
class Node
{
	private:
		Node* next = nullptr;
		Node* prev = nullptr; 
		T data = T(); 
	public:
		Node() = default; 
		Node(const T& _data, Node* _next = nullptr, Node* _prev = nullptr);
		Node* Next() const;
		Node* Prev() const; 
		T Data() const; 
		void SetNext(Node* _next);
		void SetPrev(Node* _prev);

		bool operator==(const T& _item); 
		operator T(); 

};

template<typename T>
inline Node<T>::Node(const T& _data, Node* _next, Node* _prev)
{
	next = _next;
	prev = _prev;
	data = _data;
}

template<typename T>
Node<T>* Node<T>::Next() const
{
	return next;
};

template<typename T>
Node<T>* Node<T>::Prev() const
{
	return prev;
}
template<typename T>
T Node<T>::Data() const
{
	return data;
}

template<typename T>
void Node<T>::SetNext(Node* _next)
{
	next = _next;
}

template<typename T>
void Node<T>::SetPrev(Node* _prev)
{
	prev = _prev;
}

template<typename T>
bool Node<T>::operator==(const T& _item)
{
	return data == _item;
}

template<typename T>
Node<T>::operator T()
{
	return data; 
}