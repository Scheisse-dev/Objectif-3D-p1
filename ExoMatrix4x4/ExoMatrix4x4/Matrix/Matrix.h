#pragma once
class Matrix
{
#pragma region f/p
private:
	float xx , xy , xz , xw , 
		  yx , yy , yz , yw , 
		  zx , zy , zz , zw , 
		  wx , wy , wz , ww = 0; 
public: 
	static const Matrix Identity;
#pragma endregion f/p
#pragma region constructor
public:
	Matrix(const float _xx, const float _xy, const float _xz, const float _xw, 
		   const float _yx, const float _yy, const float _yz, const float _yw, 
		   const float _zx, const float _zy, const float _zz, const float _zw, 
		   const float _wx, const float _wy, const float _wz, const float _ww);

	Matrix(const Matrix& _copy);
#pragma endregion constructor
#pragma region methods
public:
	static Matrix CreateTranslation(const float _x, const float _y, const float _z);
	static Matrix CreateScale(const float _x, const float _y, const float _z);
	static Matrix CreateRotationX(const float _rad);
	static Matrix CreateRotationY(const float _rad);
	static Matrix CreateRotationz(const float _rad);
	static Matrix CreateOrthographic(const float _width, const float height, const float nearllane, const float favllane);
	static Matrix CreatefromQuaternion();
	static Matrix Lerp(const Matrix& _a, const Matrix& _b, const float _t);
	static Matrix GetDeterminant(const Matrix& _mat);
	
#pragma endregion methods
#pragma region operator
public:
	Matrix operator*(Matrix& _other); 
	Matrix operator+(Matrix& _other);
	Matrix operator-(Matrix& _other);
	Matrix operator-(); 
	// operator[];
#pragma endregion operator
};

