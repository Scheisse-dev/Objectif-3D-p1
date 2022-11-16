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
		};
	}
}