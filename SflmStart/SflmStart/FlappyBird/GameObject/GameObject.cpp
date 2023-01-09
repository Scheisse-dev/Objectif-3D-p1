#include "GameObject.h"
#include "../../Window/Window.h"
#include "../Manager/FB_GameObjectManager/FB_GameObjectManager.h"
#pragma region constructor/destructor
GameObject::GameObject()
{
	FB_GameObjectManager::Instance()->Register(this);
}
GameObject::GameObject(GameObject& _copy)
{
	drawable = _copy.drawable;
}
GameObject::~GameObject()
{
	delete drawable;
	drawable = nullptr; 
}

#pragma endregion constructor/destructor
#pragma region methods
void GameObject::OnUpdate() {}
void GameObject::OnDraw(Window* _window)
{
	_window->Draw(drawable);
}
void GameObject::OnCollisionEnter(GameObject* _other)
{
}
#pragma endregion methods
