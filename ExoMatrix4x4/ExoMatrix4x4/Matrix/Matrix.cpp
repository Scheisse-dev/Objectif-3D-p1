#include "Matrix.h"
#include "../Math/Mathf.h"
#include "../Quaternion/Quaternion.h"
#include "../AssertMacro/AssertMacro.h"
#include <format>

#pragma region f/p
Matrix const Matrix::Identity = Matrix( 1, 0, 0, 0,
										0, 1, 0, 0,
										0, 0, 1, 0,
										0, 0, 0, 1);
#pragma endregion f/p
#pragma region constructor

Matrix::Matrix(const float _xx, const float _xy, const float _xz, const float _xw, const float _yx, const float _yy, const float _yz, const float _yw, const float _zx, const float _zy, const float _zz, const float _zw, const float _wx, const float _wy, const float _wz, const float _ww)
{
	xx = _xx, xy = _xy, xz = _xz, xw = _xw,
	yx = _yx, yy = _yy, yz = _yz, yw = _yw, 
	zx = _zx, zy = _zy, zz = _zz, zw = _zw, 
	wx = _wx, wy = _wy, wz = _wz, ww = _ww;
}

Matrix::Matrix(const Matrix& _copy)
{
	xx = _copy.xx, xy = _copy.xy, xz = _copy.xz, xw = _copy.xw,
	yx = _copy.yx, yy = _copy.yy, yz = _copy.yz, yw = _copy.yw,
	zx = _copy.zx, zy = _copy.zy, zz = _copy.zz, zw = _copy.zw,
	wx = _copy.wx, wy = _copy.wy, wz = _copy.wz, ww = _copy.ww;
}

#pragma endregion constructor
#pragma region methods
std::string Matrix::ToString()
{
	return std::format("\n\n[M11:{},M12:{},M13:{},M14:{}]\n\n[M21:{},M22:{},M23:{},M24:{}]\n\n[M31:{},M32:{},M33:{},M34:{}]\n\n[M41:{},M42:{},M43:{},M44:{}]", xx, xy, xz, xw , yx, yy, yz, yw, zx, zy, zz , zw, wx , wy ,wz , ww);
}

Matrix Matrix::CreateTranslation(const Matrix& _mat, const float _xw, const float _yw, const float _zw)
{
	
	return Matrix(_mat.xx, _mat.xy, _mat.xz, _mat.xw + _xw,
				  _mat.yx, _mat.yy, _mat.yz, _mat.yw + _yw, 
				  _mat.zx, _mat.zy, _mat.zz, _mat.zw + _zw, 
				  _mat.wx, _mat.wy, _mat.wz, _mat.ww
	);
	
}

Matrix Matrix::CreateScale(Matrix& _mat, const float _x, const float _y, const float _z)
{
	return Matrix(_mat.xx * _x, _mat.xy * _y, _mat.xz * _z, _mat.xw,
				  _mat.yx * _x, _mat.yy * _y, _mat.yz * _z, _mat.yw,
				  _mat.zx * _x, _mat.zy * _y, _mat.zz * _z, _mat.zw,
				  _mat.wx, _mat.wy, _mat.wz, _mat.ww);
}


Matrix Matrix::CreateRotationX(Matrix& _mat, const float _rad)
{
	return Matrix(_mat.xx, _mat.xy, _mat.xz, _mat.xw, 
				  _mat.yx, _mat.yy = Mathf::Cos(_rad), _mat.yz= Mathf::Sin(_rad), _mat.yw, 
				  _mat.zx, _mat.zy = -Mathf::Sin(_rad), _mat.zz = Mathf::Cos(_rad),_mat.zw, 
				  _mat.wx, _mat.wy, _mat.wz, _mat.ww);
	
}
Matrix Matrix::CreateRotationY(Matrix& _mat, const float _rad)
{
	return Matrix(_mat.xx = Mathf::Cos(_rad), _mat.xy, _mat.xz = Mathf::Sin(_rad), _mat.xw, 
				  _mat.yx, _mat.yy, _mat.yz, _mat.yw, 
				  _mat.zx = Mathf::Sin(_rad), _mat.zy, _mat.zz = Mathf::Cos(_rad), _mat.zw,
				  _mat.wx, _mat.wy, _mat.wz, _mat.ww);
}


Matrix Matrix::CreateRotationZ(Matrix& _mat, const float _rad)
{
	return Matrix(_mat.xx = Mathf::Cos(_rad), _mat.xy = Mathf::Sin(_rad), _mat.xz, _mat.xw , 
				  _mat.yx = -Mathf::Sin(_rad), _mat.yy = Mathf::Cos(_rad), _mat.yz, _mat.yw, 
				  _mat.zx, _mat.zy, _mat.zz, _mat.zw, 
				  _mat.wx, _mat.wy, _mat.wz, _mat.ww);
}

Matrix Matrix::CreateOrthographic( const float _width, const float _height, const float _favllane, const float _nearllane)
{
	return Matrix(2/ _width, 0.0f, 0.0f,0.0f,
				  0.0f, 2/_height, 0.0f, 0.0f,
				  0.0f, 0.0f, 1/(_favllane - _nearllane), 0.0f,
				  0.0f, 0.0f, -(_nearllane/(_nearllane - _favllane)), 1.0f
	);
	
}

Matrix Matrix::CreatefromQuaternion(Quaternion& _quat)
{
	
	return Matrix(1 - (2 * ((_quat.y * _quat.y) + (_quat.z * _quat.z))), 2 * ((_quat.x * _quat.y) + (_quat.z * _quat.w)), 2 * ((_quat.x * _quat.z) - (_quat.y * _quat.w)), 0.0f,
		2 * ((_quat.x * _quat.y) - (_quat.z * _quat.w)), 1 - (2 * ((_quat.x * _quat.x) + (_quat.z * _quat.z))), 2 * ((_quat.y * _quat.z) + (_quat.x * _quat.w)), 0.0f,
		2 * ((_quat.x * _quat.z) + (_quat.y * _quat.w)), 2 * ((_quat.y * _quat.z) - (_quat.x * _quat.w)), 1 - (2 * ((_quat.x * _quat.x) + (_quat.y * _quat.y))), 0.0f,
		0.0f,											 0.0f,											 0.0f,													1.0f);


}
float Matrix::GetDeterminant(const Matrix& _mat)
{
	float a = _mat.xx, b = _mat.xy, c = _mat.xz, d = _mat.xw,
		e = _mat.yx, f = _mat.yy, g = _mat.yz, h = _mat.yw,
		i = _mat.zx, j = _mat.zy, k = _mat.zz, l = _mat.zw,
		m = _mat.wx, n = _mat.wy, o = _mat.wz, p = _mat.ww;
	
	return 
		a * (f * k * p - f * l * o - g * j * p + g * l * n + h * j * o - h * k * n)
		- b * (e * k * p - e * l * o - g * i * p + g * l * m + h * i * o - h * k * m)
		+ c * (e * j * p - e * l * n - f * i * p + f * l * m + h * i * n - h * j * m)
		- d * (e * j * o - e * k * n - f * i * o + f * k * m + g * i * n + g * j * m)
		;
}
Matrix Matrix::Lerp(const Matrix& _a, const Matrix& _b, const float _t)
{
	const float _time = Mathf::Clamp01(_t);
	return Matrix(_a.xx + (_b.xx - _a.xx) * _time,
		_a.xy + (_b.xy - _a.xy) * _time,
		_a.xz + (_b.xz - _a.xz) * _time,
		_a.xw + (_b.xw - _a.xw) * _time,

		_a.yx + (_b.yx - _a.yx) * _time,
		_a.yy + (_b.yy - _a.yy) * _time,
		_a.yz + (_b.yz - _a.yz) * _time,
		_a.yw + (_b.yw - _a.yw) * _time,

		_a.zx + (_b.zx - _a.zx) * _time,
		_a.zy + (_b.zy - _a.zy) * _time,
		_a.zz + (_b.zz - _a.zz) * _time,
		_a.zw + (_b.zw - _a.zw) * _time,

		_a.wx + (_b.wx - _a.wx) * _time,
		_a.wy + (_b.wy - _a.wy) * _time,
		_a.wz + (_b.wz - _a.wz) * _time,
		_a.ww + (_b.ww - _a.ww) * _time
		);

}

#pragma endregion methods
#pragma region operator

Matrix Matrix::operator* (const Matrix& _other)
{
	return Matrix(  (xx * _other.xx) + (xy * _other.xy) + (xz * _other.xz), (xx * _other.xy) + (xy * _other.yy) + (xz * _other.zy), (xx * _other.xz) + (xy * _other.yz) + (xz * _other.zz), 0.0f,
					(yx * _other.xx) + (yy * _other.xy) + (yz * _other.xz), (yx * _other.xy) + (yy * _other.yy) + (yz * _other.zy), (xy * _other.xz) + (yy * _other.yz) + (yz * _other.zz), 0.0f,
					(zx * _other.xx) + (zy * _other.xy) + (zz * _other.xz), (zx * _other.xy) + (zy * _other.yy) + (zz * _other.zy), (zx * _other.xz) + (zy * _other.yz) + (zz * _other.zz), 0.0f,
					0.0f												  , 0.0f												  , 0.0f												  , 1.0f);
}
Matrix Matrix::operator + (const Matrix& _other)
{
		return Matrix(xx+ _other.xx, xy+ _other.xy, xz+ _other.xz, xw+ _other.xw,
		yx+ _other.yx, yy+ _other.yy, yz+ _other.yz, yw+ _other.yw,
		zx+ _other.zx, zy+ _other.zy, zz+ _other.zz, zw+ _other.zw,
		wx+ _other.wx, wy+ _other.wy, wz+ _other.wz, ww+ _other.ww)
	;
}
Matrix Matrix::operator - (const Matrix & _other)
{
		return Matrix(xx - _other.xx, xy - _other.xy, xz - _other.xz, xw - _other.xw,
		yx - _other.yx, yy - _other.yy, yz - _other.yz, yw - _other.yw,
		zx - _other.zx, zy - _other.zy, zz - _other.zz, zw - _other.zw,
		wx - _other.wx, wy - _other.wy, wz - _other.wz, ww - _other.ww);

}
Matrix Matrix::operator-()
{
	return Matrix(-xx, -xy, -xz, -xw, -yx, -yy, -yz, -yw, -zx, -zy, -zz, -zw, -wx, -wy, -wz, -ww);
}

float& Matrix::operator[](const int _index)
{
	check(_index >= 0 && _index < 15);
	switch (_index)
	{
	case 0: return xx;
	case 1: return xy;
	case 2: return xz;
	case 3: return xw;
	case 4: return yx;
	case 5: return yy;
	case 6: return yz;
	case 7: return yw;
	case 8: return zx;
	case 9: return zy;
	case 10: return zz;
	case 11: return zw;
	case 12: return wx;
	case 13: return wy; 
	case 14: return wz;
	case 15: return ww;

	}
}


#pragma endregion operator


