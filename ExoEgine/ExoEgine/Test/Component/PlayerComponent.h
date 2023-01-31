#pragma once
#include "../../Engine/Component/Component.h"


namespace Test
{
	UCLASS()
	class PlayerComponent : public Engine::Component
	{
	public:
		UFUNCTION() void Update();
REGISTER_METHOD(Update, &PlayerComponent::Update, {}, BindingFlags::Public)
	};

}
