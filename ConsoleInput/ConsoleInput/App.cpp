#include "App.h"
#include "Event.h"
#include "EventSystem.h"
#include <exception>
#include <iostream>


#pragma region constructor
App::App()
{
	handle = GetStdHandle(STD_INPUT_HANDLE);
	if (handle == INVALID_HANDLE_VALUE)
		throw std::exception("error on get handle std input");
	if (!GetConsoleMode(handle, &oldMode))
		throw std::exception("failed to get console mode");
	currentMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(handle, currentMode))
		throw std::exception("failed on set console mode !");


}

#pragma endregion constructor

#pragma region methods
void App::KeyEventProc(KEY_EVENT_RECORD _keyEvent)
{
	
	if (_keyEvent.bKeyDown && _keyEvent.uChar.AsciiChar == VK_ESCAPE)
		isOpen = false; 

}
void App::MouseEventProc(MOUSE_EVENT_RECORD _mouseEvent)
{
	Event::mousePositionX = _mouseEvent.dwMousePosition.X;
	Event::mousePositionY = _mouseEvent.dwMousePosition.Y;

	if (_mouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		EventSystem::Instance()->Update(); 

}
void App::Open()
{
	while (isOpen)
	{
		if (!ReadConsoleInput(handle, inputRecord, INPUT_BUFFER_SIZE, &numRead))
			throw std::exception("failed on read console input !");
		for (i = 0; i < numRead; i++)
		{
			switch (inputRecord[i].EventType)
			{
			case KEY_EVENT:
				KeyEventProc(inputRecord[i].Event.KeyEvent);
				break;
			case MOUSE_EVENT:
				MouseEventProc(inputRecord[i].Event.MouseEvent);
				break;
			default:
				break;
			}
		}
	}
}

#pragma endregion methods