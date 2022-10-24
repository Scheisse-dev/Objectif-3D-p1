#include <iostream>
#include "AbstractClass.h"
#include "AbstractChild.h"
#include "IFly.h"
#include "Bird.h"
#include <vector>

//interface unique au c++
int main()
{
    std::vector<AbstractClass*> abstracts = {}; 
    AbstractChild a;

    IFly* _fly = new Bird(); 
}