#pragma once
#include <initializer_list>
#include <exception>
#include "KeyValuePai.h"


//std::map
// At
// operator[]
// clear
// empty (dit si la liste est vide) 
// insert
// Remove
// Contains
//

template <typename Tkey, typename Tvalue>
class Map
{
#pragma region f/p
private: 
	KeyValuePair<Tkey, Tvalue>* tab = new KeyValuePair<Tkey, Tvalue>[0]; 
	int count = 0;

#pragma endregion f/p
#pragma region typedef
public: 
	typedef KeyValuePair<Tkey, Tvalue>* iterator; 
	typedef const KeyValuePair<Tkey, Tvalue>* const_iterator;

	iterator begin()
	{
		return &tab[0]; 
	}
	const_iterator begin() const
	{
		return &tab[0];
	}
	iterator end()
	{
		return &tab[count];
	}
	const_iterator end() const
	{
		return &tab[count];
	}
#pragma endregion typedef
#pragma region constructor/destructor
public: 
	Map() = default; 
	Map(std::initializer_list<KeyValuePair<Tkey, Tvalue>> _tab);
	Map(const Map& _copy);
	~Map(); 

#pragma endregion constructor/destructor
#pragma region methods
private: 
	int IndexOfKey(const Tkey& _key) const; 
public: 
	void Insert(const Tkey& _key, const Tvalue& _value); 
	void Insert(const KeyValuePair<Tkey, Tvalue>& _pair); 
	void Clear();
	void Remove(const Tkey& _key); 
	bool IsEmpty() const; 
	bool Contains(const Tkey& _key);
	Tvalue& At(const Tkey& _key);
	
#pragma endregion methods
#pragma region operator
public: 
	Tvalue& operator[] (const Tkey& _key); 
	// Tvalue operator[] (const TKey& _key) const; surcharge 
#pragma endregion operator
};

#pragma region constructor/destructor

template<typename Tkey, typename Tvalue>
inline Map<Tkey, Tvalue>::Map(std::initializer_list<KeyValuePair<Tkey, Tvalue>> _tab)
{
	for (KeyValuePair<Tkey, Tvalue> _pair : _tab)
		Insert(_pair); 
}

template<typename Tkey, typename Tvalue>
inline Map<Tkey, Tvalue>::Map(const Map& _copy)
{
	tab = _copy.tab; 
	count = _copy.count; 
}

template<typename Tkey, typename Tvalue>
inline Map<Tkey, Tvalue>::~Map()
{
	delete[] tab;
	count = 0;
	tab = new KeyValuePair<Tkey, Tvalue>[0];
}

#pragma endregion constructor/destructor

#pragma region methods
template<typename Tkey, typename Tvalue>
inline int Map<Tkey, Tvalue>::IndexOfKey(const Tkey& _key) const
{
	for (int i = 0; i < count; i++)
	{
		if (tab[i].Key() == _key)
			return i; 
	}
	return -1;
}
template<typename Tkey, typename Tvalue>
inline void Map<Tkey, Tvalue>::Insert(const Tkey& _key, const Tvalue& _value)
{
	Insert(KeyValuePair<Tkey, Tvalue>(_key, _value)); 
}
template<typename Tkey, typename Tvalue>
inline void Map<Tkey, Tvalue>::Insert(const KeyValuePair<Tkey, Tvalue>& _pair)
{
	if (Contains(_pair.Key()))
		throw std::exception("key already exist"); 
	KeyValuePair<Tkey, Tvalue>* _tmp = tab; 
	tab = new KeyValuePair<Tkey, Tvalue>[count + 1];
	for (int i = 0; i < count; i++)
		tab[i] = _tmp[i];
	tab[count] = _pair; 
	count++; 
}
template<typename Tkey, typename Tvalue>
inline void Map<Tkey, Tvalue>::Clear()
{
	delete[] tab;
	count = 0; 
	tab = new KeyValuePair<Tkey, Tvalue>[0]; 
}
template<typename Tkey, typename Tvalue>
inline void Map<Tkey, Tvalue>::Remove(const Tkey& _key)
{
	const int _index = IndexOfKey(_key);
	if (_index == -1) throw std::exception("key doesn't exist ! "); 
	KeyValuePair<Tkey, Tvalue>* _tmp = tab; 
	tab = new KeyValuePair<Tkey, Tvalue>[count - 1]; 
	for (int i = 0; i < _index; i++)
		tab[i] = _tmp[i];
	for (int i = 0; i < _index; i++)
		tab[i-1] = _tmp[i];
	count--; 
}
template<typename Tkey, typename Tvalue>
inline bool Map<Tkey, Tvalue>::IsEmpty() const
{
	return count == 0; 
	
}
template<typename Tkey, typename Tvalue>
inline bool Map<Tkey, Tvalue>::Contains(const Tkey& _key)
{
	return IndexOfKey(_key) != -1; 
}
template<typename Tkey, typename Tvalue>
inline Tvalue& Map<Tkey, Tvalue>::At(const Tkey& _key)
{
	const int _index = IndexOfKey(_key); 
	if (_index == -1) throw std::exception("key doesn't exist");
	return tab[_index].Value(); 
}


#pragma endregion methods
#pragma region operator
template<typename Tkey, typename Tvalue>
inline Tvalue& Map<Tkey, Tvalue>::operator[](const Tkey& _key)
{
	return At(_key); 
}

#pragma endregion operator