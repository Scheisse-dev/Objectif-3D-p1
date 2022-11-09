#include <iostream>
#include "Quaternion/Quaternion.h"

int main()
{
    Quaternion quat = Quaternion(50, 25, 80, 125);
    Quaternion quat1 = Quaternion(80, 30, 25, 40);
    std::cout << "Normalize : " + Quaternion::Normalize(quat).ToString() << std::endl;
    std::cout << "Conjugate : " + Quaternion::Conjugate(quat).ToString() << std::endl;
    std::cout << "Inverse : " + Quaternion::Inverse(quat).ToString() << std::endl;
    std::cout << "Negate : " + Quaternion::Negate(quat).ToString() << std::endl;
    std::cout << "Lerp => 0 : " + Quaternion::Lerp(quat, quat1, 0.0f).ToString() << std::endl;
    std::cout << "Lerp => 0.5 : " + Quaternion::Lerp(quat, quat1, 0.5f).ToString() << std::endl;
    std::cout << "Lerp => 1 : " + Quaternion::Lerp(quat, quat1, 1.0f).ToString() << std::endl;
    std::cout << "Dot :" << Quaternion::Dot(quat, quat1) << std::endl;
    std::cout << "Length : " << quat.Length() << std::endl; 
    std::cout << "LengthSqrt : " << quat.LengthSquared() << std::endl;

}
