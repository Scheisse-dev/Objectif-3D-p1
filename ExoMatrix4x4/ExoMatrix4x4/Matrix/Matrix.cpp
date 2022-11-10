#include "Matrix.h"
#include "../Quaternion/Quaternion.h"

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
Matrix Matrix::CreateTranslation(Matrix& _mat, const float _xw, const float _yw, const float _zw)
{
	// modifier w 
	_mat.xw += _xw; 
	_mat.yw += _yw;
	_mat.zw += _zw;

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


