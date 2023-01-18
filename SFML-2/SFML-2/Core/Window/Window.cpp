#include "Window.h"
#include "../Input/Input.h"
#include "../Time/Time.h"

#pragma region constructor/destructor
Core::Window::Window(int _width, int _height, const char* _title)
{
	width = _width;
	height = _height;
	title = _title;
}

Core::Window::~Window()
{
	Close();
	delete render;
	render = nullptr; 
}
#pragma endregion constructor/destructor
#pragma region methods
void Core::Window::Open()
{
	render = new sf::RenderWindow(sf::VideoMode(width, height), title); 
}
void Core::Window::Close()
{
	if (!render->isOpen()) return;
	render->close();
}

void Core::Window::Update()
{
	Time::deltaTime = deltaClock.restart().asSeconds();
	while (render->isOpen())
	{
		//deltaTime
		while (render->pollEvent(currentEvent))
		{
			OnReceiveEvent(currentEvent);
		}
		OnUpdate();
		render->clear();
		OnDraw();
		render->display(); 
	}
}

int Core::Window::Width() const
{
	return width;
}

int Core::Window::Height() const
{
	return height;
}

sf::RenderWindow* Core::Window::Render() const
{
	return render;
}

void Core::Window::Draw(sf::Drawable* _drawable) const
{
	render->draw(*_drawable);
}

void Core::Window::OnDraw()
{

}

void Core::Window::OnUpdate()
{
	Input::Update();
}

void Core::Window::OnReceiveEvent(const sf::Event& _event)
{
	if (_event.type == sf::Event::Closed)
		Close();
}


#pragma endregion methods
