#pragma once
#include "../Element/UIElement.h"
#include "../Interface/ITextEntered.h"
#include "../Interface/IPointerClickHandler.h"
#include "../Interface/IPointerEnterHandler.h"
#include "../Interface/IPointerExitHandler.h"

#define RETURN_KEY 8

namespace Engine::PrimaryType
{
    class Vector2;
}
namespace Engine::UI
{
    class TextField : public UIElement, public ITextEntered , public IPointerExitHandler, public IPointerEnterHandler, public IPointerClickHandler
    {
        DECLARE_CLASS_INFO(TextField, UIElement);
#pragma region f.p
    private:
        std::string inputText = std::string();
        std::string inputDefaultText = std::string();
        bool isSelected = false;
        sf::Text text = sf::Text();
#pragma endregion
#pragma region const
    public:
        TextField();
        TextField(const char* _label, const char* _defaultText, const PrimaryType::Vector2& _size);
        TextField(const char* _defaultText, const PrimaryType::Vector2& _size);
#pragma endregion
#pragma region meth
    public:
        void SetText(const char* _text);
#pragma endregion
#pragma region override
        void Draw(sf::RenderWindow* _window) override;
        void SetPosition(const PrimaryType::Vector2& _position) override;
        void OnPointerEnter() override;
        void OnPointerExit() override;
        virtual void OnPointerClick(const sf::Event& _event) override;
        virtual void OnTextEntered(sf::Uint32 _unicode) override;
        void OnPointerUnClick() override;
#pragma endregion


    };
}
