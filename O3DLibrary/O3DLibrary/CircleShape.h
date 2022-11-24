#pragma once
#include "Shape.h"

namespace Core
{ 
	class O3DLIBRARY_API CircleShape : public Shape
	{
#pragma region f/p
	private: 
		float radius = 10.0f;
#pragma endregion f/p
#pragma region constructor 
	public: 
		 CircleShape(const Position& _position, const float _radius);
#pragma endregion constructor
#pragma region methods
	public:
		 void Draw(HDC _hdc) override;
#pragma endregion methods
	};

}