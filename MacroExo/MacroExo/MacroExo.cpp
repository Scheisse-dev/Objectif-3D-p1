#include <iostream>
#include "Action.h"
#include "Object.h"


class A : public Object
{
public:
    void Test(float _a)
    {
        std::cout << _a << std::endl;
    }

};



int main()
{
    
    Action<float> onTeste = &A::Test;
    A* _a = new A();
    onTeste.Invoke(_a, 5);

    delete _a;


    return 0;
}

