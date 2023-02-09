#pragma once
#include "../../Engine/Component/Component.h"

namespace Test
{
	UCLASS()
	class PlayerComponent : public Engine::Component
	{
		DECLARE_CLASS_INFO(PlayerComponent, Component)
	public:
		PlayerComponent();
		UFUNCTION() void Update();
REGISTER_METHOD(Update, &PlayerComponent::Update, {}, BindingFlags::Public)
	};

}
