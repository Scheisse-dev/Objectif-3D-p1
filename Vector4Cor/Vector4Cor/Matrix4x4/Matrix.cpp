#include "Matrix.h"
#include "../Math/Mathf.h"
#include "../Quaternion/Quaternion.h"

#pragma region f/p
Matrix4x4 const Matrix4x4::Identity = Matrix4x4(1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1);
#pragma endregion f/p
#pragma region constructor
Matrix4x4::Matrix4x4(const float _m11, const float _m12, const float _m13, const float _m14, const float _m21, const float _m22, const float _m23, const float _m24, const float _m31, const float _m32, const float _m33, const float _m34, const float _m41, const float _m42, const float _m43, const float _m44)
{
	m11 = _m11;
	m12 = _m12;
	m13 = _m13;
	m14 = _m14;

	m21 = _m21;
	m22 = _m22;
	m23 = _m23;
	m24 = _m24;

	m31 = _m31;
	m32 = _m32;
	m33 = _m33;
	m34 = _m34;

	m41 = _m41;
	m42 = _m42;
	m43 = _m43;
	m44 = _m44;
		
}

Matrix4x4::Matrix4x4(const Matrix4x4& _copy)
{
	m11 = _copy.m11;
	m12 = _copy.m12;
	m13 = _copy.m13;
	m14 = _copy.m14;

	m21 = _copy.m21;
	m22 = _copy.m22;
	m23 = _copy.m23;
	m24 = _copy.m24;

	m31 = _copy.m31;
	m32 = _copy.m32;
	m33 = _copy.m33;
	m34 = _copy.m34;

	m41 = _copy.m41;
	m42 = _copy.m42;
	m43 = _copy.m43;
	m44 = _copy.m44;
}

#pragma endregion constructor

#pragma region Methods
Matrix4x4 Matrix4x4::CreateTranslation(const float _x, const float _y, const float _z)
{
	Matrix4x4 _result = Identity; 
	_result.m41 = _x;
	_result.m42 = _y; 
	_result.m43 = _z;
	return _result;
}
Matrix4x4 Matrix4x4::CreateScale(const float _x, const float _y, const float _z)
{
	Matrix4x4 _result = Identity;
	_result.m11 = _x; 
	_result.m22 = _y; 
	_result.m33 = _z;
	return _result; 
}
Matrix4x4 Matrix4x4::CreateRotateX(const float _radians)
{
	Matrix4x4 _result = Identity;
	const float _cos = Mathf::Cos(_radians);
	const float _sin = Mathf::Sin(_radians);
	_result.m22 = _cos;
	_result.m23 = _sin;
	_result.m32 = -_sin; 
	_result.m33 = _cos;
	return _result;
}
Matrix4x4 Matrix4x4::CreateRotateY(const float _radians)
{
	Matrix4x4 _result = Identity;
	const float _cos = Mathf::Cos(_radians);
	const float _sin = Mathf::Sin(_radians);

	_result.m11 = _cos; 
	_result.m13 = -_sin; 
	_result.m31 = _sin;
	_result.m33 = _cos; 

	return _result;
}
Matrix4x4 Matrix4x4::CreateRotateZ(const float _radians)
{
	Matrix4x4 _result = Identity;
	const float _cos = Mathf::Cos(_radians);
	const float _sin = Mathf::Sin(_radians);

	_result.m11 = _cos;
	_result.m12 = _sin; 
	_result.m21 = -_sin;
	_result.m22 = _cos; 

	return _result;
}
Matrix4x4 Matrix4x4::CreateOrthographic(const float _width, const float _height, const float _nearPlane, const float _farPlane)
{
	Matrix4x4 _result = Matrix4x4(); 
	_result.m11 = 2.0f / _width; 
	_result.m22 = 2.0f / _height;
	_result.m33 = 1.0f / (_nearPlane - _farPlane);
	_result.m43 = _nearPlane / (_nearPlane - _farPlane);
	_result.m44 = 1.0f;
	return _result;

}
Matrix4x4 Matrix4x4::CreateFromQuaternion(const Quaternion& _quaternion)
{
	Matrix4x4 _result = Matrix4x4();
	const float _xx = _quaternion.x * _quaternion.x;
	const float _yy = _quaternion.y * _quaternion.y;
	const float _zz = _quaternion.z * _quaternion.z;

	const float _xy = _quaternion.x * _quaternion.y;
	const float _wz = _quaternion.w * _quaternion.z;
	const float _xz = _quaternion.x * _quaternion.z;
	const float _wy = _quaternion.w * _quaternion.y;
	const float _yz = _quaternion.y * _quaternion.z;
	const float _wx = _quaternion.w * _quaternion.x;

	_result.m11 = 1.0f - 2.0f * (_yy + _zz);
	_result.m12 = 2.0f * (_xy + _wz);
	_result.m13 = 2.0f * (_xz - _wy);
	_result.m14 = 0.0f;

	_result.m21 = 2.0f * (_xy - _wz);
	_result.m22 = 1.0f - 2.0f * (_zz + _xx);
	_result.m23 = 2.0f * (_yz + _wx);
	_result.m24 = 0.0f;

	_result.m31 = 2.0f * (_xz + _wy); 
	_result.m32 = 2.0f * (_yz - _wx);
	_result.m33 = 1.0f - 2.0f * (_yy + _xx);
	_result.m34 = 0.0f;

	_result.m41 = 0.0f;
	_result.m41 = 0.0f;
	_result.m42 = 0.0f;
	_result.m43 = 0.0f;
	_result.m44 = 1.0f;


	return _result; 
}
Matrix4x4 Matrix4x4::CreateFromYawPitchRoll(const float _yaw, const float _pitch, const float _roll)
{
	return CreateFromQuaternion(Quaternion::CreateFromYawPitchRoll(_yaw, _pitch, _roll)); 
}
Matrix4x4 Matrix4x4::Lerp(const Matrix4x4& _a, const Matrix4x4& _b, const float _t)
{
	Matrix4x4 _result = Matrix4x4(); 

	_result.m11 = _a.m11 + (_b.m11 - _a.m11) * _t;
	_result.m12 = _a.m12 + (_b.m12 - _a.m12) * _t;
	_result.m13 = _a.m13 + (_b.m13 - _a.m13) * _t;
	_result.m14 = _a.m14 + (_b.m14 - _a.m14) * _t;

	_result.m21 = _a.m21 + (_b.m21 - _a.m21) * _t;
	_result.m22 = _a.m22 + (_b.m22 - _a.m22) * _t;
	_result.m23 = _a.m23 + (_b.m23 - _a.m23) * _t;
	_result.m24 = _a.m24 + (_b.m24 - _a.m24) * _t;

	_result.m31 = _a.m31 + (_b.m31 - _a.m31) * _t;
	_result.m32 = _a.m32 + (_b.m32 - _a.m32) * _t;
	_result.m33 = _a.m33 + (_b.m33 - _a.m33) * _t;
	_result.m34 = _a.m34 + (_b.m34 - _a.m34) * _t;

	_result.m41 = _a.m41 + (_b.m41 - _a.m41) * _t;
	_result.m42 = _a.m42 + (_b.m42 - _a.m42) * _t;
	_result.m43 = _a.m43 + (_b.m43 - _a.m43) * _t;
	_result.m44 = _a.m44 + (_b.m44 - _a.m44) * _t;

	return _result;
}
float Matrix4x4::Determinant() const
{
	const float _a = m11, _b = m12, _c = m13, _d = m14,
		_e = m21, _f = m22, _g = m23, _h = m24,
		_i = m31, _j = m32, _k = m33, _l = m34,
		_m = m41, _n = m42, _o = m43, _p = m44;

	const float _kplo = _k * _p - _l * _o;
	const float _jpln = _j * _p - _l * _n; 
	const float _jokn = _j * _o - _k * _n;
	const float _iplm = _i * _p - _l * _m;
	const float _iokm = _i * _o - _k * _m;
	const float _injm = _i * _n - _j * _m;

	return _a * (_f * _kplo - _g * _jpln + _h * _jokn) -
		_b * (_e * _kplo - _h * _iplm + _h * _iokm) +
		_c * (_e * _jpln - _f * _iplm + _h * _injm) -
		_d * (_e * _jokn - _f * _iokm + _g * _injm);


}

bool Matrix4x4::IsIdentity(const Matrix4x4& _other)
{
	return
		Identity.m11 == _other.m11 &&
		Identity.m12 == _other.m12 &&
		Identity.m13 == _other.m13 &&
		Identity.m14 == _other.m14 &&
		Identity.m21 == _other.m21 &&
		Identity.m22 == _other.m22 &&
		Identity.m23 == _other.m23 &&
		Identity.m24 == _other.m24 &&
		Identity.m31 == _other.m31 &&
		Identity.m32 == _other.m32 &&
		Identity.m33 == _other.m33 &&
		Identity.m34 == _other.m34 &&
		Identity.m41 == _other.m41 &&
		Identity.m42 == _other.m42 &&
		Identity.m43 == _other.m43;
}

#pragma endregion Methods

#pragma region operator
Matrix4x4 Matrix4x4::operator-() const
{
	Matrix4x4 _result = Matrix4x4();

	_result.m11 = -m11;
	_result.m12 = -m12;
	_result.m13 = -m13;
	_result.m14 = -m14;

	_result.m21 = -m21;
	_result.m22 = -m22;
	_result.m23 = -m23;
	_result.m24 = -m24;

	_result.m31 = -m31;
	_result.m32 = -m32;
	_result.m33 = -m33;
	_result.m34 = -m34;

	_result.m41 = -m41;
	_result.m42 = -m42;
	_result.m43 = -m43;
	_result.m44 = -m44;

	return _result;
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& _other)
{
	Matrix4x4 _result = Matrix4x4();
		_result.m11 = m11 + _other.m11;
		_result.m12 = m12 + _other.m12;
		_result.m13 = m13 + _other.m13;
		_result.m14 = m14 + _other.m14;
		_result.m21 = m21 + _other.m21;
		_result.m22 = m22 + _other.m22;
		_result.m23 = m23 + _other.m23;
		_result.m24 = m24 + _other.m24;
		_result.m31 = m31 + _other.m31;
		_result.m32 = m32 + _other.m32;
		_result.m33 = m33 + _other.m33;
		_result.m34 = m34 + _other.m34;
		_result.m41 = m41 + _other.m41;
		_result.m42 = m42 + _other.m42;
		_result.m43 = m43 + _other.m43;

		return _result;




}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& _other)
{
	Matrix4x4 _result = Matrix4x4();
	_result.m11 = m11 - _other.m11;
	_result.m12 = m12 - _other.m12;
	_result.m13 = m13 - _other.m13;
	_result.m14 = m14 - _other.m14;
	_result.m21 = m21 - _other.m21;
	_result.m22 = m22 - _other.m22;
	_result.m23 = m23 - _other.m23;
	_result.m24 = m24 - _other.m24;
	_result.m31 = m31 - _other.m31;
	_result.m32 = m32 - _other.m32;
	_result.m33 = m33 - _other.m33;
	_result.m34 = m34 - _other.m34;
	_result.m41 = m41 - _other.m41;
	_result.m42 = m42 - _other.m42;
	_result.m43 = m43 - _other.m43;

	return _result;


}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& _other)
{
	Matrix4x4 _result = Matrix4x4();

	_result.m11 = m11 * _other.m11 + m12 * _other.m21 + m13 * _other.m31 + m14 * _other.m41;
	_result.m12 = m11 * _other.m12 + m12 * _other.m22 + m13 * _other.m32 + m14 * _other.m42;
	_result.m13 = m11 * _other.m13 + m12 * _other.m23 + m13 * _other.m33 + m14 * _other.m43;
	_result.m14 = m11 * _other.m14 + m12 * _other.m24 + m13 * _other.m34 + m14 * _other.m44;

	_result.m21 = m11 * _other.m21 + m12 * _other.m21 + m13 * _other.m21 + m24 * _other.m41;
	_result.m22 = m11 * _other.m22 + m12 * _other.m22 + m13 * _other.m22 + m24 * _other.m42;
	_result.m23 = m11 * _other.m23 + m12 * _other.m23 + m13 * _other.m33 + m24 * _other.m43;
	_result.m24 = m11 * _other.m24 + m12 * _other.m24 + m13 * _other.m24 + m24 * _other.m44;

	_result.m31 = m11 * _other.m31 + m12 * _other.m21 + m13 * _other.m31 + m34 * _other.m41;
	_result.m32 = m11 * _other.m32 + m12 * _other.m22 + m13 * _other.m32 + m34 * _other.m42;
	_result.m33 = m11 * _other.m33 + m12 * _other.m23 + m13 * _other.m33 + m34 * _other.m43;
	_result.m34 = m11 * _other.m34 + m12 * _other.m24 + m13 * _other.m34 + m34 * _other.m44;

	_result.m41 = m11 * _other.m41 + m12 * _other.m21 + m13 * _other.m31 + m44 * _other.m41;
	_result.m42 = m11 * _other.m42 + m12 * _other.m22 + m13 * _other.m32 + m44 * _other.m42;
	_result.m43 = m11 * _other.m43 + m12 * _other.m23 + m13 * _other.m33 + m44 * _other.m43;
	_result.m44 = m11 * _other.m44 + m12 * _other.m24 + m13 * _other.m34 + m44 * _other.m44;

	return _result;

}

bool Matrix4x4::operator==(const Matrix4x4& _other)
{
	return
		m11 == _other.m11 &&
		m12 == _other.m12 &&
		m13 == _other.m13 &&
		m14 == _other.m14 &&
		m21 == _other.m21 &&
		m22 == _other.m22 &&
		m23 == _other.m23 &&
		m24 == _other.m24 &&
		m31 == _other.m31 &&
		m32 == _other.m32 &&
		m33 == _other.m33 &&
		m34 == _other.m34 &&
		m41 == _other.m41 &&
		m42 == _other.m42 &&
		m43 == _other.m43;
}

bool Matrix4x4::operator!=(const Matrix4x4& _other)
{
	return !this->operator==(_other); 
}



#pragma endregion operator