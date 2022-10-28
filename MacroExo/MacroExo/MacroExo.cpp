#include <iostream>
#include <format>
#include "Action.h"
#include "Object.h"
#include "IGame.h"


#define nameof(x) #x
#define PURE_VIRTUAL() = 0



#define null = nullptr

class A : public Object
{
public:
    void Test(float _a)
    {
        std::cout << _a << std::endl;
    }
    void HelloKitty()
    {
        std::cout << "gytfkytd" << std::endl;
    }

    virtual void Tku() PURE_VIRTUAL();
};

void Display(Object* _o)
{
    std::cout << std::format("Is Interface: {}\n", _o->IsInterface());
    std::cout << std::format("Is Class: {}\n", _o->IsClass());
    std::cout << std::format("Is Abstract: {}\n", _o->IsAbstract());
}

int main()
{

    
    Object* o;
    Display(o);

    IGame* game = new IGame();
    //Display(game);
    //game->GetParentClass()->Test();


    return 0;
    //Action<float> onTeste = &A::Test;
    //A* _a = new A();
    //onTeste.Invoke(_a, 5);

    //delete _a;


    //return 0;


}

