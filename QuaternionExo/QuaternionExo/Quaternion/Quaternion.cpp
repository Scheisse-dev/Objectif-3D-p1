#include "Quaternion.h"

#pragma region constructor 
Quaternion::Quaternion(const float _x, const float _y, const float _z, const float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;

}

Quaternion::Quaternion(const Quaternion& _copy)
{
	x = _copy.x;
	y = _copy.y;
	z = _copy.z;
	w = _copy.w;
}

#pragma endregion constructor 
#pragma region methods

#pragma endregion methods
#pragma region operator

#pragma endregion operator

