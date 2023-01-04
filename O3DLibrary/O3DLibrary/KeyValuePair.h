#pragma once
#include "Object.h" 
#include "FString.h"
#include "Hash.h"

namespace Core
{
	namespace Collections
	{


		template<typename TKey, typename TValue>
		class O3DLIBRARY_API KeyValuePair : public Object
		{	
#pragma region methods
		public: 

			static_assert(std::is_base_of_v < Object, TKey>, "Key must be an inherited of Object");
			static_assert(std::is_base_of_v<Object, TValue>, "Value must be an inherited of Object");

#pragma endregion methods
#pragma region f/p
		private:
			TKey key = TKey(); 
			TValue value = TValue(); 
#pragma endregion f/p
#pragma region constructor 
		public:
			KeyValuePair() = default;
			KeyValuePair(const TKey& _key, const TValue& _value)
			{
				key = _key;
				value = _value; 
			}
			KeyValuePair(const KeyValuePair& _copy)
			{
				key = _copy.key; 
				value = _copy.value;
			}
#pragma endregion constructor 
#pragma region methods
		public: 
			TKey Key() const
			{
				return key;
			}
			TValue Value() const
			{
				return value;
			}
			TValue& Value()
			{
				return value;
			}
#pragma endregion methods
#pragma region override
		public:
			PrimitiveType::FString ToString() const override
			{
				const PrimitiveType::FString& _key = Core::Utils::Hash::GetObjectToString(key);
				const PrimitiveType::FString& _ValueStr = Core::Utils::Hash::GetObjectToString(value);
				return PrimitiveType::FString::Format("Key: {}, Value : {}", key.Core::Object::ToString(), value.Core::Object::ToString());
			}
			int GetHashCode() const override
			{
				return Core::Utils::Hash::GetObjectHashCode(key) ^ Core::Utils::Hash::GetObjectHashCode(value) << 1;
			}
#pragma endregion override
#pragma region operator 
		public:
			KeyValuePair operator=(const KeyValuePair& _other)
			{
				key = _other.key; 
				value = _other.value; 
				return *this;
			}
			bool operator==(const KeyValuePair& _other)
			{
				return key == _other.key && value == _other.value; 
			}
			bool operator!=(const KeyValuePair& _other)
			{
				return !(*this == _other);
			}
			bool operator==(const TKey& _key)
			{
				return key == _key; 
			}
			bool operator!=(const TKey& _key)
			{
				return !(*this == _key);
			}
#pragma endregion operator 



		};
	}
}