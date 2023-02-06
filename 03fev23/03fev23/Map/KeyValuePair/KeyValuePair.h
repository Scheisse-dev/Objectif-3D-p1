#pragma once
#include <initializer_list>


template <typename Key, typename Value>
class KeyValuePair
{
#pragma region f/p 
private: 
	int index = 0;
	std::initializer_list<Key>* LKey = nullptr;
	std::initializer_list<Value>* LValue = nullptr;
#pragma endregion f/p
#pragma region constructor
public: 
	KeyValuePair() = default; 
	KeyValuePair(Key _key, Value _value)
	{
		index = 0; 
		LKey = new std::initializer_list<Key>();
		LValue = new std::initializer_list<Value>();
	}
#pragma region constructor
#pragma region methods
public:
	void Insert(Key _key, Value _value)
	{
		LKey[index] = _key;
		LValue[index] = _value;
		index++;
	}
	int Index()
	{
		return index;
	}
	Key GetKey(int _index)
	{
		return LKey[_index]; 
	}
	Value GetValue(Key _key)
	{
		int temp = 0;
		for (int i = 0; i < LKey->size(); i++)
		{
			if (LKey[i] == _key)
				temp = i;
				
		}
		return LValue[temp];
	}
#pragma endregion methods

};

