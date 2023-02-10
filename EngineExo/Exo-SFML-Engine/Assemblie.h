#pragma once
#include "Engine/Utils/ObjectMacro.h"

using namespace Engine;
#include "Engine\Component\Component.h"
REGISTER_TYPE(Component)
#include "Engine\GameObject\GameObject.h"
REGISTER_TYPE(GameObject)
#include "Engine\Transform\Transform.h"
REGISTER_TYPE(Transform)

using namespace Engine::PrimaryType;
#include "Engine\PrimaryType\String\String.h"
REGISTER_TYPE(String)
#include "Engine\PrimaryType\Vector2\Vector2.h"
REGISTER_TYPE(Vector2)

using namespace Engine::Reflection;
#include "Engine\Reflection\Fields\FieldsInfo.h"
REGISTER_TYPE(FieldsInfo)

using namespace Test;
#include "Test\A.h"
REGISTER_TYPE(A)
#include "Test\Component\PlayerComponent.h"
REGISTER_TYPE(PlayerComponent)


