#pragma once

template < typename Tkey, typename Tvalue> 
class KeyValuePair
{
#pragma region f/p
private : 
	Tkey key = Tkey(); 
	Tvalue value = Tvalue(); 
#pragma endregion f/p
#pragma region constructor
public: 
	KeyValuePair() = default;
	KeyValuePair(Tkey _key, Tvalue _value);
	KeyValuePair(const KeyValuePair& _copy); 
#pragma endregion constructor
#pragma region methods
public: 
	Tkey Key() const; 
	Tvalue& Value(); 
#pragma endregion methods
};

#pragma region constructor
template<typename Tkey, typename Tvalue>
inline KeyValuePair<Tkey, Tvalue>::KeyValuePair(Tkey _key, Tvalue _value)
{
	key = _key; 
	value = _value; 
}

template<typename Tkey, typename Tvalue>
inline KeyValuePair<Tkey, Tvalue>::KeyValuePair(const KeyValuePair& _copy)
{
	key = _copy.key;
	value = _copy.value; 
}
#pragma endregion constructor
#pragma region methods
template<typename Tkey, typename Tvalue>
inline Tkey KeyValuePair<Tkey, Tvalue>::Key() const
{
	return key;
}

template<typename Tkey, typename Tvalue>
inline Tvalue& KeyValuePair<Tkey, Tvalue>::Value()
{
	return value;
}
#pragma endregion methods