#pragma once
#include "../Element/UIElement.h"
#include "../Interface/IPointerClickHandler.h"
#include "../Interface/IPointerEnterHandler.h"
#include "../Interface/IPointerExitHandler.h"
#include "../../Event/Action/ActionInternal.h"


namespace Engine::UI
{
    class AssetButton : public UIElement, public IPointerClickHandler, public IPointerEnterHandler, public IPointerExitHandler
    {
        DECLARE_CLASS_INFO(AssetButton, UIElement)
#pragma region f.P
    private:
        float width = 100.f;
        float height = 40.f;
        sf::Text text = sf::Text();
        sf::Color baseColor = sf::Color::White;
        sf::Color enterColor = sf::Color(189, 195, 199);
        Action<Object*> OnClick = nullptr;
        Object* object = nullptr;
#pragma endregion
#pragma region const
    public:
        AssetButton() = default;
        AssetButton(const std::string& _text, float _width, float _height, Object* _obj, const Action<Object*>& _onClick = nullptr);
#pragma endregion
#pragma region meth
        template<typename Class>
        void AddListener(Class* _instance, void(Class::* ptr)(Object*))
        {
            OnClick.AddDynamic(_instance, ptr);
        }
        template<typename Class>
        void RemoveListener(Class* _instance, void(Class::* ptr)(Object*))
        {
            OnClick.RemoveDynamic(_instance, ptr);
        }
        void SetBackgroundColor(const sf::Color& _color);
#pragma endregion
#pragma region override
    public:
        void OnPointerClick(const sf::Event& _event) override;
        void OnPointerUnClick() override;
        void OnPointerEnter() override;
        void OnPointerExit() override;
        void SetPosition(const PrimaryType::Vector2& _position) override;
        void Draw(sf::RenderWindow* _window) override;
        
#pragma endregion

    };

}
