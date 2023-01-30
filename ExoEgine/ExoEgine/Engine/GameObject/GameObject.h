#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics/Shape.hpp>
#include "../PrimaryType/String/String.h"
#include "../PrimaryType/List/List.h"
#include "../Component/Component.h"

ENUM(PrimitiveType, Circle, Square)


namespace Engine
{
	

	class GameObject : public Object
	{
		DECLARE_CLASS_INFO(GameObject, Object)
#pragma region f/p
	private:
		PrimaryType::List<Component*> components = PrimaryType::List<Component*>();
	protected:
		sf::Shape* shape = nullptr;
		PrimaryType::String name = "";
#pragma endregion f/p
#pragma region constructor/destructor
	public:
		GameObject() = default;
		GameObject(const PrimaryType::String& _name);
		GameObject(const GameObject& _copy);
		~GameObject() override;
#pragma endregion constructor/destructor
#pragma region methods
	public:
		void AddComponent(Component* _component);
		PrimaryType::List<Component*> Components() const;
		sf::Shape* Shape() const; 
		void SetColor(const sf::Color& _color);
		static GameObject* CreatePrimitive(const PrimitiveType& _type, const PrimaryType::String& _name);
		template<typename T>
		T* AddComponent();
		template<typename T>
		T* GetComponent();
#pragma endregion methods
#pragma region operator
	public:
		GameObject& operator=(const GameObject& _other);
		PrimaryType::Boolean operator==(const GameObject& _other) const;
		PrimaryType::Boolean operator!=(const GameObject& _other) const; 
#pragma endregion operator
	};

	template<typename T>
	inline T* GameObject::AddComponent()
	{
		static_assert(std::is_base_of_v<Component, T>, "T must be inherited of Component");
		T* _component = new T();
		_component->gameobject = this; 
		components.Add(_component);
		return _component; 
	}

	template<typename T>
	inline T* GameObject::GetComponent()
	{
		const size_t _size = (size_t)components.Count();
		for (size_t i = 0; i < _size; ++i)
		{
			T* _result = dynamic_cast<T*>(components[i]);
			if (_result != nullptr) return _result; 
		}
		return nullptr;
	}

}