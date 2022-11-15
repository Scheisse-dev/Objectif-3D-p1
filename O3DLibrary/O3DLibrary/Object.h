#pragma once
#include <iostream>
#include "O3DLibrary.h"

namespace Core
{
	namespace PrimitiveType
	{
		class FString;
	}
	class Object
	{
#pragma region constructor/destructor
	public:
		Object() = default;
		virtual ~Object() = default;
#pragma endregion constructor/destructor
#pragma region methods
	public:
		O3DLIBRARY_API virtual Core::PrimitiveType::FString ToString() const;


#pragma region methods 
		
	};

}

