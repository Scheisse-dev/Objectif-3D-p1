#pragma once
#include "Object.h"
#include "EConsoleColor.h"
#include <Windows.h>

namespace Core
{
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
		O3DLIBRARY_API static void WriterLine(const object _obj, const EConsoleColor _color = EConsoleColor::Reset);
		O3DLIBRARY_API static void WriterLine(const Object& _obj, const EConsoleColor& _color = EConsoleColor::Reset);
#pragma endregion methods
	};
}
