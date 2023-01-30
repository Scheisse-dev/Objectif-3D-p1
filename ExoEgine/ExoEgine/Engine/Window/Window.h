#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "../PrimaryType/Integer/Integer.h"
#include "../PrimaryType/Boolean/Boolean.h"
#include "../PrimaryType/String/String.h"
#include "../Utils/Singleton/Singleton.h"
#include "../Utils/DebugMacro.h"


namespace Engine::Window
{
	template<typename T>
	class Window : public Utils::Singleton<T>
	{
#pragma region f/p
	protected:
		sf::RenderWindow* renderer = nullptr;
		PrimaryType::String name = "";
		PrimaryType::Integer width = 0;
		PrimaryType::Integer height = 0;
		PrimaryType::Boolean hasFocus = true;
		sf::Event currentEnvet = sf::Event();
#pragma endregion f/p
#pragma region constructor
	public:
		Window() = delete;
		Window(const char* _name, const int _width = 800,const int _height = 600)
		{
			name = _name;
			width = _width;
			height = _height;
		}
		Window(const Window&) = delete;
#pragma endregion constructor
#pragma region methods
	private:
		void Update()
		{
			while (renderer->isOpen())
			{
				while (renderer->pollEvent(currentEvent))
				{
					if (currentEnvet.type == sf::Event::Closed)
						Close();
					if (currentEnvet.type == sf::Event::LostFocus || currentEnvet.type == sf::Event::GainedFocus)
					{

					}
					if (hasFocus)
						OnReceiveEnvent(currentEvent);
				}
			}
		}
		void SetFocus(const sf::Event::EventType& _eventType)
		{
			hasFocus = _eventType == sf::Event::LostFocus ? false : true;
			LOG_FORMAT("[Engine] Focus: {}", hasFocus.ToString().ToCstr()));
		}
	public:
		virtual void Open()
		{
			renderer = new sf::RenderWindow(sf::VideoMode(width, height), name.ToCstr());
			Update(); 
		}
		void Close()
		{
			renderer->close();
		}
		PrimaryType::Boolean IsOpen() const
		{
			return renderer->isOpen();
		}
		PrimaryType::Boolean HasFocus() const
		{
			return renderer->hasFocus;
		}
		void SetFrameLimit(int _frame) const
		{
			renderer->setFramerateLimit(_frame);
		}
		void Draw(sf::Drawable* _drawable) const
		{
			renderer->draw(*_drawable);
		}
	protected:
		virtual void OnUpdate() {}
		virtual void OnDraw(){}
		virtual void OnClear() {}
		virtual void OnReceiveEvent(const sf::Event& _event);
		void Clear() const
		{
			renderer->clear();
			OnClear();
		}
		void Display() const
		{
			renderer->display();
		}
#pragma endregion methods
#pragma region override
	public:
		PrimaryType::String ToString() const override
		{
			PrimaryType::String _result = "==========Window Settings==========\n";
			_result += PrimaryType::String("Name: ");
			_result += name;
			_result += "\nWidth: ";
			_result += width.ToString();
			_result += "\nHeight: ";
			_result += height.ToString();
			_result += "===================================\n";
			return _result;
		}
#pragma endregion override
	};
