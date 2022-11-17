#pragma once
#include "Object.h"

namespace Core
{
	namespace IO
	{
		class Directory : public Object
		{
#pragma region methods
		public:
			O3DLIBRARY_API static void MakeDirectory(const PrimitiveType::FString& _path);
			O3DLIBRARY_API static PrimitiveType::Boolean Exist(const PrimitiveType::FString& _path);
#pragma endregion methods
		};
	}
}