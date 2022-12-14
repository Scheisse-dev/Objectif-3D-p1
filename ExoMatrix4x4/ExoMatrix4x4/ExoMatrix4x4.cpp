#include <iostream>
#include "Matrix/Matrix.h" 
#include "Quaternion/Quaternion.h"

int main()
{
    Matrix mat = Matrix(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    Quaternion quat = Quaternion(10, 20, 30, 40);
    //std::cout << "CreateTranslation => (10, 25, 45)" + Matrix::CreateTranslation(mat, 10, 25, 45).ToString() << "\n" << "=====================" << std::endl;
    //std::cout << "CreateScale => 5.0f" + Matrix::CreateScale(mat, 5.0f, 5.0f, 5.0f).ToString() << "\n" << "=====================" << std::endl;
    //std::cout << "CreateRotationX => 25.0f" + Matrix::CreateRotationX(mat, 25.0f).ToString() << "\n" << "=====================" << std::endl;
    //std::cout << "CreateRotationY => 35.0f" + Matrix::CreateRotationY(mat, 35.0f).ToString() << "\n" << "=====================" << std::endl;
    //std::cout << "CreateRotationZ => 45.0f" + Matrix::CreateRotationZ(mat, 45.0f).ToString() << "\n" << "=====================" << std::endl;
    //std::cout << "CreateFromQuaternion=> (10,20,30,40)" + Matrix::CreatefromQuaternion(quat).ToString() << "\n" << "=====================" << std::endl;
    //std::cout << "Get Determinant" << Matrix::GetDeterminant(mat) << "\n" << "=====================" << std::endl;
    //std::cout << "Lerp => 1" + Matrix::Lerp(Matrix::CreateTranslation(mat, 10, 25, 45), Matrix::CreateScale(mat, 5.0f, 5.0f, 5.0f), 1.0f).ToString() << "\n" << "=====================" << std::endl;
    //std::cout << "Lerp => 0.5" + Matrix::Lerp(Matrix::CreateTranslation(mat, 10, 25, 45), Matrix::CreateScale(mat, 5.0f, 5.0f, 5.0f), 0.5f).ToString() << "\n" << "=====================" << std::endl;
    //std::cout << "Lerp => 0" + Matrix::Lerp(Matrix::CreateTranslation(mat, 10, 25, 45), Matrix::CreateScale(mat, 5.0f, 5.0f, 5.0f), 0.0f).ToString() << "\n" << "=====================" << std::endl;
    std::cout << "CreateOrthogaphic => (100, 80, 250, 150)" + Matrix::CreateOrthographic(100, 80, 250, 150).ToString() << "\n" << "=====================" << std::endl;
    //std::cout << "-Translation" << (-Matrix::CreateTranslation(mat, 10, 25, 45)).ToString() << "\n" << "=====================" << std::endl;
    //std::cout << "Translation * Scale" << (Matrix::CreateTranslation(mat, 10, 25, 45) * Matrix::CreateScale(mat, 5.0f, 5.0f, 5.0f)).ToString() << "\n" << "=====================" << std::endl;
    //std::cout << "Translation + Scale" << (Matrix::CreateTranslation(mat, 10, 25, 45) + Matrix::CreateScale(mat, 5.0f, 5.0f, 5.0f)).ToString() << "\n" << "=====================" << std::endl;
    //std::cout << "Translation - Scale" << (Matrix::CreateTranslation(mat, 10, 25, 45) - Matrix::CreateScale(mat, 5.0f, 5.0f, 5.0f)).ToString() << "\n" << "=====================" << std::endl;
    std::cout << mat[0];
}
