#pragma once
#include "Object.h"
#include "EConsoleColor.h"
#include <Windows.h>

namespace Core
{
#define LOG(obj) Core::Console::WriteLine("[LOG]", obj);
#define LOG_WARNING(obj) Core::Console::WriteLine("[WARNING]", obj, Core::EConsoleColor::Yellow);
#define LOG_ERROR(obj) Core::Console::WriteLine("[ERROR]", obj, Core::EConsoleColor::Red);

	namespace IO
	{
		class TextWritter; 
	}
	class Console : public Object
	{
#pragma region f/p
	private:
		O3DLIBRARY_API static inline HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	public: 
		O3DLIBRARY_API static IO::TextWritter* Out;

#pragma endregion f/p
#pragma region methods
	private:
		O3DLIBRARY_API static IO::TextWritter* Out_Internal();
	public: 
		O3DLIBRARY_API static void WriteLine(const PrimitiveType::FString& _label , const object _obj, const EConsoleColor _color = EConsoleColor::Reset);
		O3DLIBRARY_API static void WriteLine(const PrimitiveType::FString& _label , const Object& _obj, const EConsoleColor& _color = EConsoleColor::Reset);
#pragma endregion methods
	};
}
