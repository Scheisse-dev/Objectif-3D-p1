#pragma once
#include "Object.h"
#include "Uri.h"
namespace Core
{
	namespace Net
	{
		class O3DLIBRARY_API WebClient
		{
#pragma region f/p
		private:
			Uri uri = Uri(); 
#pragma endregion f/p
#pragma region constructor
		public:
			WebClient() = default; 
			WebClient(const Uri& _uri);
			WebClient(const WebClient& _copy); 
#pragma endregion constructor
#pragma region methods
		public:
			void DownloadFile(const PrimitiveType::FString& _pathFile); 
#pragma endregion methods
#pragma region operator
		public:

#pragma endregion operator
		};
	}
}