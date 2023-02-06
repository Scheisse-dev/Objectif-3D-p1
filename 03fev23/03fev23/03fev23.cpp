#include <iostream>
#include "Map/Map.h"

//Map 

int main()
{
    Map<int, std::string> loutre = Map<int, std::string>(1, "loutre");
    loutre.Insert(1, "oursin");

    std::cout << loutre.Count() << std::endl;
    
    std::cout << loutre.Find(1);

    
}

