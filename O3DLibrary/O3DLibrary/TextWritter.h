#pragma once

#include "Object.h"
#include <fstream>

namespace Core
{
	namespace PrimitiveType
	{
		class FString;
		class Boolean;
	}
	namespace IO
	{
		class TextWritter : public Object
		{
#pragma region f/p
		private:
			const char* path = nullptr;
			std::ofstream stream = std::ofstream();
#pragma endregion f/p
#pragma region constructor
		public:
			O3DLIBRARY_API TextWritter() = default;
			O3DLIBRARY_API TextWritter(const char* _path);
			O3DLIBRARY_API TextWritter(const PrimitiveType::FString& _path);
			O3DLIBRARY_API TextWritter(const TextWritter& _copy);
#pragma endregion constructor
#pragma region methods 
		public: 
			O3DLIBRARY_API PrimitiveType::Boolean IsOpen() const;
			O3DLIBRARY_API PrimitiveType::Boolean Exist() const;
			O3DLIBRARY_API PrimitiveType::Boolean Equals(const TextWritter& _obj) const;
			O3DLIBRARY_API PrimitiveType::FString Path() const;
			O3DLIBRARY_API void Close();
			O3DLIBRARY_API void Clear(); 
			O3DLIBRARY_API void Write(const Object& _obj); 
			O3DLIBRARY_API void Write(const Object* _obj);
#pragma endregion methods
#pragma region override
		public: 
			O3DLIBRARY_API PrimitiveType::FString ToString() const override;
			O3DLIBRARY_API PrimitiveType::Boolean Equals(const Object* _obj) const override; 

#pragma endregion override
#pragma region operator
		public: 
			O3DLIBRARY_API void operator<<(const Object& _obj);
			O3DLIBRARY_API void operator<<(const Object* _obj);
#pragma endregion operator 
		};
	}
}