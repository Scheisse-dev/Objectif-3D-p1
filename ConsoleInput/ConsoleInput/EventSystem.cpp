#include "EventSystem.h"
#include "Button.h"
#include "Event.h"
#include "Rect.h"

#pragma region methods
void EventSystem::Register(Button* _button)
{
	buttons.push_back(_button); 
}

void EventSystem::UnRegister(Button* _button)
{
	const size_t _size = buttons.size(); 
	for (size_t i = 0; i < _size; i++)
	{
		if (buttons[i] == _button)
		{
			buttons.erase(buttons.begin() + i);
			break; 
		}
	}
}

void EventSystem::Update()
{
	const size_t _size = buttons.size(); 
	for (size_t i = 0; i < _size; i++)
	{
		if (buttons[i]->GetRect()->Contains(Event::mousePositionX, Event::mousePositionY))
			buttons[i]->OnClick();
	}
}

void EventSystem::Clear()
{
	const size_t _size = buttons.size();
	for (size_t i = 0; i < _size; i++)
	{
		delete buttons[i];
	}
	buttons.clear(); 
}
#pragma endregion methods
#pragma region override
void EventSystem::OnDestroy()
{
	Clear();
}
#pragma endregion override