#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>

namespace Core
{
	class Window : public Object
	{
		DECLARE_CLASS_INFO(Window, Object)
#pragma region f/p
	protected:
		int width = 900;
		int height = 800; 
		const char* title = "Default Window Name";
		sf::RenderWindow* render = nullptr;
		sf::Event currentEvent = sf::Event(); 
		sf::Clock deltaClock = sf::Clock(); 
#pragma endregion f/p
#pragma region constructor/destructor
	public:
		Window() = delete;
		Window(int _width, int _height, const char* _title);
		Window(const Window&) = delete; 
		~Window() override;
#pragma endregion constructor/destructor
#pragma region methods
	public:
		void Open();
		void Close(); 
		int Width() const;
		int Height() const;
		sf::RenderWindow* Render() const;
		void Draw(sf::Drawable* _drawable) const;
	protected:
		void OnDraw();
		void OnReceiveEvent(const sf::Event& _event);
		void OnUpdate();
	private:
		void Update(); 
#pragma endregion methods
	};
}