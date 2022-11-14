#include "Matrix.h"
#include "../Math/Mathf.h"
#include "../Quaternion/Quaternion.h"
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
	return std::format("\n\n[M11:{},M12:{},M13:{},M14:{}]\n\n[M21:{},M22:{},M23:{},M24:{}]\n\n[M31:{},M32:{},M33:{},M34:{}]\n\n[M41:{},M42:{},M43{},M44:{}]", xx, xy, xz, xw , yx, yy, yz, yw, zx, zy, zz , zw, wx , wy ,wz , ww);
}

Matrix Matrix::CreateTranslation(Matrix& _mat, const float _xw, const float _yw, const float _zw)
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

Matrix Matrix::CreatefromQuaternion(Quaternion& _quat)
{
	
	return Matrix(1 - (2 * ((_quat.y * _quat.y) + (_quat.z * _quat.z))), 2 * ((_quat.x * _quat.y) + (_quat.z * _quat.w)), 2 * ((_quat.x * _quat.z) - (_quat.y * _quat.w)), 0.0f,
		2 * ((_quat.x * _quat.y) - (_quat.z * _quat.w)), 1 - (2 * ((_quat.x * _quat.x) + (_quat.z * _quat.z))), 2 * ((_quat.y * _quat.z) + (_quat.x * _quat.w)), 0.0f,
		2 * ((_quat.x * _quat.z) + (_quat.y * _quat.w)), 2 * ((_quat.y * _quat.z) - (_quat.x * _quat.w)), 1 - (2 * ((_quat.x * _quat.x) + (_quat.y * _quat.y))), 0.0f,
		0.0f,											 0.0f,											 0.0f,													1.0f);


}
float Matrix::GetDeterminant(const Matrix& _mat)
{
	return _mat.xx*((_mat.yy * _mat.zz * _mat.ww) - (_mat.yy);
}

#pragma endregion methods
#pragma region operator

Matrix Matrix::operator* (Matrix& _other)
{
		xx * _other.xx, xy * _other.xy, xz * _other.xz, xw * _other.xw,
		yx * _other.yx, yy * _other.yy, yz * _other.yz, yw * _other.yw,
		zx * _other.zx, zy * _other.zy, zz * _other.zz, zw * _other.zw,
		wx * _other.wx, wy * _other.wy, wz * _other.wz, ww * _other.ww;
		return *this;
}
Matrix Matrix::operator + (Matrix& _other)
{
		xx+ _other.xx, xy+ _other.xy, xz+ _other.xz, xw+ _other.xw,
		yx+ _other.yx, yy+ _other.yy, yz+ _other.yz, yw+ _other.yw,
		zx+ _other.zx, zy+ _other.zy, zz+ _other.zz, zw+ _other.zw,
		wx+ _other.wx, wy+ _other.wy, wz+ _other.wz, ww+ _other.ww;
	return *this;
}
Matrix Matrix::operator - (Matrix & _other)
{
		xx - _other.xx, xy - _other.xy, xz - _other.xz, xw - _other.xw,
		yx - _other.yx, yy - _other.yy, yz - _other.yz, yw - _other.yw,
		zx - _other.zx, zy - _other.zy, zz - _other.zz, zw - _other.zw,
		wx - _other.wx, wy - _other.wy, wz - _other.wz, ww - _other.ww;
	return *this;
}
Matrix Matrix::operator-()
{
	return -*this;
}

#pragma endregion operator


