#pragma once
#include <windows.h>
class Console
{
#pragma region f/p
private:
	static inline HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	static inline COORD cursorPosition = { 0,0 }; 
#pragma endregion f/p
#pragma region methods
public:
	static void SetCursorPosition(const int _x, const int _y); 
};
#pragma endregion methods

