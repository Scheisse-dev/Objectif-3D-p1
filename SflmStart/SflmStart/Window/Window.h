#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>
#include "Menu/BaseMenu.h"

class Window : public Object
{
#pragma region f/p
private:
	float width = 900; 
	float height = 600;
	const char* title = "Default Window";
protected:
	sf::Texture textureBackground;
	sf::Sprite background;
	sf::RenderWindow* window = nullptr;
	std::map<const char* ,BaseMenu*> menus = std::map<const char* , BaseMenu*>();
protected:
	bool eventIfNotFocus = false; 
#pragma endregion f/p 
#pragma region constructor
public: 
	Window() = default;
	Window(const float _width, const float _height, const char* _title);
	Window(const Window& _copy) = delete;
	virtual ~Window(); 
#pragma endregion constructor
#pragma region methods
private:
	void Update(); 
public: 
	void Open();
	void Close();
	bool IsOpen();
	bool HasFocus(); 
	void SetFrameLimit(const int _frame);
	void Draw(sf::Drawable* _drawable);
	sf::RenderWindow* Renderer() const; 
	float Width() const; 
	float Height() const; 
protected:
	void CloseAllMenus();
	void OpenMenu(const char* _name, BaseMenu* _menu); 
	void RegisterMenu(const char* _name, BaseMenu* _menu);
	virtual void InitMenu();
	virtual void OnDraw() = 0; 
	virtual void OnUpdate() = 0;
	virtual void OnReceiveEvent(const sf::Event& _event);
#pragma endregion methods

};

