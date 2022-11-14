#pragma once
#include "string"

class Quaternion;

class Matrix
{
#pragma region f/p
private:
	float xx, xy, xz, xw,
		yx, yy, yz, yw,
		zx, zy, zz, zw,
		wx, wy, wz, ww = 0;
public: 
	static const Matrix Identity; //done
#pragma endregion f/p
#pragma region constructor
public:
	Matrix(const float _xx, const float _xy, const float _xz, const float _xw, 
		   const float _yx, const float _yy, const float _yz, const float _yw, 
		   const float _zx, const float _zy, const float _zz, const float _zw, 
		   const float _wx, const float _wy, const float _wz, const float _ww);//done

	Matrix(const Matrix& _copy);
#pragma endregion constructor
#pragma region methods
public:
	std::string ToString();
	static Matrix CreateTranslation(const Matrix& _mat, const float _xw, const float _yw, const float _zw); // good
	static Matrix CreateScale(Matrix& _mat, const float _x, const float _y, const float _z); //good
	static Matrix CreateRotationX(Matrix& _mat, const float _rad); // good
	static Matrix CreateRotationY(Matrix& _mat , const float _rad); // good
	static Matrix CreateRotationZ(Matrix& _mat, const float _rad); //good
	static Matrix CreateOrthographic( const float _width, const float _height, const float _nearllane, const float _favllane);
	static Matrix CreatefromQuaternion( Quaternion& _quat); //good
	static Matrix Lerp(const Matrix& _a, const Matrix& _b,const float _t); //good
	static float GetDeterminant(const Matrix& _mat); // good 
	
#pragma endregion methods
#pragma region operator
public:
	Matrix operator*(const Matrix& _other); //good
	Matrix operator+(const Matrix& _other);//good
	Matrix operator-(const Matrix& _other);//good
	Matrix operator-(); //good
	float& operator[](const int _index); // done
#pragma endregion operator
};

