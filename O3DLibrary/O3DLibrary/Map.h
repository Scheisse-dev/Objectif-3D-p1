#pragma once
#include "Object.h"
#include "FString.h"
#include "KeyValuePair.h"
#include "Exception.h"
#include "Boolean.h"

namespace Core
{
	namespace Collections
	{
		template<typename TKey, typename TValue>
		class O3DLIBRARY_API Map : public Object
		{
#pragma region f/p
		private:
			KeyValuePair < TKey, TValue>* tab = new KeyValuePair<TKey, TValue>[50];
			int count = 0;
			int capacity = 50;
		public:
			typedef KeyValuePair<TKey, TValue>* iterator;
			typedef KeyValuePair<TKey, TValue>* const_interator;

			iterator End() {
				return &tab[count];
			}
			
			const_interator end() {
				return &tab[count];
			}
			iterator Begin()
			{
				return &tab[0];
			}
			const_interator begin()
			{
				return &tab[0];
			}
#pragma endregion f/p
#pragma region constructor/destructor
		public:
			Map() = default; 
			Map(const int _capacity)
			{
				capacity = _capacity;
				tab = new KeyValuePair<TKey, TValue>[capacity];
			}
			Map(const std::initializer_list<KeyValuePair<TKey, TValue>>& _list)
			{
				if (_list.size() > capacity)
				{
					capacity = _list.size() * 2; 
					tab = new KeyValuePair<TKey, TValue>[capacity];
				}
				for (const KeyValuePair<TKey, TValue>& _pair : _list)
				{
					Add(_pair); 
				}
			}
			Map(const Map& _copy)
			{
				tab = _copy.tab;
				count = _copy.count; 
				capacity = _copy.capacity;
			}
#pragma endregion constructor/destructor
#pragma region methods
		private: 
			void Add(const KeyValuePair<TKey, TValue>& _pair)
			{
				if (count + 1 > capacity) throw OutOfRangeException("[Map] => out of range !");
				if (Countains(_pair.Key())) throw Exception("[Map] => Key already exist !");
				const int _hashed = Utils::Hash::GetObjectHashCode(_pair.Key()) % capacity;
				tab[_hashed] = _pair; 
				count++;
			}
		public: 
			int Count() const
			{
				return count; 
			}
			bool Countains(const TKey& _key)
			{
				const int _hashed = Utils::Hash::GetObjectHashCode(_key) % capacity;
				return tab[_hashed].Key() == _key; 
			}
			void Add(const TKey& _key, const TValue& _value)
			{
				if (Contains(_key)) throw Exception("[Map] => Key already exist !");
				const int _hashed = Utils::Hash::GetObjectHashCode(_key) % capacity;
				tab[_hashed] = KeyValuePair<TKey, TValue>(_key, _value); 
			}
			void Remove(const TKey& _key)
			{
				if (!Countains(_key)) throw Exception("[Map] => Key doesn't exist !");
				const int _hashed = Utils::Hash::GetObjectHashCode(_key) % capacity;
				tab[_hashed] = KeyValuePair<TKey, TValue>();
				count--;
			}
#pragma endregion methods
#pragma region operator
		public:
			TValue& operator[](const TKey& _key)
			{
				if (!Countains(_key)) throw Exception("[Map] => key doesn't exist !"); 
				const int _hashed = Utils::Hash::GetObjectHashCode(_key) % capacity;
				return tab[_hashed].Value();
			}
			TValue operator[](const TKey& _key) const
			{
				if (!Countains(_key)) throw Exception("[Map] => key doesn't exist !");
				const int _hashed = Utils::Hash::GetObjectHashCode(_key) % capacity;
				return tab[_hashed].Value();
			}
#pragma endregion operator
		};
	}

}