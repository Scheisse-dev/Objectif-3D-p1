#pragma once
template<typename T>
class Node
{
	private:
		Node* next = nullptr; //nouveau pointeur
		Node* prev = nullptr; 
		T data = T(); // nouveau template de data = template, donc une valeur sans type
#pragma region constructor
	public:
		Node() = default;
		Node(const T& _data, Node* _next = nullptr, Node* _prev = nullptr);
		Node* Next() const;
		Node* Prev() const; 
		T& Data(); 
		void SetNext(Node* _next);
		void SetPrev(Node* _prev);

		bool operator==(const T& _item); 
		operator T(); 

};
#pragma endregion constructor

template<typename T>
inline Node<T>::Node(const T& _data, Node* _next, Node* _prev) // inline permet de réduire l'impact des appels de fonction 
															   // Node<T> appel de la classe Node avec un template 
															   //const T& _data déclaration d'une constante data prenant le template comme type 
															   // Node* _prev, déclaration d'un noveau pointeur pour attribuer les copies
{
	next = _next; //création de copies 
	prev = _prev;
	data = _data;
}

template<typename T>
Node<T>* Node<T>::Next() const // Node<T> appel le constructeur de la classe node; 
{
	return next;
};

template<typename T>
Node<T>* Node<T>::Prev() const
{
	return prev;
}
template<typename T>
T& Node<T>::Data()
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