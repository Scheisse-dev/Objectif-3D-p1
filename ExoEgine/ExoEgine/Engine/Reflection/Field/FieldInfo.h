#pragma once
#include "../../Object/Object.h"
#include "../../PrimaryType/String/String.h"
#include "../../PrimaryType/Boolean/Boolean.h"
#include "../Flags/BindingFlag.h"

namespace Engine::Reflection
	{
		UCLASS()
		class FieldInfo : public Object
		{
			DECLARE_CLASS_INFO(FieldInfo, Object)
	#pragma region f/p
		private:
			PrimaryType::String name = "";
			Object* reflectedObject = nullptr; 
			BindingFlags flag = BindingFlags::NoPublic;
	#pragma endregion f/p
	#pragma region constructor
		public:
			FieldInfo() = default;
			FieldInfo(PrimaryType::String _name, Object* _reflectedObject, BindingFlags _flags);
	#pragma endregion constructor
#pragma region methods
			PrimaryType::Boolean IsPublic() const;
			PrimaryType::Boolean IsPrivate() const;
			PrimaryType::Boolean IsStatic() const;
			PrimaryType::Boolean IsArray() const;
			PrimaryType::Boolean IsReflectedClass() const;
			PrimaryType::String Name() const; 
			Object ReflectedObject() const;
			BindingFlags Flags() const;

#pragma endregion methods
#pragma region override
				PrimaryType::String ToString() const override; 
				Object& operator=(const Object* obj) override;
#pragma endregion override
		};

	}