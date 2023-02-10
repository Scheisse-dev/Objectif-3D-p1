#pragma once
#include "../Object/Object.h"
#include "../PrimaryType/String/String.h"
#include "../PrimaryType/Boolean/Boolean.h"
#include "../PrimaryType/List/List.h"
#include "../Component/Component.h"
#include "../Transform/Transform.h"
#include "SFML/Graphics.hpp"

ENUM(PrimitiveType, Circle, Square)

namespace Engine
{
    namespace Window
    {
        class EngineWindow;
    }

    UCLASS()
    class GameObject : public Object
    {
        DECLARE_CLASS_INFO(GameObject, Object)
#pragma region var
    private:
        UPROPERTY() PrimaryType::List<Component*> components = PrimaryType::List<Component*>();
REGISTER_FIELD(components, &components, BindingFlags::NoPublic)
    protected:
        UPROPERTY() sf::Shape* shape = nullptr;
REGISTER_FIELD(shape, shape, BindingFlags::NoPublic)
    public:
        UPROPERTY() PrimaryType::String name = "";
REGISTER_FIELD(name, &name, BindingFlags::Public)
        Transform* transform = nullptr;
#pragma region const/dest
    public:
        GameObject() = default;
        GameObject(const PrimaryType::String& _name);
        ~GameObject() override;
#pragma endregion
#pragma region methods
    public:
        void AddComponent(Component* _compo);
        PrimaryType::List<Component*> Components() const;
        sf::Shape* Shape();
        void SetColor(const sf::Color& _color);
        static GameObject* CreatePrimitive(const PrimitiveType& _type, const PrimaryType::String& _name);
        void Draw(const Window::EngineWindow* _window) const;
        void OnDeSerialiseFinish() override;
        template <typename T>
        T* AddComponent();
        template <typename T>
        T* GetComponent() const;
#pragma endregion
#pragma region operator
    public:
        GameObject& operator=(const GameObject& _other);
        Engine::PrimaryType::Boolean operator==(const GameObject& _other);
        Engine::PrimaryType::Boolean operator!=(const GameObject& _other);
#pragma endregion
    };

    template<typename T>
    T* GameObject::AddComponent()
    {
        static_assert(std::is_base_of_v<Component, T>, "T must be inherited of Component");
        T* _compo = new T();
        _compo->gameObject = this;
        components.Add(_compo);
        return _compo;
    }

    template<typename T>
    T* GameObject::GetComponent() const
    {
        const size_t _size = (size_t)components.Count();
        for (size_t i = 0; i < _size; i++)
        {
            T* _res = dynamic_cast<T*>(components[i]);
            if (_res != nullptr)
                return _res;
        }
        return nullptr;
    }
}
