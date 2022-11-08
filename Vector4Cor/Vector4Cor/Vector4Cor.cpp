#include <iostream>
#include "Vector4.h"


int main()
{
    Vector4 _a = Vector4::Zero;
    Vector4 _b = Vector4::One;
    Vector4 _c = Vector4(2); 

    std::cout << Vector4::Clamp(_b, _a, _c).ToString() << std::endl;
    std::cout << Vector4::Clamp(_a, _b, _c).ToString() << std::endl;
    std::cout << Vector4::Distance(_a, _b) << std::endl;
    _c.Normalize();
    std::cout << _c.ToString() << std::endl;
    std::cout << _b.Length() << std::endl;
    std::cout << _b.LengthSquared() << std::endl;
    Vector4 _d = Vector4(5, 10, 10, 15);
    std::cout << Vector4::Dot(_b, _d) << std::endl;
    _a += Vector4(8, 24, 3, 10); 
    std::cout << Vector4::Min(_a, _d).ToString() << std::endl;
    std::cout << Vector4::Max(_a, _d).ToString() << std::endl;
    std::cout << (-_d).ToString() << std::endl;



    return 0;

}

