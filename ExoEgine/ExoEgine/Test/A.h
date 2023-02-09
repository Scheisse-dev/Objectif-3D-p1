#pragma once

#include "../../Engine/PrimaryType/Integer/Integer.h"
#include "../../Engine/PrimaryType/Float/Float.h"
#include "../../Engine/PrimaryType/Double/Double.h"
#include "../../Engine/PrimaryType/String/String.h"
#include "../../Engine/PrimaryType/Boolean/Boolean.h"
#include "../../Engine/PrimaryType/Vector/Vector2/Vector2.h"
#include "../../Engine/PrimaryType/List/List.h"
#include "../../Engine/Transform/Transform.h"
#include "../../Engine/Component/Component.h"
#include "B.h"

UCLASS()
class A : public Engine::Object
{
public:

	
	

	UPROPERTY() Engine::PrimaryType::List<Engine::PrimaryType::Integer> coucou = {5 , 1 , 6};
REGISTER_FIELD(coucou, &coucou, BindingFlags::Public)
	
	UPROPERTY() Engine::PrimaryType::List<Engine::Component> list = {  };
REGISTER_FIELD(list, &list, BindingFlags::Public)

	


//
//Engine::PrimaryType::String ToString() const override
//{
//	Engine::PrimaryType::String _result = "";
//	for (B* _value : blist)
//		_result += _value->toast.ToString();
//	return _result; 
//}
};
