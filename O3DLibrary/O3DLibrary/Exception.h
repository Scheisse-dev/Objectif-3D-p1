#pragma once
#include "Object.h"
#include "FString.h"
#include <source_location>

namespace Core
{
		class O3DLIBRARY_API Exception : public Object
		{
#pragma region f/p
		private: 
			Core::PrimitiveType::FString error = ""; 
#pragma endregion f/p
#pragma region constructor
		public: 
			 Exception(const Core::PrimitiveType::FString& _error = "exception", const std::source_location& _location = std::source_location::current());

#pragma endregion constructor
#pragma region override
		public: 
			 Core::PrimitiveType::FString ToString() const override; 
#pragma endregion override
		};
		typedef Exception OutOfRangeException; 
		typedef Exception DivideByZeroException; 
}