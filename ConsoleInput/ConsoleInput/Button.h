#pragma once
#include <string>

class Rect; 

class Button
{
#pragma region f/p
private:
	std::string content = ""; 
	Rect* rect = nullptr; 
#pragma endregion f/p
#pragma region constructor/destructor
public: 
	Button() = default; 
	Button(const std::string& _content, Rect* _rect);
	Button(const Button& _copy); 
#pragma endregion constructor/destructor
#pragma region methods
public: 
	void OnClick(); 
	Rect* GetRect() const;
#pragma endregion methods 
};

