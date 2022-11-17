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
		class TextReader : public Object
		{
#pragma region f/P
		private:
			const char* path = nullptr;
			std::ifstream stream = std::ifstream(); 

#pragma endregion f/p 
#pragma region constructor
		public:
			O3DLIBRARY_API TextReader() = default;
			O3DLIBRARY_API TextReader(const char* _path);
			O3DLIBRARY_API TextReader(const PrimitiveType::FString& _path);
			O3DLIBRARY_API TextReader(const TextReader& _copy);
#pragma endregion constructor
#pragma region methods
		public: 
			O3DLIBRARY_API void Close();
			O3DLIBRARY_API PrimitiveType::Boolean IsOpen() const;
			O3DLIBRARY_API PrimitiveType::Boolean IsValid() const;
			O3DLIBRARY_API PrimitiveType::Boolean ReadeLine(PrimitiveType::FString& _out);
			O3DLIBRARY_API PrimitiveType::Boolean ReadeLine();
			O3DLIBRARY_API PrimitiveType::FString ReadToEnd();
			O3DLIBRARY_API PrimitiveType::FString Path() const;
			O3DLIBRARY_API PrimitiveType::Boolean Equals(const TextReader& _textReader) const;
#pragma endregion methods
#pragma region override
		public:
			O3DLIBRARY_API PrimitiveType::FString ToString() const override;
			O3DLIBRARY_API PrimitiveType::Boolean Equals(const Object* _obj) const override;
#pragma endregion override
		};
	}
}