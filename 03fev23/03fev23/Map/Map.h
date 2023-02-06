#pragma once
#include "KeyValuePair/KeyValuePair.h"

template <typename IKey, typename IValue>
class Map
{
#pragma region f/p
	KeyValuePair<IKey, IValue>* pair = nullptr;
#pragma endregion f/p
public:
	Map(IKey _key, IValue _value)
	{
		pair = new KeyValuePair<IKey, IValue>(_key, _value);
	}
	~Map()
	{
		Clear();
	}
#pragma region methods
	//Clear, count, begin, end , Insert, find, 

	void Clear()
	{
		delete pair; 
		pair = nullptr; 		
	}
	void Insert(IKey _key, IValue _value)
	{
		pair->Insert(_key, _value); 
	}
	int Count()
	{
		return pair->Index();
	}
	int Begin()
	{
		//return pair[0];
	}
	int End()
	{
		//return pair[pair.Index()]
	}
	IValue Find(IKey _key)
	{
		pair->GetValue(_key);
	}

#pragma endregion methods
#pragma region operator
public:

#pragma endregion operator

};

