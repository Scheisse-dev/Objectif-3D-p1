#pragma once

namespace Core
{
	namespace PrimitiveType
	{
		class String;
	}
	class Object
	{
#pragma region constructor/destructor
	public:
		Object() = default;
		virtual ~Object() = default;
#pragma endregion constructor/destructor
#pragma region methods
	public:
		virtual Core::PrimitiveType::String ToString() const;
#pragma region methods
	};

}

class Object
{
};
