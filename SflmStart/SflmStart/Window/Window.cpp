#include "Window.h"
#include "../Time/Time.h"
#include "../Event/Event.h"
#include "Menu/BaseMenu.h"
#include "../UI/Manager/UIElementManager.h"
#include <format>

#pragma region constructor
Window::Window(const float _width, const float _height, const char* _title)
{
	width = _width; 
	height = _height;
	title = _title; 
}

Window::~Window()
{
	Close(); 
	for (std::pair<const char*, BaseMenu*> _pair : menus)
	{
		delete _pair.second;
	}
	menus.clear(); 
	delete window;
}

#pragma endregion constructor
#pragma region methods
void Window::Update()
{
	
	SetFrameLimit(160);
	sf::Event _event = sf::Event(); 
	sf::Clock _clock = sf::Clock(); 
	while (window->isOpen())
	{

		Time::deltaTime = _clock.restart().asSeconds(); 
		while (window->pollEvent(_event))
		{
			//TODO event if not focus ?
			if (!window->hasFocus() && !eventIfNotFocus) continue;
			Event::currentEvent = &_event;
			OnReceiveEvent(_event); 
			break;
		}
		UIElementManager::Instance()->Update();
		OnUpdate();
		window->clear(); 
		OnDraw();
		window->display();
	}
}
void Window::Open()
{
	InitMenu();
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	Update();
	
}
void Window::Close()
{
	if (!window->isOpen()) return;
	window->close();
}
bool Window::IsOpen()
{
	return window->isOpen();
}
bool Window::HasFocus()
{
	return window->hasFocus();
}
void Window::SetFrameLimit(const int _frame)
{
	window->setFramerateLimit(_frame);
}
void Window::Draw(sf::Drawable* _drawable)
{
	window->draw(*_drawable);
}
sf::RenderWindow* Window::Renderer() const
{
	return window;
}
void Window::OnReceiveEvent(const sf::Event& _event)
{
	if (_event.type == sf::Event::Closed)
		Close(); 
}
float Window::Width() const
{
	return width;
}
float Window::Height() const
{
	return height;
}


void Window::CloseAllMenus()
{
	for (std::pair<const char*, BaseMenu*> _menu : menus)
		_menu.second->Close();
}
void Window::RegisterMenu(const char* _name, BaseMenu* _menu)
{
	menus.insert(std::pair(_name, _menu));
}

void Window::OpenMenu(const char* _name)
{
	CloseAllMenus();
	if (!menus.contains(_name))
	{
		throw std::exception(std::format("Menu : {} doesn't exist", _name).c_str());
	}
	menus[_name]->Open();
}
void Window::InitMenu()
{
	

}
#pragma endregion methods



