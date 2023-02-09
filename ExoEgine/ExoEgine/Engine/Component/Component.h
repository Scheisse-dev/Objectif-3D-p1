#pragma once
#include "../Object/Object.h"
#include "../PrimaryType/Boolean/Boolean.h"

namespace Engine
{
	class GameObject; 

	UCLASS()
	class Component : public Object
	{
		DECLARE_CLASS_INFO(Component, Object)
#pragma region f/p
		public:
		UPROPERTY() PrimaryType::Boolean enable = true;
REGISTER_FIELD(enable, &enable, BindingFlags::Public)
		GameObject* gameobject = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
	public:
		Component() = default;
		~Component() override = default;
#pragma endregion constructor/destructor
#pragma region operator
	public:
		Object& operator=(const Object* _obj) override;
		Component& operator=(const Component& _cop);

#pragma endregion operator
	};

}
