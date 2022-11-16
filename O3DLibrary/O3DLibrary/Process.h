#pragma once
#include "Object.h"
#include "O3DLibrary.h"

namespace Core
{
	namespace PrimaryType
	{
		class FString; 
	}
	namespace Diagnostics
	{
		class Process
		{
		public: 
			O3DLIBRARY_API static void Start(const Core::PrimitiveType::FString& _path, const Core::PrimitiveType:: FString& _parameters);
		};
	}
}