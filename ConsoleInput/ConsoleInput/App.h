#pragma once
#include <windows.h>

#define INPUT_BUFFER_SIZE 128

class App
{
#pragma region f/p
private:
	HANDLE handle = HANDLE(); 
	DWORD oldMode, currentMode; 
	DWORD numRead, i;
	INPUT_RECORD inputRecord[INPUT_BUFFER_SIZE];
	bool isOpen = true;
#pragma endregion f/p
#pragma region constructor
public: 
	App(); 
#pragma endregion constructor
#pragma region methods
private:
	void KeyEventProc(KEY_EVENT_RECORD _keyEvent); 
	void MouseEventProc(MOUSE_EVENT_RECORD _mouseEvent); 
public: 
	void Open(); 

#pragma endregion methods
};

