#pragma once
#include "Object.h"

namespace Core
{
	namespace IO
	{
		class Path : public Object
		{
#pragma region f/p
		private:
			static const char DirectorySeparator = '/';
#pragma endregion f/p
#pragma region methods
		public: 
			O3DLIBRARY_API static PrimitiveType::FString GetPath(const PrimitiveType::FString& _path);
			O3DLIBRARY_API static PrimitiveType::FString GetParent(const PrimitiveType::FString& _path);
			O3DLIBRARY_API static PrimitiveType::FString Combine(const std::initializer_list<PrimitiveType::FString>& _paths);
#pragma endregion methods

		};
	}
}